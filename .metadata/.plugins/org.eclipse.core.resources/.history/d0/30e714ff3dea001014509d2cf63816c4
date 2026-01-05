################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/app_main.c \
../User/Src/input.c \
../User/Src/lcd.c \
../User/Src/output.c \
../User/Src/segment.c \
../User/Src/timer.c 

OBJS += \
./User/Src/app_main.o \
./User/Src/input.o \
./User/Src/lcd.o \
./User/Src/output.o \
./User/Src/segment.o \
./User/Src/timer.o 

C_DEPS += \
./User/Src/app_main.d \
./User/Src/input.d \
./User/Src/lcd.d \
./User/Src/output.d \
./User/Src/segment.d \
./User/Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Lib/Inc -I../User/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/app_main.cyclo ./User/Src/app_main.d ./User/Src/app_main.o ./User/Src/app_main.su ./User/Src/input.cyclo ./User/Src/input.d ./User/Src/input.o ./User/Src/input.su ./User/Src/lcd.cyclo ./User/Src/lcd.d ./User/Src/lcd.o ./User/Src/lcd.su ./User/Src/output.cyclo ./User/Src/output.d ./User/Src/output.o ./User/Src/output.su ./User/Src/segment.cyclo ./User/Src/segment.d ./User/Src/segment.o ./User/Src/segment.su ./User/Src/timer.cyclo ./User/Src/timer.d ./User/Src/timer.o ./User/Src/timer.su

.PHONY: clean-User-2f-Src

