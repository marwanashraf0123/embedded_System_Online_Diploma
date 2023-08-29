/*
 * main.c
 *
 *  Created on: 28 Aug 2023
 *      Author: marwa
 */

/*
 * main.c
 *
 *  Created on: 28 Aug 2023
 *      Author: marwan
 */

#include "FIFO.h"
#include <stdio.h>




int main()
{
	FIFO_buf_t uart_buf;
	if(FIFO_init(&uart_buf , uart_buffer,SIZE) == FIFO_NO_ERROR)
	{
		printf("done init");
		printf("\n");
	}



	for (element_type i = 0 ; i < 10;i++)
	{
		if(FIFO_push(&uart_buf , i) == FIFO_NO_ERROR)
		{
			printf("done pushing %d",i);
			printf("\n");
		}

	}


	FIFO_is_full(&uart_buf);
			printf("\n");
	printf("\n");
	FIFO_print(&uart_buf);


	for (element_type i = 0 ; i < 10;i++)
		{
			if(FIFO_pop(&uart_buf , &i) == FIFO_NO_ERROR)
			{
				printf(" %d done popping",i);

				printf("\n");
			}


		}
	FIFO_is_full(&uart_buf);
	printf("\n");
	printf("\n");
	FIFO_print(&uart_buf);
}


