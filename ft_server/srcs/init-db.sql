CREATE DATABASE wordpress;
GRANT ALL ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'password';
update mysql.user set plugin='mysql_native_password' where user='root';
FLUSH PRIVILEGES;
