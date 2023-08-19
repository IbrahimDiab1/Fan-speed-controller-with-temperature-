################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Fan Controller
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Fan\ Controller.lss \

FLASH_IMAGE += \
Fan\ Controller.hex \

EEPROM_IMAGE += \
Fan\ Controller.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: main-build

# Main-build Target
main-build: Fan\ Controller.elf secondary-outputs

# Tool invocations
Fan\ Controller.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Fan Controller.map -mmcu=atmega16 -o "Fan Controller.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Fan\ Controller.lss: Fan\ Controller.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Fan Controller.elf  >"Fan Controller.lss"
	@echo 'Finished building: $@'
	@echo ' '

Fan\ Controller.hex: Fan\ Controller.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Fan Controller.elf  "Fan Controller.hex"
	@echo 'Finished building: $@'
	@echo ' '

Fan\ Controller.eep: Fan\ Controller.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Fan Controller.elf  "Fan Controller.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Fan\ Controller.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Fan Controller.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Fan\ Controller.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -Uflash:w:Fan Controller.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "Fan Controller.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
