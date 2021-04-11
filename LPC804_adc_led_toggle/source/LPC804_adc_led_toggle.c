/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    LPC804_adc_led_toggle.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC804.h"
#include "fsl_debug_console.h"
#include "fsl_adc.h"
#include "fsl_power.h"
/* Define MACROS */
#define ON 					0U
#define OFF					1U
#define OUTPUT				1U
#define INPUT				0U
#define ADC_PERIPHERIAL		kPDRUNCFG_PD_ADC0
#define RED_LED				12U
#define GREEN_LED			13U
#define ADC_VALUE			2500
#define PORT0				0U
#define ADC_CHANNEL_7		7U
/* Define Structures */
adc_result_info_t result_config;
gpio_pin_config_t output_config =
		{ OUTPUT, OFF };

/* Define Functions */
void gpio_init_output(uint32_t);
void adc_config();
int main(void) {


  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    CLOCK_EnableClock(kCLOCK_Gpio0);

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();

    // Power Up ADC Peripherial
    POWER_DisablePD(ADC_PERIPHERIAL);

    // Configure ADC, Channel 7
    adc_config();

    // Init RED_LED, GREEN_LED
    gpio_init_output(RED_LED);
    gpio_init_output(GREEN_LED);




#endif


    while(1)
    {
    	// Enabling ADC Manually
    	ADC_DoSoftwareTriggerConvSeqA(ADC);

    	// Waiting for ADC to finish converting
    	while (!ADC_GetChannelConversionResult(ADC, 7U, &result_config))
    	{

    	}
    	// Getting ADC result
    	ADC_GetConvSeqAGlobalConversionResult(ADC, &result_config);

    	// Toggle LEDs based on ADC_VALUE
    	if(result_config.result >= ADC_VALUE && result_config.channelNumber == ADC_CHANNEL_7)
    	{
    		GPIO_PinWrite(GPIO, PORT0, RED_LED, ON);
    		GPIO_PinWrite(GPIO, PORT0, GREEN_LED, ON);
    	}
    	else
    	{
    		GPIO_PinWrite(GPIO, PORT0, RED_LED, OFF);
    		GPIO_PinWrite(GPIO, PORT0, GREEN_LED, OFF);
    	}
    }
    return 0 ;
}

void adc_config()
{
	adc_config_t adc_config_default;
	adc_conv_seq_config_t adcConvSeqConfigStruct;

	// Configure ADC clock divider. Clock divider = x + 1(Always plus one)
	adc_config_default.clockDividerNumber = 1U;
	// Disable low power mode. ADC will stay on when no conversions are happening.
	adc_config_default.enableLowPowerMode = 0U;

	// Configuring Conversion sequence
	adcConvSeqConfigStruct.channelMask = (1U << ADC_CHANNEL_7);
	adcConvSeqConfigStruct.enableSingleStep = false;
	adcConvSeqConfigStruct.enableSyncBypass = false;
	adcConvSeqConfigStruct.interruptMode = kADC_TriggerPolarityPositiveEdge;
	adcConvSeqConfigStruct.interruptMode = kADC_InterruptForEachSequence;

	// Initializing ADC
	ADC_Init(ADC, &adc_config_default);

	// Initializing Seq A
	ADC_SetConvSeqAConfig(ADC, &adcConvSeqConfigStruct);

	// Enabling Seq A
	ADC_EnableConvSeqA(ADC, true);

}

void gpio_init_output(uint32_t PIN)
{
	GPIO_PinInit(GPIO, PORT0, PIN, &output_config);
}
