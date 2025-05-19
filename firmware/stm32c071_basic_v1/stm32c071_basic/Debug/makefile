################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/lowlevel/USART/subdir.mk
-include Drivers/lowlevel/SPI/subdir.mk
-include Drivers/lowlevel/NSS/subdir.mk
-include Drivers/lowlevel/ICs/SI5351/subdir.mk
-include Drivers/lowlevel/ICs/SI4735/subdir.mk
-include Drivers/lowlevel/ICs/RFFC5071/subdir.mk
-include Drivers/lowlevel/ICs/MAX5712/subdir.mk
-include Drivers/lowlevel/ICs/AXP209/subdir.mk
-include Drivers/lowlevel/ICs/ADF4351/subdir.mk
-include Drivers/lowlevel/ICs/AD9959/subdir.mk
-include Drivers/lowlevel/ICs/AD9834/subdir.mk
-include Drivers/lowlevel/I2C/subdir.mk
-include Drivers/lowlevel/GPIO/subdir.mk
-include Drivers/lowlevel/Delay/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := stm32c071_basic
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stm32c071_basic.elf \

MAP_FILES += \
stm32c071_basic.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm32c071_basic.list \


# All Target
all: main-build

# Main-build Target
main-build: stm32c071_basic.elf secondary-outputs

# Tool invocations
stm32c071_basic.elf stm32c071_basic.map: $(OBJS) $(USER_OBJS) C:\Users\idepo\STM32CubeIDE\workspace_1.18.0\stm32c071_basic\STM32C071C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "stm32c071_basic.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"C:\Users\idepo\STM32CubeIDE\workspace_1.18.0\stm32c071_basic\STM32C071C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm32c071_basic.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm32c071_basic.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm32c071_basic.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout stm32c071_basic.elf stm32c071_basic.list stm32c071_basic.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
