/*
 * output.c
 *
 *  Created on: Sep 22, 2025
 *      Author: vermi
 */


#include <output.h>

static void turn_on(Output* public)
{
	OutputPrivate* this = (OutputPrivate*) public;

	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);
	this->state = true;
}

static void turn_off(Output* public)
{
	OutputPrivate* this = (OutputPrivate*) public;

	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);
	this->state = false;
}

static void toggle(Output* public)
{
	OutputPrivate* this = (OutputPrivate*) public;

	this->state ? turn_off(public) : turn_on(public);
}

Output* new_Output(GPIO_TypeDef* port, uint16_t pin)
{
	OutputPrivate* this = malloc(sizeof(OutputPrivate));

	this->public.turn_on  = turn_on;
	this->public.turn_off = turn_off;
	this->public.toggle   = toggle;

	this->port  = port;
	this->pin   = pin;
	this->state = false;

	return (Output*) this;
}
