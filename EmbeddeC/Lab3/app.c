
#define SYSCTL_RCGC2_R       (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R     (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R     (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R    (*((volatile unsigned long*)0x400253FC))

int main()
{
	unsigned long delay;
	SYSCTL_RCGC2_R   |=0x00000020;
	delay=SYSCTL_RCGC2_R;

	GPIO_PORTF_DIR_R |=(1<<3);
	GPIO_PORTF_DEN_R |=(1<<3);


	while(1)
	{
		GPIO_PORTF_DATA_R ^=(1<<3);
		for(int i = 0 ; i <20000; i++ );
	}
}