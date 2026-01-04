/*
 * callback.h
 *
 *  Created on: Dec 14, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_CALLBACK_H_
#define INC_CALLBACK_H_

#include <common_include.h>

typedef void (* CallbackFunction)(void*);

CLASS (Callback) {
	void* context;
	CallbackFunction function;
};


#endif /* INC_CALLBACK_H_ */
