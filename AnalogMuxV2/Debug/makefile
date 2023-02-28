################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SHIFT_REGISTER/subdir.mk
-include HAL/CLCD1602/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AnalogMuxV2.lss \

FLASH_IMAGE += \
AnalogMuxV2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AnalogMuxV2.elf secondary-outputs

# Tool invocations
AnalogMuxV2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AnalogMuxV2.map -mmcu=atmega32 -o "AnalogMuxV2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AnalogMuxV2.lss: AnalogMuxV2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AnalogMuxV2.elf  >"AnalogMuxV2.lss"
	@echo 'Finished building: $@'
	@echo ' '

AnalogMuxV2.hex: AnalogMuxV2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AnalogMuxV2.elf  "AnalogMuxV2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AnalogMuxV2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AnalogMuxV2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AnalogMuxV2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
