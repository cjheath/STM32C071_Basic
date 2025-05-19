################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lowlevel/GPIO/GPIO.c 

OBJS += \
./Drivers/lowlevel/GPIO/GPIO.o 

C_DEPS += \
./Drivers/lowlevel/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lowlevel/GPIO/%.o Drivers/lowlevel/GPIO/%.su Drivers/lowlevel/GPIO/%.cyclo: ../Drivers/lowlevel/GPIO/%.c Drivers/lowlevel/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/GPIO" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/I2C" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/AD9834" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/CMSIS/Device/ST/STM32C0xx/Include" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/SPI" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/USART" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/Delay" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/NSS" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/SI5351" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/SI4735" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/AXP209" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/ADF4351" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/AD9959" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/RFFC5071" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/MAX5712" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lowlevel-2f-GPIO

clean-Drivers-2f-lowlevel-2f-GPIO:
	-$(RM) ./Drivers/lowlevel/GPIO/GPIO.cyclo ./Drivers/lowlevel/GPIO/GPIO.d ./Drivers/lowlevel/GPIO/GPIO.o ./Drivers/lowlevel/GPIO/GPIO.su

.PHONY: clean-Drivers-2f-lowlevel-2f-GPIO

