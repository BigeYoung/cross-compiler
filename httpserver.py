import requests
import MySQLdb
import _thread
from subprocess import Popen
from simple_http_server import request_map
from simple_http_server import Response
from simple_http_server import Request
from simple_http_server import Header
from simple_http_server import JSONBody
from simple_http_server import HttpError
from simple_http_server import Headers
from simple_http_server import Redirect
from simple_http_server import server

# 打开数据库
db = MySQLdb.connect(host="mariadb", user="cpps",
                     password="cpps", database="cpps_db", charset='utf8')
cursor = db.cursor()

def opcua_server(req_items, ip):
    '''产品响应器启动线程：生成OPC UA程序
        - 成功：`products.status`标记为：`processing`
        - TODO 失败：把托盘标记为空闲，把数据库清除，`products.status`标记为：`error`，把错误原因写入数据库。
    '''
    # 替换cpp文件里的字符串
    with open('cpp_template/myUAModel.cpp') as infile, open('output/myUAModel.cpp', 'w') as outfile:
        for line in infile:
            for src, target in req_items:
                line = line.replace(src, str(target))
            outfile.write(line)
    # 编译cpp文件，下载到树莓派里
    p = Popen('./build.sh %s' % (ip,), shell=True)
    p.wait()

@request_map("/product_reactor", method=["PUT"])
def product_reactor(req=Request()):
    '''产品响应器请求空托盘
        - 成功：将托盘IP、ID写入数据库，Consul将对应托盘标记为忙碌，启动“生成OPC UA程序”线程。
        - 失败：`products.status`标记为：`error`，并把错误原因写入数据库。
    '''
    product_guid = req.json["__PRODUCT_GUID__"]
    # 查询空托盘
    r = requests.get('http://192.168.137.121:8500/v1/catalog/services?dc=dc1')
    services = r.json().items()
    for s_id, s_tags in services:
        if "Product" not in s_tags or "empty" not in s_tags:
            continue
        s = requests.get(
            'http://192.168.137.121:8500/v1/catalog/service/'+s_id+'?dc=dc1')

        status = requests.get("http://192.168.137.121:8500/v1/health/node/"+s.json()[0]["Node"]).json()[0]["Status"]
        if status != "passing":
            continue

        ip = s.json()[0]["TaggedAddresses"]["wan"]
        # -成功 找到空托盘

        # Consul将对应托盘标记为忙碌
        p = Popen('./update_status.sh %s %s' % (ip, product_guid,), shell=True)

        # 将托盘IP、ID写入数据库
        ip_port = 'opc.tcp://'+ip+':4844'
        sql = "UPDATE `products` SET `pallet_guid`=%s, `pallet_ip_port`=%s WHERE `guid`=%s"
        val = (s_id, ip_port, product_guid)
        # 执行sql语句
        cursor.execute(sql, val)
        # 提交到数据库执行
        db.commit()
        print("更新产品与匹配的托盘：", cursor.rowcount, "条记录被改变。")

        # 等待Consul将对应托盘标记为忙碌完成
        p.wait()

        # 启动“生成OPC UA程序”线程。
        _thread.start_new_thread(
            opcua_server, (req.json.items(), ip,))
        return ip

    # 失败：`product.status`标记为：`error`，并把错误原因写入数据库。
    sql = "UPDATE `products` SET `status`='error', `message`='No empty pallet available.' WHERE `guid`=%s"
    val = (product_guid, )
    cursor.execute(sql, val)
    db.commit()
    raise HttpError(500, "没有可用的空托盘了。")


server.start()

# 关闭数据库连接
db.close()
