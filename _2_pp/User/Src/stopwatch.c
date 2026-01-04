/*
 * stopwatch.c
 *
 *  Created on: Jan 3, 2026
 *      Author: LeeJooHo
 */


#include <stopwatch.h>

static State state = STATE_STOPPED;

void operate_stopwatch(void)
{
	switch (state)
	{
	case STATE_STOPPED:
		if (is_released(BUTTON_2)) state = STATE_RUNNING;
		return;
	case STATE_RUNNING:
		if (is_released(BUTTON_2)) state = STATE_PAUSED;
		return;
	case STATE_PAUSED:
		if (is_released(BUTTON_2)) state = STATE_RUNNING;
		if (is_released(BUTTON_3)) state = STATE_STOPPED;
		return;
	default:
		return;
	}
}
