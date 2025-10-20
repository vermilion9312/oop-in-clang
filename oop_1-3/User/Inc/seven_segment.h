/*
 * seven_segment.h
 *
 *  Created on: Oct 13, 2025
 *      Author: vermi
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

#include <common_include.h>
#include <7SEG.h>

typedef struct _SevenSegment SevenSegment;
struct _SevenSegment {
	void (* operate)(SevenSegment*);
	void (* count_up)(SevenSegment*);
};

typedef struct _SevenSegmentPrivate SevenSegmentPrivate;
struct _SevenSegmentPrivate {
	SevenSegment public;

	uint16_t count;
};

SevenSegment* new_SevenSegment(void);

#endif /* INC_SEVEN_SEGMENT_H_ */
