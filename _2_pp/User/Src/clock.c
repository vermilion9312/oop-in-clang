/*
 * clock.c
 *
 *  Created on: Jan 3, 2026
 *      Author: LeeJooHo
 */


#include <clock.h>

static ClockMode clock_mode = MODE_STOPWATCH;

void operation_clock(void)
{
	switch (clock_mode)
	{
	case MODE_CLOCK:
		return;
	case MODE_TIMER:
		return;
	case MODE_STOPWATCH:
		operate_stopwatch();
		return;
	case MODE_ALARM:
		return;
	case MODE_MUSIC_PLAYER:
		return;
	default:
		return;
	}
}
