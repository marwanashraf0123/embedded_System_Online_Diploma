/*
 * FIFO.c
 *
 *  Created on: 28 Aug 2023
 *      Author: marwan
 */
#include <stdio.h>
#include "FIFO.h"



FIFO_status FIFO_init(FIFO_buf_t* FIFO_Config , element_type*buf,int size)
{

	if(buf==NULL)
		return FIFO_NULL;

	FIFO_Config->length = size;
	FIFO_Config->base=buf;
	FIFO_Config->head=buf;
	FIFO_Config->tail=buf;
	FIFO_Config->count=0;
	return FIFO_NO_ERROR;


}
FIFO_status FIFO_push(FIFO_buf_t* FIFO_Config , element_type item)
{

	if(!FIFO_Config->base || !FIFO_Config->head || !FIFO_Config->tail)
		return FIFO_NULL;


	if(FIFO_Config->count == FIFO_Config->length)
		return FIFO_FULL;


	*(FIFO_Config->head) = item;
	FIFO_Config->count++;
	//circluar FIFO
	if(FIFO_Config->head == (FIFO_Config->base+ (FIFO_Config->length +sizeof(element_type))))
		FIFO_Config->head = FIFO_Config->base;

	else
		FIFO_Config->head++;

	return FIFO_NO_ERROR;
}



FIFO_status FIFO_pop(FIFO_buf_t* FIFO_Config , element_type*item)
{
	if(!FIFO_Config->base || !FIFO_Config->head || !FIFO_Config->tail)
		return FIFO_NULL;

	if(FIFO_Config->count == 0)
		return FIFO_EMPTY;

	*item = *(FIFO_Config->tail);
	FIFO_Config->count--;

	if(FIFO_Config->tail == (FIFO_Config->base + (FIFO_Config->length + sizeof(element_type))))
		FIFO_Config->tail = FIFO_Config->base;


	else
		FIFO_Config->tail++;

	return FIFO_NO_ERROR;
}
FIFO_status FIFO_is_full(FIFO_buf_t*FIFO_Config)
{
	if(!FIFO_Config->base || !FIFO_Config->head || !FIFO_Config->tail)
		return FIFO_NULL;

	if(FIFO_Config->length == FIFO_Config->count)
	{
		printf("FIFO_FULL");
		return FIFO_FULL;
	}
	else
	{
		printf("FIFO_NOT_FULL");
		return FIFO_NOT_FULL;
	}
}

void FIFO_print(FIFO_buf_t* FIFO_Config)
{
	if(FIFO_Config->count==0)
		{
			printf("FIFO is Empty");
			return ;
		}

	element_type *temp = FIFO_Config->tail;
	for(int i = 0 ; i < FIFO_Config->length;i++)
	{
		printf("%d",*(temp));
		printf("\n");
		temp++;
	}
}
