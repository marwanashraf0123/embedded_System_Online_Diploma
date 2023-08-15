/*Copy rights marwan ashraf*/

MEMORY
{
    FLASH(RX) : ORIGIN = 0x08000000 ,LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0x20000000 ,LENGTH = 20K 
}

SECTIONS
{
	.text : 
	{
     	*(.vector*)
     	*(.text*)  
     	_E_text = . ;
	}> FLASH

	.data :
	{
	_S_data = . ;
	*(.data*)
	_E_data = . ;
	}> SRAM AT> FLASH

	.bss :
	{

	_S_bss = . ;
	*(.bss*)
	. = ALIGN(4);
	_E_bss = .;

	. = ALIGN(4);
	. = . + 0x1000;
    _stack_top = . ;


	}> SRAM
}