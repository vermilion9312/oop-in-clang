################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Mode/mode_stopwatch.c 

OBJS += \
./User/Mode/mode_stopwatch.o 

C_DEPS += \
./User/Mode/mode_stopwatch.d 


# Each subdirectory must supply rules for building sources it contributes
User/Mode/%.o User/Mode/%.su User/Mode/%.cyclo: ../User/Mode/%.c User/Mode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../User/Mode -I../User/Inc -I../Lib/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Mode

clean-User-2f-Mode:
	-$(RM) ./User/Mode/mode_stopwatch.cyclo ./User/Mode/mode_stopwatch.d ./User/Mode/mode_stopwatch.o ./User/Mode/mode_stopwatch.su

.PHONY: clean-User-2f-Mode

