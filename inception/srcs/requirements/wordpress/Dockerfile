FROM alpine:3.19

ENV SERVICE_USER=tmp

RUN apk upgrade --no-cache &&             \
    apk add --no-cache  curl php82 php82-curl php82-phar php82-fpm php82-mysqli \
                        mariadb-client php82-iconv php82-tokenizer fcgi && \
    adduser -u 1000 -D -h /var/www tmp && chown -R tmp:tmp /var/www

WORKDIR /var/www

ADD --chmod=755 https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar /usr/local/bin/wp

COPY --chown=tmp:tmp --chmod=644 conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY --chown=tmp:tmp --chmod=755 tools/wordpress.sh /

ENTRYPOINT ["/wordpress.sh"]
#고정실행

CMD ["php-fpm82", "-F"]
#docker run 명령어를 칠때 변경가능
#ENTRYPOINT는 컨테이너가 최초에 꼭 실행해야만 하는 명령어가 있을 때, CMD는 컨테이너 실행 시 시작되는 명령어지만 변경할 수 있을 때 활용하시면 됩니다.
STOPSIGNAL SIGQUIT
