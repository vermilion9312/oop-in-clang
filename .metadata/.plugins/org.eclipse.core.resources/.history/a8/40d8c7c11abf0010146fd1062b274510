/*
 * common_include.h
 *
 *  Created on: Sep 22, 2025
 *      Author: vermi
 */

#ifndef INC_COMMON_INCLUDE_H_
#define INC_COMMON_INCLUDE_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stm32f4xx.h>

#define CLASS(name) \
    typedef struct _##name name; \
    struct _##name

#define PRIVATE(name) \
    typedef struct _##name##Private name##Private; \
    struct _##name##Private

#define THIS(Type, obj) \
    Type##Private* this = (Type##Private*)(obj)

#endif /* INC_COMMON_INCLUDE_H_ */
