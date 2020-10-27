FROM python
RUN apt-get update \
    && apt-get install openssh-client cmake build-essential python3-mysqldb -y \
    && pip3 install simple_http_server requests mysqlclient
COPY . .
RUN chown root:root ssh/id_rsa && chmod 600 ssh/id_rsa
ENTRYPOINT [ "python3", "-u", "httpserver.py" ]
