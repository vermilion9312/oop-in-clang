/*
 * output.h
 *
 *  Created on: Sep 22, 2025
 *      Author: vermi
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

#include <common_include.h>

CLASS (Output) {
	void (* turn_on)(Output*);
	void (* turn_off)(Output*);
	void (* toggle)(Output*);
};

PRIVATE (Output) {
	Output public;

	GPIO_TypeDef* port;
	uint16_t      pin;
	bool          state;
};

Output* new_Output(GPIO_TypeDef*, uint16_t);

#endif /* INC_OUTPUT_H_ */
