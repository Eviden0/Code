FROM dasctfbase/web_php73_apache


COPY ./files /tmp/
RUN cp -rf /tmp/html/ /var/www/ && \
    mkdir "/var/www/html/upload" && \
    chown -R root:root /var/www/html && \
    chmod -R 755 /var/www/html && \
    chown -R www-data:www-data /var/www/html/upload
RUN mv /var/www/html/flag.sh / && \
    chmod +x /flag.sh
