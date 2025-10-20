/*
 * app_main.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <app_main.h>
#include <main.h>
#include <led_manager.h>
#include <seven_segment.h>

static Input*        button_1;
static Output*       left_red;
static Output*       right_red;
static LEDManager*   led_red;
static SevenSegment* segment;

void app_init(void)
{
	_7SEG_GPIO_Init();

	button_1  = new_Input(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	left_red  = new_Output(LEFT_RED_GPIO_Port,  LEFT_RED_Pin );
	right_red = new_Output(RIGHT_RED_GPIO_Port, RIGHT_RED_Pin);
	led_red   = new_LEDManager(button_1, left_red, right_red);
	segment   = new_SevenSegment();
}

void app_loop(void)
{
	led_red->operate(led_red);
	segment->operate(segment);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		if (button_1->is_held(button_1)) segment->count_up(segment);
	}
}
