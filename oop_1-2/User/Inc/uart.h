/*
 * uart.h
 *
 *  Created on: Oct 8, 2025
 *      Author: vermi
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include <common_include.h>

#define BUFFER_SIZE 1

typedef struct _Uart Uart;
struct _Uart {
	void (* receive)(Uart*);
	uint8_t (* get_rx_data)(Uart*);
	void (* reset_data)(Uart*);
};

typedef struct _UartPrivate UartPrivate;
struct _UartPrivate {
	Uart public;

	UART_HandleTypeDef* handle;
	uint8_t rx_data;
};

Uart* new_Uart(UART_HandleTypeDef* handle);

#endif /* INC_UART_H_ */
