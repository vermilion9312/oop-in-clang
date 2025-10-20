/*
 * led_manager.h
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */

#ifndef INC_LED_MANAGER_H_
#define INC_LED_MANAGER_H_

#include <main.h>
#include <input.h>
#include <output.h>
#include <uart.h>

typedef struct _LEDManager LEDManager;
struct _LEDManager {
	void (* operate)(LEDManager*, bool, uint8_t);
};

typedef struct _LEDManagerPrivate LEDManagerPrivate;
struct _LEDManagerPrivate {
	LEDManager public;

	Input*  button;
	Input* direction_button;

	Output* led;
	Output* left_led;
	Output* right_led;

	Uart* uart;
	uint8_t rx_data;
};

LEDManager* new_LEDManager(Input*, Output*, Output*, Uart*, uint8_t);

#endif /* INC_LED_MANAGER_H_ */
