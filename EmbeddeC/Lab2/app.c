
#include <stdint.h>


#define RCC_Base 0x40021000
#define PortA_Base 0x40010800

#define RCC_A    *(unsigned volatile long *)(RCC_Base+0x18)
#define GPIOA_CRH *(unsigned volatile long *)(PortA_Base+0x04)
#define GPIOA_ODR *(unsigned volatile long *)(PortA_Base+0x0c)

typedef union
{
	volatile unsigned long PortA;
	 struct
	{
		volatile unsigned long reserved:13;
		volatile unsigned long pin13:1;


	}pin;


}port_a;

unsigned int str[3] = {1,2,3};
unsigned int str1[3];



int main(void)
{
    int i;

	volatile port_a *Port_A_LED = ( volatile port_a *)(PortA_Base+0x0c);
    RCC_A |=(1<<2);

    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;


	while(1)
	{
		Port_A_LED -> pin.pin13 = 0;
		//GPIOA_ODR ^=(1<<13);
		for (  i = 0 ; i < 5000 ;i++);
		Port_A_LED -> pin.pin13 = 1 ;
		for (  i = 0 ; i < 5000 ;i++);
	}
}
