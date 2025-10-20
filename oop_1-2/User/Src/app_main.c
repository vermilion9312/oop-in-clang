/*
 * app_main.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <app_main.h>
#include <main.h>
#include <led_manager.h>

static Input* button_1;
static Input* button_2;
static Input* button_3;
static Input* button_4;

static Output* left_red;
static Output* left_green;
static Output* left_blue;

static Output* right_red;
static Output* right_green;
static Output* right_blue;

static LEDManager* led_red;
static LEDManager* led_green;
static LEDManager* led_blue;

static Uart* uart;
extern UART_HandleTypeDef huart3;

void app_init(void)
{
	button_1 = new_Input(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	button_2 = new_Input(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	button_3 = new_Input(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
	button_4 = new_Input(BUTTON_4_GPIO_Port, BUTTON_4_Pin);

	left_red   = new_Output(LEFT_RED_GPIO_Port,   LEFT_RED_Pin  );
	left_green = new_Output(LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin);
	left_blue  = new_Output(LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin );

	right_red   = new_Output(RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin  );
	right_green = new_Output(RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin);
	right_blue  = new_Output(RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin );

	uart = new_Uart(&huart3);
	uart->receive(uart);

	led_red   = new_LEDManager(button_1, left_red,   right_red  , uart, '1');
	led_green = new_LEDManager(button_2, left_green, right_green, uart, '2');
	led_blue  = new_LEDManager(button_3, left_blue,  right_blue , uart, '3');
}

void app_loop(void)
{
	uint8_t rx_snapshot = uart->get_rx_data(uart);
	bool dir_toggle = (rx_snapshot == '4');

	led_red->operate(led_red, dir_toggle, rx_snapshot);
	led_green->operate(led_green, dir_toggle, rx_snapshot);
	led_blue->operate(led_blue, dir_toggle, rx_snapshot);

	if (rx_snapshot != 0) uart->reset_data(uart);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART3)
	{
		uart->receive(uart);
	}
}
