################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/LPC804_Project_Practice.c \
../source/semihost_hardfault.c 

OBJS += \
./source/LPC804_Project_Practice.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/LPC804_Project_Practice.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC804M101JDH24 -DCPU_LPC804M101JDH24_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\board" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\source" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\drivers" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\device" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\CMSIS" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\component\uart" -I"C:\Users\battl\Documents\MCUXpressoIDE_11.2.1_4149\workspace\LPC804_Project_Practice\utilities" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

