/*
 * segment.c
 *
 *  Created on: Jan 3, 2026
 *      Author: LeeJooHo
 */


#include <segment.h>

void operate_segment(bool is_held)
{
	_7SEG_SetNumber(DGT1, get_time(TIME_SEC), (is_held && get_time(TIME_100MS) < 5) ? OFF : ON);
	_7SEG_SetNumber(DGT2, get_time(TIME_100MS), OFF);
}

