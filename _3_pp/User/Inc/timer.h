/*
 * timer.h
 *
 *  Created on: Jan 3, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <common_include.h>

void increase_current_time(void);
void set_current_time_zero(void);
uint32_t get_current_time(void);
void set_lap_time(void);
uint32_t get_lap_time(uint8_t);
uint8_t get_lap_count(void);

#endif /* INC_TIMER_H_ */
