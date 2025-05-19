################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32c0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32c0xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32c0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32c0xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32c0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32c0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/GPIO" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/I2C" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/AD9834" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/CMSIS/Device/ST/STM32C0xx/Include" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/SPI" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/USART" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/Delay" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/NSS" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/SI5351" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/SI4735" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/AXP209" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/ADF4351" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/AD9959" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/RFFC5071" -I"C:/Users/idepo/STM32CubeIDE/workspace_1.18.0/stm32c071_basic/Drivers/lowlevel/ICs/MAX5712" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32c0xx_it.cyclo ./Core/Src/stm32c0xx_it.d ./Core/Src/stm32c0xx_it.o ./Core/Src/stm32c0xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32c0xx.cyclo ./Core/Src/system_stm32c0xx.d ./Core/Src/system_stm32c0xx.o ./Core/Src/system_stm32c0xx.su

.PHONY: clean-Core-2f-Src

