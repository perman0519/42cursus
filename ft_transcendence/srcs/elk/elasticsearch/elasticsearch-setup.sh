set -e

# Elasticsearch 시작
/usr/local/bin/docker-entrypoint.sh elasticsearch &

# Elasticsearch가 충분히 시작될 때까지 대기
sleep 40

# echo "Elasticsearch is up. Starting password setup."

# # Password setup
# elasticsearch-reset-password -u elastic -i -b << eof
# ${ELASTIC_PASSWORD}
# ${ELASTIC_PASSWORD}
# eof

# elasticsearch-reset-password -u kibana_system -i -b << eof
# ${KIBANA_SYSTEM_PASSWORD}
# ${KIBANA_SYSTEM_PASSWORD}
# eof

# elasticsearch-reset-password -u logstash_system -i -b << eof
# ${KIBANA_SYSTEM_PASSWORD}
# ${KIBANA_SYSTEM_PASSWORD}
# eof

touch /usr/share/elasticsearch/config/certs/passwordclear.txt

tail -f /dev/null
