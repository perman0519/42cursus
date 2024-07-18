#!/bin/bash

# Kibana가 준비될 때까지 대기
until curl -sk https://kibana:5601/api/status | grep -q '{"status":{"overall":{"level":"available"}}}'; do
    echo "Waiting for Kibana..."
    sleep 10
done

# 대시보드 설정
curl -X POST "https://kibana:5601/api/saved_objects/_import" \
     -H 'kbn-xsrf: true' \
     -u elastic:${ELASTIC_PASSWORD} \
     -k \
     --form file=@/dashboard.ndjson

# ILM 설정
# ILM 정책 생성
curl -X PUT "https://elasticsearch:9200/_ilm/policy/nginx_log_policy"\
     -H 'Content-Type: application/json' \
     -u elastic:${ELASTIC_PASSWORD} \
     -k \
     -d'
{
  "policy": {
    "phases": {
      "hot": {
        "min_age": "0ms",
        "actions": {}
      },
      "delete": {
        "min_age": "30d",
        "actions": {
          "delete": {}
        }
      }
    }
  }
}'

# 인덱스 템플릿 생성
curl -X PUT "https://elasticsearch:9200/_index_template/nginx_log_template" \
     -H 'Content-Type: application/json' \
     -u elastic:${ELASTIC_PASSWORD} \
     -k \
     -d'
{
  "index_patterns": ["nginx-*"],
  "template": {
    "settings": {
      "index.lifecycle.name": "nginx_log_policy"
    }
  }
}'


existing_indices=$(curl -s \
                        -X GET "https://elasticsearch:9200/_cat/indices/nginx-*?h=index" \
                        -u elastic:${ELASTIC_PASSWORD} \
                        -k)

for index in $existing_indices
do
  curl -X PUT "https://elasticsearch:9200/${index}/_settings" \
       -H 'Content-Type: application/json' \
       -u elastic:${ELASTIC_PASSWORD} \
       -k \
       -d'
  {
    "index.lifecycle.name": "nginx_log_policy"
  }'

  echo "Applied ILM policy to ${index}"
done


echo "Nginx log retention policy has been set up."

echo "Dashboard setup complete."
