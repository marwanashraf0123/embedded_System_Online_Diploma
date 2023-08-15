// Marwan Ashraf.

#include <stdint.h>

extern int main();

void Reset_Handler(void);

void Defualt_Handler()
{
	Reset_Handler();
}



/***************************************************************************************/
void NMI_Handler(void) __attribute__((weak, alias("Defualt_Handler")));
void H_fault_Handler(void) __attribute__((weak, alias("Defualt_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Defualt_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak, alias("Defualt_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Defualt_Handler")));


/***************************************************************************************/
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _stack_top;

/***************************************************************************************/

uint32_t vector[] __attribute__((section(".vectors"))) = {
 
	(uint32_t)&_stack_top,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&H_fault_Handler,
	(uint32_t)&MM_Fault_Handler,
	(uint32_t)&Bus_Fault_Handler,
	(uint32_t)&Usage_Fault_Handler,
	
};
/****************************************************************************************/

void Reset_Handler()
{
	uint32_t Data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char *Ptr_src = (unsigned char*)&_E_text;
	unsigned char *Ptr_dst = (unsigned char*)&_S_data;

// Copy .data section from Flash to ram
	for (int  i = 0 ; i < Data_size ;i++)
	{
		*((unsigned char*)Ptr_dst++)  = *((unsigned char*)Ptr_src++); 
	}

// Init the .bss section in ram
	unsigned char bss_size =(unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	Ptr_dst = (unsigned char*)&_S_bss;

	for (int  i = 0 ; i < bss_size ; i++)
	{
		*((unsigned char*)Ptr_dst++) =(unsigned char)0;
	}

// jump to main
	main();
}