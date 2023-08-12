#include <stdio.h>
#include <uart.h>


unsigned char str[100] = "Hello";


int main()
{
    UART_writestring(str);

}
