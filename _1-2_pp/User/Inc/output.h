/*
 * output.h
 *
 *  Created on: Sep 22, 2025
 *      Author: vermi
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

#include <common_include.h>

typedef enum {
	LED_RED,
	LED_GREEN,
	LED_BLUE,

	MAX_OUTPUT
} OutputIndex;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	bool          state;
} OutputConfig;

void turn_on(OutputIndex);
void turn_off(OutputIndex);
void toggle(OutputIndex);
void change_config(void);

#endif /* INC_OUTPUT_H_ */
