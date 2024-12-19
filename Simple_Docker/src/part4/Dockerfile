FROM nginx

WORKDIR /server/

COPY server.c /server/

COPY ./nginx/nginx.conf /etc/nginx.conf

RUN apt update && \
    apt-get install -y libfcgi-dev && \
    apt-get install -y spawn-fcgi && \
    apt-get install -y gcc && \
    useradd Bob; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /usr/bin/chfn; \
    chmod g-s /usr/bin/expiry; \
    chmod u-s /usr/bin/passwd; \
    chmod g-s /sbin/unix_chkpwd; \
    chmod g-s /usr/bin/chage; \
    chmod g-s /usr/bin/wall; \
    chmod u-s /bin/umount; \
    chmod u-s /bin/mount; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /bin/su; \
    chmod u-s /usr/bin/chsh; \
  rm -rf /var/lib/apt/lists
  
USER Bob
  
  
HEALTHCHECK --	interval=5m --timeout=3s \
  CMD curl -f http://localhost/ || exit 1
  
  
ENTRYPOINT gcc server.c -lfcgi -o server && \
        spawn-fcgi -p 8080 ./server && \
             nginx -g 'daemon off;'
             
