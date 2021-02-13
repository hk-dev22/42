# Config ssl
mkdir /etc/nginx/ssl
chmod 700 /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx-selfsigned.key -out /etc/nginx/ssl/nginx-selfsigned.crt -subj "/C=FR/ST=Paris/L=Franconville/O=42/OU=hkortbi/CN=localhost"

# Config mysql
service mysql start
echo "create database wordpress default character set utf8 collate utf8_unicode_ci;" | mysql -u root
echo "create user 'couscous'@'localhost' identified by 'merguez22';" | mysql -u root
echo "grant all privileges on wordpress.* TO 'couscous'@'localhost'" | mysql -u root
echo "flush privileges;" | mysql -u root

# Config phpmyadmin new user
service php7.3-fpm start
echo "grant all on *.* to 'hkortbi'@'localhost' IDENTIFIED BY 'lemotdepasse'" | mysql -u root
echo "flush privileges;" | mysql -u root

# Launch
service nginx start
nginx -t
service nginx restart
service mysql restart
service php7.3-fpm restart
sleep infinity