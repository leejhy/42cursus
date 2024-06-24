#!/bin/sh
set -e

chmod +x /usr/local/bin/wp
chown tmp:tmp /usr/local/bin/wp
umask 0002
su tmp

echo "start wordpress.sh "
if [ ! -e  wp-config-sample.php ]; then
    su tmp -c "wp core download --path=/var/www --locale=ko_KR"
fi

su tmp -c "wp config create --force --skip-check --dbhost=mariadb --dbcharset="utf8" --dbuser=$MARIADB_USER_ID --dbpass=$MARIADB_USER_PASSWORD --dbname=$MARIADB_DATABASE"

if ! su tmp -c "wp core is-installed"; then
    su tmp -c "wp core install --locale=en_US --url=${DOMAIN} --title=Inception --admin_user=${WP_ADMIN_ID} --admin_email=${WP_ADMIN_EMAIL} --admin_password=${WP_ADMIN_PASSWORD}"
    su tmp -c "wp user create ${WP_USER_ID} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASSWORD}"
fi

su tmp -c "wp core update-db"
su tmp -c "wp plugin update --all"

exec "$@"








