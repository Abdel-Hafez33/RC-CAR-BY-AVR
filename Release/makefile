################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/GPIO/subdir.mk
-include HAL/ULTRASONIC_SENSOR/subdir.mk
-include HAL/MOTOR_DRIVER/subdir.mk
-include HAL/MOTOR/subdir.mk
-include HAL/IR\ SENSOR/subdir.mk
-include HAL/BLUETOOTH/subdir.mk
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
rc.lss \

FLASH_IMAGE += \
rc.hex \

EEPROM_IMAGE += \
rc.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: rc.elf secondary-outputs

# Tool invocations
rc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,rc.map -mmcu=atmega32 -o "rc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

rc.lss: rc.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S rc.elf  >"rc.lss"
	@echo 'Finished building: $@'
	@echo ' '

rc.hex: rc.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex rc.elf  "rc.hex"
	@echo 'Finished building: $@'
	@echo ' '

rc.eep: rc.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex rc.elf  "rc.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: rc.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 rc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) rc.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
