FROM alpine:3.19

RUN apk upgrade --no-cache && \
	apk add --no-cache openssl nginx curl && \
	adduser -u 1000 -D -h /var/www tmp && chown -R tmp:tmp /var/www

RUN openssl	req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx_pem.pem \
	-out /etc/ssl/certs/nginx_cer.crt \
	-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=./CN=junhylee.42.fr/emailAddress=junhylee@student.42seoul.kr"

COPY --chmod=644 conf/nginx.conf /etc/nginx/nginx.conf

ENTRYPOINT ["nginx", "-g", "daemon off;"]

STOPSIGNAL SIGQUIT