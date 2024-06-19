#!/bin/sh

if [ ! -d "/var/lib/mysql/mysql" ]; then
	echo "[INFO] Create '/run/mysqld' directory."
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
	mariadb-install-db --user=$MYSQL_USER --datadir=/var/lib/mysql --basedir=/usr --rpm

	cat << EOF > /bootstrap_commands

USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE user='';

GRANT ALL ON *.* TO 'root'@'%' identified by '$MYSQL_ROOT_PW' WITH GRANT OPTION ;
SET PASSWORD FOR 'root'@'%'=PASSWORD('$MYSQL_ROOT_PW') ;
FLUSH PRIVILEGES ;

CREATE DATABASE IF NOT EXISTS $WP_DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci ;
CREATE USER '$WP_DB_USER'@'%' IDENTIFIED BY '$WP_DB_PW';
GRANT ALL PRIVILEGES ON *.* TO '$WP_DB_USER'@'%';
FLUSH PRIVILEGES ;

EOF

	mysqld --bootstrap --user=$MYSQL_USER < /bootstrap_commands
	rm -rf /bootstrap_commands
else
	echo "[INFO] Directory already present, skipping creation"
	chown -R mysql:mysql /var/lib/mysql
fi

cp /tmp/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

mysqld_safe --user=$MYSQL_USER
