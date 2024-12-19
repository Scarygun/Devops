#!/usr/bin/env bash


sudo docker build . -t server:v2

sudo docker images

sudo docker run --rm -d -p 80:81 --name server2 server:v2

printf "The sever is up. Press <Enter> to stop it.\n"
read -p "Time to stop? " -r

sudo docker stop server2
