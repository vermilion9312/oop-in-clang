/*
 * app_main.c
 *
 *  Created on: Sep 23, 2025
 *      Author: vermi
 */


#include <app_main.h>
#include <main.h>
#include <led_manager.h>

static Input* button_1;
static Input* button_2;
static Input* button_3;

static Output* left_red;
static Output* left_green;
static Output* left_blue;

static Output* right_red;
static Output* right_green;
static Output* right_blue;

static LEDManager* led_red;
static LEDManager* led_green;
static LEDManager* led_blue;

void app_init(void)
{
	button_1 = new_Input(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	button_2 = new_Input(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	button_3 = new_Input(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	left_red   = new_Output(LEFT_RED_GPIO_Port,   LEFT_RED_Pin  );
	left_green = new_Output(LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin);
	left_blue  = new_Output(LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin );

	right_red   = new_Output(RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin  );
	right_green = new_Output(RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin);
	right_blue  = new_Output(RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin );

	led_red   = new_LEDManager(button_1, left_red,   right_red  );
	led_green = new_LEDManager(button_2, left_green, right_green);
	led_blue  = new_LEDManager(button_3, left_blue,  right_blue );
}

void app_loop(void)
{
	led_red->operate(led_red);
	led_green->operate(led_green);
	led_blue->operate(led_blue);
}
