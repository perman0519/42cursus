#!/bin/bash

# Kibana 가용성 확인
until curl -s http://localhost:5601/api/status | grep -q '{"status":{"overall":{"level":"available"}}}'; do
    echo "$(date '+%Y-%m-%d %H:%M:%S') Waiting for Kibana..."
    sleep 10
done

echo "Kibana is up. Importing saved objects..."

# 인덱스 패턴 생성
create_index_pattern() {
    local pattern=$1
    local response=$(curl -X POST "localhost:5601/api/index_patterns/index_pattern?overwrite=true" \
        -H "kbn-xsrf: true" \
        -H "Content-Type: application/json" \
        -d "{\"index_pattern\": {\"title\": \"$pattern\", \"timeFieldName\": \"@timestamp\"}}")
    echo $response
}

create_index_pattern "nginx-*"
create_index_pattern "django-*"

get_index_pattern_id() {
    local pattern=$1
    local response=$(curl -s -X GET "localhost:5601/api/saved_objects/_find?type=index-pattern&search_fields=title&search=$pattern" \
        -H "kbn-xsrf: true")
    echo $response | grep -o '"id":"[^"]*' | cut -d'"' -f4
}

# 시각화 생성
create_visualization() {
    local id=$1
    local title=$2
    local index_pattern=$3
    local response=$(curl -X POST "localhost:5601/api/saved_objects/visualization/$id?overwrite=true" \
        -H "kbn-xsrf: true" \
        -H "Content-Type: application/json" \
        -d "{
            \"attributes\": {
                \"title\": \"$title\",
                \"visState\": \"{\\\"type\\\":\\\"histogram\\\",\\\"params\\\":{\\\"type\\\":\\\"histogram\\\",\\\"grid\\\":{\\\"categoryLines\\\":false},\\\"categoryAxes\\\":[{\\\"id\\\":\\\"CategoryAxis-1\\\",\\\"type\\\":\\\"category\\\",\\\"position\\\":\\\"bottom\\\",\\\"show\\\":true,\\\"style\\\":{},\\\"scale\\\":{\\\"type\\\":\\\"linear\\\"},\\\"labels\\\":{\\\"show\\\":true,\\\"truncate\\\":100},\\\"title\\\":{}}],\\\"valueAxes\\\":[{\\\"id\\\":\\\"ValueAxis-1\\\",\\\"name\\\":\\\"LeftAxis-1\\\",\\\"type\\\":\\\"value\\\",\\\"position\\\":\\\"left\\\",\\\"show\\\":true,\\\"style\\\":{},\\\"scale\\\":{\\\"type\\\":\\\"linear\\\",\\\"mode\\\":\\\"normal\\\"},\\\"labels\\\":{\\\"show\\\":true,\\\"rotate\\\":0,\\\"filter\\\":false,\\\"truncate\\\":100},\\\"title\\\":{\\\"text\\\":\\\"Count\\\"}}],\\\"seriesParams\\\":[{\\\"show\\\":true,\\\"type\\\":\\\"histogram\\\",\\\"mode\\\":\\\"stacked\\\",\\\"data\\\":{\\\"label\\\":\\\"Count\\\",\\\"id\\\":\\\"1\\\"},\\\"valueAxis\\\":\\\"ValueAxis-1\\\",\\\"drawLinesBetweenPoints\\\":true,\\\"lineWidth\\\":2,\\\"showCircles\\\":true}],\\\"addTooltip\\\":true,\\\"addLegend\\\":true,\\\"legendPosition\\\":\\\"right\\\",\\\"times\\\":[],\\\"addTimeMarker\\\":false,\\\"labels\\\":{\\\"show\\\":false},\\\"thresholdLine\\\":{\\\"show\\\":false,\\\"value\\\":10,\\\"width\\\":1,\\\"style\\\":\\\"full\\\",\\\"color\\\":\\\"#E7664C\\\"}},\\\"aggs\\\":[{\\\"id\\\":\\\"1\\\",\\\"enabled\\\":true,\\\"type\\\":\\\"count\\\",\\\"schema\\\":\\\"metric\\\",\\\"params\\\":{}},{\\\"id\\\":\\\"2\\\",\\\"enabled\\\":true,\\\"type\\\":\\\"date_histogram\\\",\\\"schema\\\":\\\"segment\\\",\\\"params\\\":{\\\"field\\\":\\\"@timestamp\\\",\\\"timeRange\\\":{\\\"from\\\":\\\"now-15m\\\",\\\"to\\\":\\\"now\\\"},\\\"useNormalizedEsInterval\\\":true,\\\"scaleMetricValues\\\":false,\\\"interval\\\":\\\"auto\\\",\\\"drop_partials\\\":false,\\\"min_doc_count\\\":1,\\\"extended_bounds\\\":{}}}]}\",
                \"uiStateJSON\": \"{}\",
                \"description\": \"\",
                \"version\": 1,
                \"kibanaSavedObjectMeta\": {
                    \"searchSourceJSON\": \"{\\\"query\\\":{\\\"query\\\":\\\"\\\",\\\"language\\\":\\\"kuery\\\"},\\\"filter\\\":[],\\\"indexRefName\\\":\\\"kibanaSavedObjectMeta.searchSourceJSON.index\\\"}\"
                }
            },
            \"references\": [
                {
                    \"name\": \"kibanaSavedObjectMeta.searchSourceJSON.index\",
                    \"type\": \"index-pattern\",
                    \"id\": \"$index_pattern\"
                }
            ]
        }")
    echo $response
}

nginx_pattern_id=$(get_index_pattern_id "nginx-*")
django_pattern_id=$(get_index_pattern_id "django-*")

echo "get get get get $nginx_pattern_id"

create_visualization "nginx-logs-chart" "Nginx Logs" "$nginx_pattern_id"
create_visualization "django-logs-chart" "Django Logs" "$django_pattern_id"

create_dashboard() {
    local title=$1
    local response=$(curl -X POST "localhost:5601/api/saved_objects/dashboard?overwrite=true" \
        -H "kbn-xsrf: true" \
        -H "Content-Type: application/json" \
        -d "{
            \"attributes\": {
                \"title\": \"$title\",
                \"hits\": 0,
                \"description\": \"\",
                \"panelsJSON\": \"[{\\\"embeddableConfig\\\":{},\\\"gridData\\\":{\\\"h\\\":15,\\\"i\\\":\\\"1\\\",\\\"w\\\":24,\\\"x\\\":0,\\\"y\\\":0},\\\"panelIndex\\\":\\\"1\\\",\\\"version\\\":\\\"7.6.0\\\",\\\"panelRefName\\\":\\\"panel_0\\\"},{\\\"embeddableConfig\\\":{},\\\"gridData\\\":{\\\"h\\\":15,\\\"i\\\":\\\"2\\\",\\\"w\\\":24,\\\"x\\\":24,\\\"y\\\":0},\\\"panelIndex\\\":\\\"2\\\",\\\"version\\\":\\\"7.6.0\\\",\\\"panelRefName\\\":\\\"panel_1\\\"}]\",
                \"optionsJSON\": \"{\\\"hidePanelTitles\\\":false,\\\"useMargins\\\":true}\",
                \"version\": 1,
                \"timeRestore\": false,
                \"kibanaSavedObjectMeta\": {
                    \"searchSourceJSON\": \"{\\\"query\\\":{\\\"language\\\":\\\"kuery\\\",\\\"query\\\":\\\"\\\"},\\\"filter\\\":[]}\"}
            },
            \"references\": [
                {
                    \"name\": \"panel_0\",
                    \"type\": \"visualization\",
                    \"id\": \"nginx-logs-chart\"
                },
                {
                    \"name\": \"panel_1\",
                    \"type\": \"visualization\",
                    \"id\": \"django-logs-chart\"
                }
            ]
        }")
    echo $response
}
create_dashboard "Logs Dashboard"

echo "Setup completed."

# 컨테이너 실행 유지
tail -f /dev/null
