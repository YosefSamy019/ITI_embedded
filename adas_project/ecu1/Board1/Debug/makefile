################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/EXIT_interrupt/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO2/DIO/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Ultrasonic_Sensor/subdir.mk
-include HAL/Temp_sensor/subdir.mk
-include HAL/Servo_motor/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/Push_button/subdir.mk
-include HAL/Lighting_sensor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEY_PAD/subdir.mk
-include HAL/EXT_EEPROM/subdir.mk
-include HAL/DC_Motor/subdir.mk
-include HAL/Buzzer/subdir.mk
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
security_ECU.lss \

FLASH_IMAGE += \
security_ECU.hex \

EEPROM_IMAGE += \
security_ECU.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: security_ECU.elf secondary-outputs

# Tool invocations
security_ECU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,security_ECU.map -mmcu=atmega32 -o "security_ECU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

security_ECU.lss: security_ECU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S security_ECU.elf  >"security_ECU.lss"
	@echo 'Finished building: $@'
	@echo ' '

security_ECU.hex: security_ECU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex security_ECU.elf  "security_ECU.hex"
	@echo 'Finished building: $@'
	@echo ' '

security_ECU.eep: security_ECU.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex security_ECU.elf  "security_ECU.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: security_ECU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 security_ECU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) security_ECU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
