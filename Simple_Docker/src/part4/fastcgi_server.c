/*
 * hello.cpp
 * Copyright (C) 2015 uralbash <root@uralbash.ru>
 *
 * Distributed under terms of the MIT license.
 * 
 * Reference: https://lectureswww.readthedocs.io/5.web.server/fcgi.html
 * 
 * About 502 Bad Gateway: https://stackoverflow.com/questions/18305484/nginx-fastcgi-c-throws-502-bad-gateway
 */


#include "fcgi_stdio.h"
#include <stdlib.h>


int main(void)
{
    while (FCGI_Accept() >= 0)
    {
        printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\nHello World!");
    }

    return 0;
}
