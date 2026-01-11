/*
 * rgb.h
 *
 *  Created on: Jan 10, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_RGB_H_
#define INC_RGB_H_

#include <input.h>
#include <output.h>

typedef struct {
	Output* left_led;
	Output* right_led;
} RGB;

void operate_rgb(RGB*, InputEvent);

#endif /* INC_RGB_H_ */
