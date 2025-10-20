/*
 * seven_segment.c
 *
 *  Created on: Oct 13, 2025
 *      Author: vermi
 */


#include <seven_segment.h>

static void operate(SevenSegment* public)
{
	SevenSegmentPrivate* this = (SevenSegmentPrivate*) public;
	uint16_t count = this->count;

	uint8_t ones_digit   = (count / 1000) % 10;
	uint8_t tenths_digit = (count /  100) % 10;

	uint8_t dot1 = (tenths_digit < 5) ? ON : OFF;
	uint8_t dot2 = (!ones_digit && !tenths_digit) ? ON : OFF;

	_7SEG_SetNumber(DGT1, ones_digit,   dot1);
	_7SEG_SetNumber(DGT2, tenths_digit, dot2);
}

static void count_up(SevenSegment* public)
{
	SevenSegmentPrivate* this = (SevenSegmentPrivate*) public;

	this->count++;
}

SevenSegment* new_SevenSegment(void)
{
	SevenSegmentPrivate* this = malloc(sizeof(SevenSegmentPrivate));

	this->public.operate  = operate;
	this->public.count_up = count_up;

	this->count = 0;

	return (SevenSegment*) this;
}
