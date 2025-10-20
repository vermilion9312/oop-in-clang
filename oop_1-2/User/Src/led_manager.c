/*
 * led_manager.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <led_manager.h>

static void operate(LEDManager* public, bool dir_toggle, uint8_t rx_snapshot)
{
	LEDManagerPrivate* this = (LEDManagerPrivate*) public;
	Input*  button           = this->button;
	Input*  direction_button = this->direction_button;
	Uart*   uart             = this->uart;

	button->update(button);
	direction_button->update(direction_button);



	if (direction_button->is_released(direction_button) || dir_toggle == '4')
	{
		this->led = (this->led == this->left_led) ? this->right_led : this->left_led;
	}

	if (button->is_released(button) || rx_snapshot == this->rx_data)
	{
		this->led->toggle(this->led);
	}
}

LEDManager* new_LEDManager(Input* button, Output* left_led, Output* right_led, Uart* uart, uint8_t rx_data)
{
	LEDManagerPrivate* this = malloc(sizeof(LEDManagerPrivate));

	this->public.operate = operate;

	this->button           = button;
	this->direction_button = new_Input(BUTTON_4_GPIO_Port, BUTTON_4_Pin);
	this->led              = left_led;
	this->left_led         = left_led;
	this->right_led        = right_led;
	this->uart             = uart;
	this->rx_data          = rx_data;

	return (LEDManager*) this;
}
