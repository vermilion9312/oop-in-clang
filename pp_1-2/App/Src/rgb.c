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
		return;
	case EVENT_FALLING:
		toggle_output(this->led);
		return;
	default:
		return;
	}
}
