FROM debian:buster
MAINTAINER Hicham Kortbi (hk.dev22@gmail.com)

# Autoindex
ENV AUTOINDEX on

# Install packages 
RUN apt-get update
RUN apt-get install -y wget
RUN apt-get install -y nginx
RUN apt-get install -y openssl
RUN apt-get install -y mariadb-server mariadb-client
RUN apt-get install -y php7.3 php7.3-fpm php7.3-mysql php7.3-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline php7.3-curl php7.3-gd php7.3-intl php7.3-mbstring php7.3-soap php7.3-xml php7.3-xmlrpc php7.3-zip

# Add sources files
ADD srcs/default ./
ADD srcs/wp-config.php ./
ADD srcs/install.sh ./

# Config nginx
RUN if [ "$AUTOINDEX" = "off"]; then mv ./default_off etc/nginx/sites-enabled; else mv ./default etc/nginx/sites-enabled; fi
RUN chown -R www-data /var/www/* && chmod -R 755 /var/www/*

# Wordpress - Download and install
RUN mkdir -p /var/www/localhost/wordpress
RUN wget https://wordpress.org/latest.tar.gz && tar -xzf latest.tar.gz && mv wordpress/* /var/www/localhost/wordpress/ && \
    rm -rf latest.tar.gz wordpress/ && mv wp-config.php /var/www/localhost/wordpress

# phpMyAdmin
RUN mkdir /var/www/localhost/phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz && tar -xzf phpMyAdmin-5.0.4-all-languages.tar.gz && \
    mv phpMyAdmin-5.0.4-all-languages/* var/www/localhost/phpmyadmin && rm -rf phpMyAdmin-5.0.4-all-languages.tar.gz phpMyAdmin-5.0.4-all-languages 

CMD ["bash",  "./install.sh"]

EXPOSE 80

EXPOSE 443