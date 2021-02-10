From debian:latest
MAINTAINER Hicham Kortbi (hk.dev22@gmail.com)

# Install nginx, php, mariadb and utilities (wget,...)
RUN apt-get update
RUN apt-get install -y nginx mariadb-server mariadb-client php-fpm php-mysql wget

# Configure nginx
COPY ./srcs/default ./etc/nginx/sites-available/default

# Download wordpress
RUN wget -O /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz

# Unzip wordpress (this create directory wordpress which cntaines site files)
RUN tar -xzvf /tmp/wordpress.tar.gz -C /var/www/html

# Change the ownership of the site directory
RUN chown -R www-data.www-data /var/www/html/*

# Create a database for wordpress
COPY ./srcs/database.sh ./tmp/
RUN chmod 755 ./tmp/database.sh
CMD ./tmp/database.sh

CMD service nginx start
CMD ["echo","Image created"]
