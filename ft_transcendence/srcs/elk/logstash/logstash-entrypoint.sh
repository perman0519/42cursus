#!/bin/bash

# Wait for the password setup to be completed
while [ ! -f /usr/share/logstash/config/certs/passwordclear.txt ]; do
  echo "Waiting for password setup to complete..."
  sleep 5
done

# ./jdk/bin/keytool -import -alias elasticsearch -keystore "/usr/share/logstash/jdk/lib/security/cacerts" -storepass changeit -file "/usr/share/logstash/config/certs/elasticsearch_cert.pem" << eof
# yes
# eof

# ./bin/logstash-keystore add ELASTIC_PASSWORD
# Start Logstash
/usr/local/bin/docker-entrypoint
