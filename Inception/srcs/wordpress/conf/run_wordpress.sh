#!/bin/sh

# if [ ! -d "/var/www/html/wordpress" ]; then
# 	echo "hello"
# 	echo "Directory "/var/www/html/wordpress" doesn't exist"
# 	echo "Create "/var/www/html/wordpress" directory"
# 	wget https://wordpress.org/latest.tar.gz
# 	tar -xzf latest.tar.gz
# 	rm latest.tar.gz
# 	if [ ! -d "wordpress" ]; then
# 		echo "WordPress directory not found"; exit 1;
# 	fi

# 	# Move WordPress to the desired location
# 	mkdir -p /var/www/html
# 	mv wordpress /var/www/html/wordpress

# 	echo "listen = 9000" >> /etc/php81/php-fpm.d/www.conf
# else
# 	echo "Directory "/var/www/html/wordpress" already exist"
# fi

# wp-cli



if [ -f "/var/www/html/wp-config.php" ]; then
	echo "already installed."
else
	# mkdir -p /var/www/html/
	# mkdir -p $WP_DIR
	cd /var/www/html/
	wp core download --allow-root

	wp config create --dbname=$WP_DB_NAME --dbuser=$WP_DB_USER --dbpass=$WP_DB_PW --dbhost=$MYSQL_HOST --allow-root

	wp core install --url=$DOMAIN --title="Junssong's INCEPTION" --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL --allow-root

	wp theme install hestia --activate --allow-root

	# 유저 생성
	wp user create $WP_USER_NAME $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW --allow-root
fi
chown -R nginx:nginx /var/www/html
php-fpm81 -F
