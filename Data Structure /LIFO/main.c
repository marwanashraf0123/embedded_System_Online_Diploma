/*
 * main.c
 *
 *  Created on: 28 Aug 2023
 *      Author: marwan
 */

#include "LIFO.h"
#include <stdio.h>




int main()
{
	LIFO_buf_t uart_buf;
	if(LIFO_init(&uart_buf , uart_buffer,SIZE) == LIFO_NO_ERROR)
	{
		printf("done init");
		printf("\n");
	}

	for (element_type i = 0 ; i < 10;i++)
	{
		if(LIFO_push(&uart_buf , i) == LIFO_NO_ERROR)
		{
			printf("done pushing");
			printf("\n");
		}

	}
	LIFO_is_full(&uart_buf);
			printf("\n");
	printf("\n");
	LIFO_print(&uart_buf);

	for (element_type i = 0 ; i < 10;i++)
		{
			if(LIFO_pop(&uart_buf , &i) == LIFO_NO_ERROR)
			{
				printf(" %d done popping",i);

				printf("\n");
			}


		}
	LIFO_is_full(&uart_buf);
	printf("\n");
	printf("\n");
	LIFO_print(&uart_buf);
}
