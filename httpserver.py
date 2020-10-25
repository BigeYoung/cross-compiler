import requests
import MySQLdb
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
db = MySQLdb.connect("mysql", "cpps", "cpps", "cpps_db", charset='utf8')

def opcua_server():

"""
产品响应器启动线程：生成OPC UA程序
    - 成功：`product.status`标记为：`processing`
    - 失败：把托盘标记为空闲，把数据库清除，`product.status`标记为：`error`，把错误原因写入数据库。
"""
   # 替换cpp文件里的字符串
   with open('cpp_template/myUAModel.cpp') as infile, open('output/myUAModel.cpp', 'w') as outfile:
        for line in infile:
            for src, target in req.json.items():
                line = line.replace(src, target)
            outfile.write(line)
    # 编译cpp文件
    p = Popen("./build.sh", shell=True)
    p.wait()
    # 下载到服务器里
    p = Popen('./download.sh %s' % (str(ip),), shell=True)
    p.wait()


@request_map("/product_reactor", method=["PUT"])
def product_reactor(req=Request()):

"""
产品响应器请求空托盘
    - 成功：将托盘IP、ID写入数据库，Consul将对应托盘标记为忙碌。
    - 失败：`product.status`标记为：`error`，并把错误原因写入数据库。
"""
   product_guid = req.json["product_guid"]
    # 查询空托盘
    r = requests.get('http://192.168.137.121:8500/v1/catalog/services?dc=dc1')
    services = r.json().items()
    for s_id, s_tags in services:
        if "Product" not in s_tags:
            continue
        r = requests.get(
            'http://192.168.137.121:8500/v1/catalog/service/'+s_id+'?dc=dc1')
        if "Type" in r.json()[0]["ServiceMeta"].keys():
            if r.json()[0]["ServiceMeta"]["Type"] =="Product":
                if not r.json()[0]["ServiceMeta"]["ProductID"]:
                    ip = r.json()[0]["TaggedAddresses"]["wan"]
                    # -成功 找到空托盘
                    # 将托盘IP、ID写入数据库
                    cursor = db.cursor()
                    sql = "UPDATE `product` SET `pallet_guid`='%s', `pallet_ip_port`='opc.tcp://%s:4844' WHERE `guid`='%s'"
                    val = (s_id, ip, product_guid)
                    cursor.execute(sql)
                    db.commit()
                    print("更新产品与匹配的托盘：", cursor.rowcount, "条记录被改变。")
                    # TODO Consul将对应托盘标记为忙碌
                    r = requests.put(
                        'http://192.168.137.121:8500/v1/agent/service/maintenance/'+s_id+'?enable=true&reason=product_processing')
                    return ip

    # 失败：`product.status`标记为：`error`，并把错误原因写入数据库。
    cursor = db.cursor()
    sql = "UPDATE `product` SET `status`='error', `message`='没有可用的空托盘了。' WHERE `guid`='%s'"
    val = (product_guid)
    cursor.execute(sql)
    db.commit()
    print("没有可用的空托盘了：", cursor.rowcount, "条记录被改变。")
    raise HttpError(500, "没有可用的空托盘了。")

server.start()

# 关闭数据库连接
db.close()
