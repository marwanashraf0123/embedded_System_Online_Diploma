/*
 * FIFO.h
 *
 *  Created on: 28 Aug 2023
 *      Author: marwan
 */

#ifndef FIFO_H_
#define FIFO_H_

/*****************************************************************************
                          Config
****************************************************************************/
#define element_type unsigned char
//buffer 1
#define SIZE 5
element_type uart_buffer[SIZE];


typedef struct
{
	int count;
	int length;
	element_type* base;
	element_type* head;
	element_type* tail;

}FIFO_buf_t;


typedef enum
{
	FIFO_NO_ERROR,FIFO_NULL,FIFO_FULL,FIFO_EMPTY,FIFO_NOT_FULL
}FIFO_status;

/********************************************************************************************************
 	 	 	 	 	 	 	 	 	 	 APIS
 ********************************************************************************************************/
FIFO_status FIFO_init(FIFO_buf_t* FIFO_Config , element_type*buf,int size);
FIFO_status FIFO_push(FIFO_buf_t* FIFO_Config , element_type item);
FIFO_status FIFO_pop(FIFO_buf_t* FIFO_Config , element_type*item);
FIFO_status FIFO_is_full(FIFO_buf_t*FIFO_Config);
void FIFO_print(FIFO_buf_t* FIFO_Config);

#endif /* FIFO_H_ */
