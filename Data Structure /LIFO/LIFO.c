/*
 * LIFO.c
 *
 *  Created on: 28 Aug 2023
 *      Author: marwan
 */
#include "LIFO.h"

LIFO_status LIFO_init(LIFO_buf_t* LIFO_Config , element_type*buf,int size)
{
	if(buf == NULL)
		return LIFO_NULL;

	LIFO_Config->base = buf;
	LIFO_Config->head =LIFO_Config->base;
	LIFO_Config->count = 0 ;
	LIFO_Config->length = size;

	return LIFO_NO_ERROR;
}
LIFO_status LIFO_push(LIFO_buf_t* LIFO_Config , element_type item)
{
	if(!LIFO_Config->head || !LIFO_Config->base)
		return LIFO_NULL;

	if(LIFO_Config->count == LIFO_Config->length)
		return LIFO_FULL;

	*(LIFO_Config->head) = item;
	printf("%d \t",*(LIFO_Config->head));
	LIFO_Config->head++;
	LIFO_Config->count++;
	return LIFO_NO_ERROR;
}
LIFO_status LIFO_pop(LIFO_buf_t* LIFO_Config , element_type*item)
{
	if(!LIFO_Config->head || !LIFO_Config->base)
		return LIFO_NULL;

	if(LIFO_Config->count == 0)
		return LIFO_EMPTY;

	LIFO_Config->head--;
	*item = *(LIFO_Config->head);
	LIFO_Config->count--;

	return LIFO_NO_ERROR;
}
void LIFO_print(LIFO_buf_t* LIFO_Config)
{
	if(LIFO_Config->count==0)
	{
		printf("LIFO is Empty");
		return ;
	}
	element_type *temp = LIFO_Config->base;

	for(element_type  i = 0 ;i<LIFO_Config->length ;i++)
	{
		printf("%d",*temp);
		temp++;
		printf("\n");
	}


}

LIFO_status LIFO_is_full(LIFO_buf_t*LIFO_Config)
{
	if(!LIFO_Config->head || !LIFO_Config->base)
		return LIFO_NULL;

	if(LIFO_Config->head == (LIFO_Config->base + LIFO_Config->length )) // if(LIFO_Config->count==LIFO_Config->length)
	{
		printf("LIFO_FULL");
		return LIFO_FULL;
	}
	else
	{
		printf("LIFO_NOT_FULL");
		return LIFO_NOT_FULL;
	}

}



