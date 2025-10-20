/*
 * uart.c
 *
 *  Created on: Oct 8, 2025
 *      Author: vermi
 */


#include <uart.h>

static void receive(Uart* public)
{
	UartPrivate* this = (UartPrivate*) public;

	HAL_UART_Receive_IT(this->handle, &this->rx_data, BUFFER_SIZE);
}

static uint8_t get_rx_data(Uart* public)
{
	UartPrivate* this = (UartPrivate*) public;

	return this->rx_data;
}

static void reset_data(Uart* public)
{
	UartPrivate* this = (UartPrivate*) public;

	this->rx_data = 0;
}

Uart* new_Uart(UART_HandleTypeDef* handle)
{
	UartPrivate* this = malloc(sizeof(UartPrivate));

	this->public.receive     = receive;
	this->public.get_rx_data = get_rx_data;
	this->public.reset_data  = reset_data;

	this->handle  = handle;
	this->rx_data = 0;

	return (Uart*) this;
}
