## Part 1. Готовый докер
Взять официальный докер образ с nginx и выкачать его при помощи docker pull
![img](/src/part1/docker%20pull.png)

Проверить наличие докер образа через docker images
![img](/src/part1/docker%20images.png)

Запустить докер образ через docker run -d [image_id|repository]
![img](/src/part1/docker%20run.png)

Проверить, что образ запустился через docker ps
![img](/src/part1/docker%20ps1.png)


Посмотреть информацию о контейнере через docker inspect [container_id|container_name]

По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера

id

![img](/src/part1/docker_inspect.png)

size

![img](/src/part1/docker%20inspect%20Size.png)

ports

![img](/src/part1/docker%20inspect%20%20Exposed.png)

Остановить докер образ через docker stop [container_id|container_name]
![img](/src/part1/docker%20stop.png)

Проверить, что образ остановился через docker ps
![img](/src/part1/docker%20ps%202.png)

Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run
![img](/src/part1/docker%20run.png)
![img](/src/part1/docker%20run%20ps.png)

Проверить, что в браузере по адресу localhost:80 доступна стартовая страница nginx
![img](/src/part1/local%20host.png)


Перезапустить докер контейнер через docker restart [container_id|container_name]
![img](/src/part1/docker%20restart.png)


Проверить любым способом, что контейнер запустился
![img](/src/part1/docker%20ps%202.png)


## Part 2. Операции с контейнером


Прочитать конфигурационный файл nginx.conf внутри докер контейнера через команду exec
![img](/src/part2/images/2.1.png)


Создать на локальной машине файл nginx.conf

![img](/src/part2/images/2.2.png)

Настроить в нем по пути /status отдачу страницы статуса сервера nginx
![img](/src/part2/images/2.3.png)

Скопировать созданный файл nginx.conf внутрь докер образа через команду docker cp
![img](/src/part2/images/2.4.png)


Перезапустить nginx внутри докер образа через команду exec
![img](/src/part2/images/2.5.png)

Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx
![img](/src/part2/images/2.6.png)

Экспортировать контейнер в файл container.tar через команду export
![img](/src/part2/images/2.6.png)

Остановить контейнер
(переделала все с контенером 7250dfa40cfc)

![img](/src/part2/images/2.7.png)

Удалить образ через docker rmi [image_id|repository], не удаляя перед этим контейнеры
![img](/src/part2/images/2.8.png)


Удалить остановленный контейнер

![img](/src/part2/images/2.9.png)


Импортировать контейнер обратно через команду import
![img](/src/part2/images/2.10.png)


Запустить импортированный контейнер
![img](/src/part2/images/2.11.png)


Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx
![img](/src/part2/images/2.12.png)


## Part 3. Мини веб-сервер

Написать мини сервер на C и FastCgi, который будет возвращать простейшую страничку с надписью Hello World!

![img](/src/part3/images/3.1.png)

скопировала сервер в докер через команду docker cp

перешла в интерактивный режим(внутрь своего контейнера)

![img](/src/part3/images/3.2.png)


скачала нужные библиотки:
apt update

apt-get install libfcgi-dev

apt-get install spawn-fcgi

apt-get install gcc

запуск

![img](/src/part3/images/3.2.png)

Написать свой nginx.conf, который будет проксировать все запросы с 81 порта на 127.0.0.1:8080
![img](/src/part3/images/3.3.png)

cкачала nginx

![img](/src/part3/images/3.4.png)

запустила nginx

![img](/src/part3/images/3.5.png)
![img](/src/part3/images/3.6.png)

скопировала туда файлы server.c и nginx.conf

![img](/src/part3/images/3.7.png)


запутила server.c

запустила через spawn-fcgi
![img](/src/part3/images/3.8.png)

Проверить, что в браузере по localhost:81 отдается написанная вами страничка
![img](/src/part3/images/3.9.png)


## Part 4. Свой докер

При написании докер образа избегайте множественных вызовов команд RUN

Написать свой докер образ, который:

1) собирает исходники мини сервера на FastCgi из Части 3
![img](/src/part4/images/4.1.png)

2) запускает его на 8080 порту
![img](/src/part4/images/4...png)

3) копирует внутрь образа написанный ./nginx/nginx.conf
![img](/src/part4/images/4.png)

4) запускает nginx.
nginx можно установить внутрь докера самостоятельно, а можно воспользоваться готовым образом с nginx'ом, как базовым.
![img](/src/part4/images/Screenshot%20from%202024-12-06%2020-43-42.png)

Проверить через docker images, что все собралось корректно
![img](/src/part4/images/4.2.png)

Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а (см. Часть 2)
![img](/src/part4/images/4.3.png)

Проверить, что по localhost:80 доступна страничка написанного мини сервера
![img](/src/part4/images/4.5.png)

Дописать в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx
![img](/src/part4/images/4.4.png)

Перезапустить докер образ
Если всё сделано верно, то, после сохранения файла и перезапуска контейнера, конфигурационный файл внутри докер образа должен обновиться самостоятельно без лишних действий

Проверить, что теперь по localhost:80/status отдается страничка со статусом nginx
![img](/src/part4/images/4.6.png))

## Part 5. Dockle

После написания образа никогда не будет лишним проверить его на безопасность.
== Задание ==

Просканировать образ из предыдущего задания через dockle [image_id|repository]
![img](/src/part5/images/5.1.png)



Исправить образ так, чтобы при проверке через dockle не было ошибок и предупреждений

Для исправления ошибки:

"CIS-DI-0005: Enable Content trust for Docker" перед тем как собрать докер, использую эту команду "export DOCKER_CONTENT_TRUST=1"

"CIS-DI-0010: Do not store credential in environment variables/files"-команда dockle -ak NGINX_GPGKEY -ak NGINX_GPGKEY_PATH lll:2.0

готовый dockerfile
![img](/src/part5/images/5.3.png)
![img](/src/part5/images/5.2.png)

## Part 6. Базовый Docker Compose

Вот вы и закончили вашу разминку. А хотя погодите...
Почему бы не поэкспериментировать с развёртыванием проекта, состоящего сразу из нескольких докер образов?
== Задание ==

Написать файл docker-compose.yml, с помощью которого:

1) Поднять докер контейнер из Части 5 (он должен работать в локальной сети, т.е. не нужно использовать инструкцию EXPOSE и мапить порты на локальную машину)


2) Поднять докер контейнер с nginx, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера

Замапить 8080 порт второго контейнера на 80 порт локальной машины

Остановить все запущенные контейнеры

Собрать и запустить проект с помощью команд docker-compose build и docker-compose up
![img](/src/part6/images/6.1.jpg)


Проверить, что в браузере по localhost:80 отдается написанная вами страничка, как и ранее


![img](/src/part6/images/6.2.jpg)