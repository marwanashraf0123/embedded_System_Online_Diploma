/*
 * LIFO.h
 *
 *  Created on: 28 Aug 2023
 *      Author: marwan
 */
#include <stdio.h>
#include <stdint.h>

#ifndef LIFO_H_
#define LIFO_H_



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

}LIFO_buf_t;


typedef enum
{
	LIFO_NO_ERROR,LIFO_NULL,LIFO_FULL,LIFO_EMPTY,LIFO_NOT_FULL
}LIFO_status;

/********************************************************************************************************
 	 	 	 	 	 	 	 	 	 	 APIS
 ********************************************************************************************************/
LIFO_status LIFO_init(LIFO_buf_t* LIFO_Config , element_type*buf,int size);
LIFO_status LIFO_push(LIFO_buf_t* LIFO_Config , element_type item);
LIFO_status LIFO_pop(LIFO_buf_t* LIFO_Config , element_type*item);
LIFO_status LIFO_is_full(LIFO_buf_t*LIFO_Config);
void LIFO_print(LIFO_buf_t* LIFO_Config);



#endif /* LIFO_H_ */
