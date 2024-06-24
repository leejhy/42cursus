#!/bin/sh

# mariadb 초기 설정 스크립트
# 

# 이 옵션은 스크립트 실행 중에 어떤 명령이라도 실패하면 즉시 스크립트를 종료하도록 설정합니다.
set -e

mariadbd    --user=mysql            \
            --datadir=/var/lib/mysql\
            --bootstrap << EOF
    FLUSH PRIVILEGES;
    CREATE USER IF NOT EXISTS root@localhost IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
    SET PASSWORD FOR root@localhost = PASSWORD('$MARIADB_ROOT_PASSWORD');
    GRANT ALL ON *.* TO root@localhost WITH GRANT OPTION;
    CREATE USER IF NOT EXISTS root@'%' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
    SET PASSWORD FOR root@'%' = PASSWORD('$MARIADB_ROOT_PASSWORD');
    GRANT ALL ON *.* TO root@'%' WITH GRANT OPTION;
    CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;
    CREATE USER IF NOT EXISTS $MARIADB_USER_ID@'%' IDENTIFIED BY '$MARIADB_USER_PASSWORD';
    SET PASSWORD FOR $MARIADB_USER_ID@'%' = PASSWORD('$MARIADB_USER_PASSWORD');
    GRANT ALL ON $MARIADB_DATABASE.* TO $MARIADB_USER_ID@'%' WITH GRANT OPTION;
    FLUSH PRIVILEGES;
EOF

exec "$@"