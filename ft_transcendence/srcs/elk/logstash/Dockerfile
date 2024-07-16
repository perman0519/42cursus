FROM docker.elastic.co/logstash/logstash:8.14.2

# Copy the custom entrypoint script
COPY logstash-entrypoint.sh /usr/share/logstash/logstash-entrypoint.sh

# Set execute permissions
# RUN chmod +x /usr/share/logstash/logstash-entrypoint.sh

# Use the custom entrypoint script
ENTRYPOINT ["/usr/share/logstash/logstash-entrypoint.sh"]
