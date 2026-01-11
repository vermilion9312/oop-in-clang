/*
 * input.h
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include <common_include.h>

typedef enum {
	EVENT_ON,
	EVENT_RISING,
	EVENT_FALLING
} InputEvent;

typedef enum {
	NOMAL_OPEN,
	NOMAL_CLOSE
} InputType;

typedef void (* Callback)(void*, InputEvent);

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	InputType     type;
	bool          last_state;
	bool          state;
	void*         context;
	Callback      callback;
} Input;

void update_input(Input*);
void set_callback(Input*, void*, Callback);

#endif /* INC_INPUT_H_ */
