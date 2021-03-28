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
 * @file    LPC804_ctimer_LED_Toggle.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC804.h"
#include "fsl_debug_console.h"
#include "fsl_ctimer.h"


/* MACROS */
#define match_value 		10000000U		//1 sec switch time
#define OFF					0U
#define ON					1U
#define RED_LED				13U
#define GREEN_LED			12U
#define OUTPUT				1U
#define INPUT				0U
#define TRUE				1U
#define FALSE				0U
#define CTIMER0_MATCH0		kCTIMER_Match_0

/* Function Declaration */
void ctimer0_match0_callback();

/* Structs */

ctimer_callback_t ctimer_callback_table[] =										// Struct to define match register callback functions
		{ctimer0_match0_callback, NULL, NULL, NULL, NULL, NULL, NULL,NULL};
ctimer_config_t ctimer0_config;													// Struct to declare ctimer configuration. Use default config
ctimer_match_config_t ctimer0_match_config;										// Timer Match Configuration
gpio_pin_config_t OUTPUT_CONFIG = { OUTPUT, OFF};								// GPIO Configuration

/*******************************************************************************
 * Definitions
 ******************************************************************************/
// Configuring match configuration
void match_config_init (ctimer_match_config_t *matchConfig0)
 {
		matchConfig0->enableCounterReset = true;
	    matchConfig0->enableCounterStop  = false;
	    matchConfig0->matchValue         = match_value;
	    matchConfig0->outControl         = kCTIMER_Output_Toggle;
	    matchConfig0->outPinInitState    = false;
	    matchConfig0->enableInterrupt    = true;
 }

// configuring match callback
void ctimer0_match0_callback()
{

	if(!GPIO_PinRead(GPIO, 0, RED_LED))
	{
		GPIO_PinWrite(GPIO,0,RED_LED, ON);
		GPIO_PinWrite(GPIO,0,GREEN_LED, OFF);
	}
	else
	{
		GPIO_PinWrite(GPIO,0,RED_LED, OFF);
		GPIO_PinWrite(GPIO,0,GREEN_LED, ON);
	}
}

/* Initalizing GPIOs */
void gpio_init()
{
	CLOCK_EnableClock(kCLOCK_Gpio0);
	GPIO_PinInit(GPIO, 0, RED_LED, &OUTPUT_CONFIG);
	GPIO_PinInit(GPIO, 0, GREEN_LED, &OUTPUT_CONFIG);

}

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    // Initalizing GPIOs
    gpio_init();
    // Getting default timer configuration
    CTIMER_GetDefaultConfig(&ctimer0_config);
    //	Initalizing timer
    CTIMER_Init(CTIMER0, &ctimer0_config);
    // Updating match config
    match_config_init(&ctimer0_match_config);
    // Defining callback function for all channels
    CTIMER_RegisterCallBack(CTIMER0, &ctimer_callback_table[0], kCTIMER_MultipleCallback);
    // Setting up match
    CTIMER_SetupMatch(CTIMER0, CTIMER0_MATCH0 , &ctimer0_match_config);
    // Starting Timer
    CTIMER_StartTimer(CTIMER0);

   while(1)
   {

   }

    return 0 ;
}
