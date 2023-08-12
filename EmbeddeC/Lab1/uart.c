
#define UART0DR *(volatile long* const)(0x101f1000)



void UART_writestring(unsigned char *ptr)
{
    while (*ptr != '\0')
    {
    UART0DR = (unsigned long)(*ptr);
    ptr++;
    }
}
