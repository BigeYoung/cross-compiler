FROM python
RUN apt-get update \
    && apt-get install openssh-client cmake build-essential -y \
    && pip3 install simple_http_server requests
COPY . .
ENTRYPOINT [ "python3", "-u", "httpserver.py" ]
