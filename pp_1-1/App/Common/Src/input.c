/*
 * input.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <input.h>

static bool is_on(Input* this)
{
	return this->state;
}

static bool is_rising(Input* this)
{
	return !this->last_state && this->state;
}

static bool is_falling(Input* this)
{
	return this->last_state && !this->state;
}

void update_input(Input* this)
{
	this->last_state = this->state;
	bool state = HAL_GPIO_ReadPin(this->port, this->pin);
	this->state = (this->type == NOMAL_OPEN) ? state : !state;

	if (!this->context || !this->callback) return;

	if (is_on(this))      this->callback(this->context, EVENT_ON);
	if (is_rising(this))  this->callback(this->context, EVENT_RISING);
	if (is_falling(this)) this->callback(this->context, EVENT_FALLING);
}

void set_callback(Input* this, void* context, Callback callback)
{
	this->context  = context;
	this->callback = callback;
}
