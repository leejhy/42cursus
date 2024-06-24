FROM alpine:3.19

RUN	apk upgrade --no-cache && apk add --no-cache mariadb mariadb-client && \
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql

COPY --chmod=644 conf/my.cnf /etc/my.cnf
COPY --chmod=644 conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY --chmod=755 tools/mariadb.sh /

ENTRYPOINT ["/mariadb.sh"]

CMD ["mariadbd-safe"]

STOPSIGNAL SIGQUIT