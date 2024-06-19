#!/bin/sh

if [ -f "/var/www/html/wp-config.php" ]; then
	echo "already installed."
else
	cd /var/www/html/

	wp core download
	wp config create --dbname=$WP_DB_NAME --dbuser=$WP_DB_USER --dbpass=$WP_DB_PW --dbhost=$MYSQL_HOST
	wp core install --url=$DOMAIN --title="Junssong's INCEPTION" --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL
	wp user create $WP_USER_NAME $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW
	wp theme install zakra --activate
	chown -R nginx:nginx /var/www/html
fi

php-fpm82 -F
