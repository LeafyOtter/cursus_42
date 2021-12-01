if [ $AUTO_INDEX = "off" ]
then
	sed -i "s/autoindex on/autoindex off/g" /etc/nginx/sites-enabled/default
fi

service mysql start
service php7.3-fpm start
mysql -u root --skip-password < /root/init-db.sql
mysql -u wordpress_user -ppassword wordpress < /root/wordpress.sql
nginx -g 'daemon off;'
