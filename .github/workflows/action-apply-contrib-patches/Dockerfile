FROM debian:9.5-slim

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y git

LABEL "repository"="https://github.com/CuBoulder/express_mono"

ADD entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
