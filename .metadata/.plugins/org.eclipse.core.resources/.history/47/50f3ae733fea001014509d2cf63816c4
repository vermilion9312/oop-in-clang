/*
 * timer.c
 *
 *  Created on: Jan 3, 2026
 *      Author: LeeJooHo
 */

#ifndef SRC_TIMER_C_
#define SRC_TIMER_C_

#include <timer.h>

static uint32_t time;

void increase_time(void)
{
	time++;
}

void set_time_zero(void)
{
	time = 0;
}

uint32_t get_time(TimeIndex index)
{
	switch (index)
	{
	case TIME_100MS:
		return (time / 100) % 10;
	case TIME_SEC:
		return (time / 1000) % 10;
	default:
		return 0;
	}
}

#endif /* SRC_TIMER_C_ */
