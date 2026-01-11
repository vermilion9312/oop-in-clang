/*
 * rgb.c
 *
 *  Created on: Jan 10, 2026
 *      Author: LeeJooHo
 */


#include <rgb.h>

void operate_rgb(RGB* this, InputEvent event)
{
	switch(event)
	{
	case EVENT_ON:
		return;
	case EVENT_RISING:
		toggle_output(this->left_led);
		return;
	case EVENT_FALLING:
		toggle_output(this->right_led);
		return;
	default:
		return;
	}
}
