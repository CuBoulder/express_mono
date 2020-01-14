FROM debian:9.5-slim

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y git && \
    apt-get install -y curl

LABEL "com.github.actions.name"="Update express_mono upstream"
LABEL "com.github.actions.description"="Update express_mono in Pantheon Upstream"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="https://github.com/CuBoulder/express_mono"
LABEL "maintainer"="OSR Web Deploy <osr_web_deploy@colorado.edu"

ADD entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
