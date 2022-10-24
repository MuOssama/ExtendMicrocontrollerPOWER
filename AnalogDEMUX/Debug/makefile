################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/SERVO/subdir.mk
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
AnalogDEMUX.lss \

FLASH_IMAGE += \
AnalogDEMUX.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AnalogDEMUX.elf secondary-outputs

# Tool invocations
AnalogDEMUX.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AnalogDEMUX.map -mmcu=atmega32 -o "AnalogDEMUX.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AnalogDEMUX.lss: AnalogDEMUX.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AnalogDEMUX.elf  >"AnalogDEMUX.lss"
	@echo 'Finished building: $@'
	@echo ' '

AnalogDEMUX.hex: AnalogDEMUX.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AnalogDEMUX.elf  "AnalogDEMUX.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AnalogDEMUX.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AnalogDEMUX.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AnalogDEMUX.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
