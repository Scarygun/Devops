#!/usr/bin/env bash


export DOCKER_CONTENT_TRUST=1

sudo docker build . -t server:v2

printf "Dockle judges the server:v2 image.\n"
dockle -ak NGINX_GPGKEY -ak NGINX_GPGKEY_PATH server:v2
printf "Status code = %d.\n" "$?"

export DOCKER_CONTENT_TRUST=0

sudo docker run --rm -it -d -p 80:81 --name server2 server:v2

printf "The sever is up. Press <Enter> to stop it.\n"
read -p "Time to stop? " -r

sudo docker stop server2
