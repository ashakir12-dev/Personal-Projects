################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC804M101JDH24 -DCPU_LPC804M101JDH24_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\board" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\source" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\drivers" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\device" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\CMSIS" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\component\uart" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Interrupt_LED_Toggle\utilities" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


