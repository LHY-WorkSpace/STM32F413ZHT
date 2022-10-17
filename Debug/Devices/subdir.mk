################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Devices/ST7789.c 

OBJS += \
./Devices/ST7789.o 

C_DEPS += \
./Devices/ST7789.d 


# Each subdirectory must supply rules for building sources it contributes
Devices/%.o Devices/%.su: ../Devices/%.c Devices/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F413xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"F:/123/STM32F413_CubeMX/STM32F413ZHT/Devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Devices

clean-Devices:
	-$(RM) ./Devices/ST7789.d ./Devices/ST7789.o ./Devices/ST7789.su

.PHONY: clean-Devices

