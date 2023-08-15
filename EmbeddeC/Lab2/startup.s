/*Copy rights marwan ashraf*/



.section .vector

.word   0x20001000
.word 	_reset   /*Reset*/	
.word 	Vector_handler 	 /*NMI*/	
.word 	Vector_handler   /*Hard Fault*/
.word 	Vector_handler   /*MM_Fault*/
.word 	Vector_handler   /*Usage Fault*/




.section .text

_reset:
	bl main
	b .

.thumb_func
Vector_handler:
	bl _reset