################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LPC804_Interrupt_LED_Toggle.axf

# Tool invocations
LPC804_Interrupt_LED_Toggle.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="LPC804_Interrupt_LED_Toggle.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T LPC804_Interrupt_LED_Toggle_Debug.ld -o "LPC804_Interrupt_LED_Toggle.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) LPC804_Interrupt_LED_Toggle.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "LPC804_Interrupt_LED_Toggle.axf"; # arm-none-eabi-objcopy -v -O binary "LPC804_Interrupt_LED_Toggle.axf" "LPC804_Interrupt_LED_Toggle.bin" ; # checksum -p LPC804 -d "LPC804_Interrupt_LED_Toggle.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
