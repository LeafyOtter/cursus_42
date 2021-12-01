#
#	Dockerfile
#	by wind
#	<loutre@courrier.dev>
#	02/07/02 23:08:56
#	04/07/21 15:03:33
#

FROM debian:buster

LABEL maintainer="loutre@courrier.dev"

RUN apt-get update && \
	apt-get install -y git mariadb-server nginx \
	wget php-cli php-fpm php-curl php-gd php-intl \
	php-json php-mbstring php-xml php-zip php-common \
	php-xmlrpc php-soap php-mysql

WORKDIR /tmp

#	Installing PhpMyAdmin

RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz && \
	mkdir /usr/share/phpMyAdmin && \
	tar xvf phpMyAdmin-latest-all-languages.tar.gz --strip-components=1 -C /usr/share/phpMyAdmin && \
	rm -rf phpMyAdmin-latest-all-languages.tar.gz && \
	ln -s /usr/share/phpMyAdmin /var/www/html/phpmyadmin

#	Installing WordPress

RUN wget https://wordpress.org/latest.tar.gz && \
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -O wp && \
	chmod 755 wp && \
	mv wp /usr/bin/ && \
	tar xvf latest.tar.gz && \
	cp -a wordpress/. /var/www/html && \
	rm -rf latest.tar.gz wordpress

RUN	chown -R www-data:www-data /var/www/html/

ADD --chown=www-data:www-data srcs/wordpress.sql /root/wordpress.sql

ADD --chown=www-data:www-data srcs/default_nginx /etc/nginx/sites-enabled/default

ADD --chown=www-data:www-data srcs/config.inc.php /usr/share/phpMyAdmin/config.inc.php

ADD --chown=www-data:www-data srcs/localhost.cert /etc/nginx/certs/localhost.cert

ADD --chown=www-data:www-data srcs/localhost.key /etc/nginx/certs/localhost.key

ADD --chown=www-data:www-data srcs/wp-config.php /var/www/html/wp-config.php

WORKDIR /

COPY srcs/init* /root/

ENV AUTO_INDEX="on"

ENTRYPOINT ["sh", "/root/init.sh"]
