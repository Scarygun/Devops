#include <stdio.h>
#include "fcgi_stdio.h"

int main() {
    FCGI_printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\nHello World!");
    return 0;
}
