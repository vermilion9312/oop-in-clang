/*
 * input.h
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include <common_include.h>
#include <callback.h>

#define MAX_CALLBACK 5

typedef enum {
	HELD,
	PRESSED,
	RELEASED,

} InputEvent;

CLASS (Input) {
	void (* tick)(Input*);
	void (* set_callback)(Input*, void*, CallbackFunction, InputEvent);
};

typedef bool (* InputCondition)(Input*);

PRIVATE (Input) {
	Input public;

	GPIO_TypeDef* port;
	uint16_t      pin;
	bool          last_state;
	bool          state;

	InputCondition condition[MAX_CALLBACK];
	Callback       callback[MAX_CALLBACK];
	uint8_t        total_callback;
};

Input* new_Input(GPIO_TypeDef*, uint16_t);

#endif /* INC_INPUT_H_ */
