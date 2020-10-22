import requests
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

@request_map("/uaserver", method=["PUT"])
def uaserver(req=Request()):
    with open('cpp_template/'+req.json["PRODUCT_NAME"]+'/myUAModel.cpp') as infile, open('output/myUAModel.cpp', 'w') as outfile:
        for line in infile:
            for src, target in req.json.items():
                line = line.replace(src, target)
            outfile.write(line)
    p = Popen("./build.sh", shell=True)
    p.wait()
    r = requests.get('http://192.168.137.121:8500/v1/catalog/services?dc=dc1')
    services = r.json().keys()
    for s in services:
        r = requests.get(
            'http://192.168.137.121:8500/v1/catalog/service/'+s+'?dc=dc1')
        if "Type" in r.json()[0]["ServiceMeta"].keys():
            if r.json()[0]["ServiceMeta"]["Type"]=="Product":
                if not r.json()[0]["ServiceMeta"]["ProductID"]:
                    ip = r.json()[0]["TaggedAddresses"]["wan"]
                    p = Popen('./download.sh %s' % (str(ip),), shell=True)
                    p.wait()
    return "done."


server.start()
