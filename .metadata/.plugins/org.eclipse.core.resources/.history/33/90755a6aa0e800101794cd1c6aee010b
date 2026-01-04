/*
 * app_main.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <app_main.h>
#include <main.h>
#include <input.h>
#include <output.h>

void app_init(void)
{

}

void app_loop(void)
{
	update(BUTTON_1);
	update(BUTTON_2);
	update(BUTTON_3);
	update(BUTTON_4);

	if(is_released(BUTTON_1)) toggle(LED_RED);
	if(is_released(BUTTON_2)) toggle(LED_GREEN);
	if(is_released(BUTTON_3)) toggle(LED_BLUE);
	if(is_released(BUTTON_4)) change_config();
}
