/*
 * lcd.h
 *
 *  Created on: Oct 18, 2025
 *      Author: vermi
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include <common_include.h>
#include <CLCD.h>
#include <timer.h>
#include <mode_mediator.h>

typedef struct _LCD LCD;
struct _LCD {
	void (* operate)(LCD*);
};

typedef struct _LCDPrivate LCDPrivate;
struct _LCDPrivate {
	LCD public;

	ModeMediator* mediator;
	Timer* timer;
};

LCD* new_LCD(ModeMediator*);

#endif /* INC_LCD_H_ */
