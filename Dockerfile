FROM python
RUN apt-get update \
    && apt-get install openssh-client cmake build-essential python3-mysqldb -y \
    && pip3 install simple_http_server requests mysqlclient
COPY . .
ENTRYPOINT [ "python3", "-u", "httpserver.py" ]
