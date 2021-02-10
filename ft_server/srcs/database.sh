systemctl start mariadb

CREATE DATABASE wordpress_db;
CREATE USER 'wordpress_user'@'localhost';
SET password FOR 'wordpress_user'@'localhost' = password('lemotdepasse');
GRANT ALL PRIVILEGES ON wordpress_db.* to wordpress_user@'localhost';
FLUSH PRIVILEGES;