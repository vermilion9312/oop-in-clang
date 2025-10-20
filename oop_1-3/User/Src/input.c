/*
 * input.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <input.h>

static void update(Input* public)
{
	InputPrivate* this = (InputPrivate*) public;

	this->last_state = this->state;
	this->state = HAL_GPIO_ReadPin(this->port, this->pin);
}

static bool is_held(Input* public)
{
	InputPrivate* this = (InputPrivate*) public;

	return this->state;
}

static bool is_pressed(Input* public)
{
	InputPrivate* this = (InputPrivate*) public;

	return !this->last_state && this->state;
}

static bool is_released(Input* public)
{
	InputPrivate* this = (InputPrivate*) public;

	return this->last_state && !this->state;
}

Input* new_Input(GPIO_TypeDef* port, uint16_t pin)
{
	InputPrivate* this = malloc(sizeof(InputPrivate));

	this->public.update      = update;
	this->public.is_held     = is_held;
	this->public.is_pressed  = is_pressed;
	this->public.is_released = is_released;

	this->port       = port;
	this->pin        = pin;
	this->last_state = false;
	this->state      = false;

	return (Input*) this;
}
