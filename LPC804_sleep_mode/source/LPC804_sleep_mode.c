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
 * @file    LPC804_sleep_mode.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC804.h"
#include "fsl_debug_console.h"

/* TODO: insert other include files here. */
#include "fsl_pint.h"
#include "fsl_syscon.h"
#include "fsl_power.h"

/* TODO: insert other definitions and declarations here. */
#define RED_LED 		13U
#define ON				0U
#define OFF				1U
#define PINT0			kPINT_PinInt0
#define PORT0			0U
#define _PINT_PIN_INT0_SRC kSYSCON_GpioPort0Pin12ToPintsel
/*
 * @brief   This application is to practice putting a Micro to sleep mode \
 * and using an interrupt to wake up the micro from sleep
 */

gpio_pin_config_t output_config = { 1U,1U};

/* Callback function for Pin 12 Interrupt to wake up micro */
void pint0_callback(pint_pin_int_t pintr, uint32_t pmatch_status)
{
	// Turn on RED_LED
	GPIO_PinWrite(GPIO,PORT0,RED_LED,ON);
	// Clear Interrupt Flag
    PINT_PinInterruptClrStatus(PINT, pintr);
}

/* Function to initialize RED_LED */
void INIT_RedLed()
{
	CLOCK_EnableClock(kCLOCK_Gpio0);
	GPIO_PinInit(GPIO, PORT0, RED_LED, &output_config);
}

/* Function to initialize SW2 interrupt to waker up Micro */
void INIT_SW2Interrupt()
{
	// Attach PINT0 to Pin12
	SYSCON_AttachSignal(SYSCON, PINT0, _PINT_PIN_INT0_SRC);
	// Enable PIN Interrupt
	PINT_Init(PINT);
	// Configurate PIN12 Interrupt for Rising edge
	PINT_PinInterruptConfig(PINT, PINT0, kPINT_PinIntEnableRiseEdge, pint0_callback);
	// Enable callback function
	PINT_EnableCallbackByIndex(PINT, PINT0);
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
    // Initialize RED_LED & SW2 Interrupt
    INIT_RedLed();
    INIT_SW2Interrupt();

    // ENTER SLEEP MODE
    POWER_EnterSleep();

    while(1)
	{

	GPIO_PinWrite(GPIO,0U,RED_LED,1U);
	printf("Micro Awake \n");

	}
    return 0 ;
}
