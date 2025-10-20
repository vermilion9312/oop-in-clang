/*
 * led_manager.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <led_manager.h>

static void operate(LEDManager* public)
{
	LEDManagerPrivate* this = (LEDManagerPrivate*) public;
	Input*  button    = this->button;
	Output* left_led  = this->left_led;
	Output* right_led = this->right_led;

	button->update(button);
	if (button->is_pressed(button))  left_led->toggle(left_led);
	if (button->is_released(button)) right_led->toggle(right_led);
}

LEDManager* new_LEDManager(Input* button, Output* left_led, Output* right_led)
{
	LEDManagerPrivate* this = malloc(sizeof(LEDManagerPrivate));

	this->public.operate = operate;

	this->button    = button;
	this->left_led  = left_led;
	this->right_led = right_led;

	return (LEDManager*) this;
}
