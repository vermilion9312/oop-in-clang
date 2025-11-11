/*
 * led_manager.h
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */

#ifndef INC_LED_MANAGER_H_
#define INC_LED_MANAGER_H_

#include <input.h>
#include <output.h>

CLASS (LEDManager) {
	void (* operate)(LEDManager*);
};

PRIVATE (LEDManager) {
	LEDManager public;

	Input*  button;
	Output* left_led;
	Output* right_led;
};

LEDManager* new_LEDManager(Input*, Output*, Output*);

#endif /* INC_LED_MANAGER_H_ */
