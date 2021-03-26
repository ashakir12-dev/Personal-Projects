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
 * @file    LPC804_Interrupt_LED_Toggle.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC804.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_pint.h"
#include "fsl_syscon.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

#define RED_LED				13U
#define SW2					14U
#define OUTPUT				1U
#define INPUT				0U
#define ON					0U
#define OFF					1U
#define _PINT_PIN_INT0_SRC kSYSCON_GpioPort0Pin12ToPintsel

gpio_pin_config_t OUTPUT_CONFIG = { OUTPUT , OFF};
gpio_pin_config_t INPUT_CONFIG = { INPUT , OFF};

/*
 * @brief   Application entry point.
 */
/* Interrupt Callback Function */
void pint_intr_callback(pint_pin_int_t pintr, uint32_t pmatch_status)
{
    GPIO_PinWrite(GPIO, 0U, RED_LED, ON);
    PINT_PinInterruptClrStatus(PINT, pintr);
}

void interrupt_init()
{
	/* Attach peripheral to Pin */
	SYSCON_AttachSignal(SYSCON, kPINT_PinInt0, _PINT_PIN_INT0_SRC);

	/* Initialize PINT Perph and Clock */
	PINT_Init(PINT);

	/* Configure PIN Interrupt with Callback */
    PINT_PinInterruptConfig(PINT, kPINT_PinInt0, kPINT_PinIntEnableBothEdges, pint_intr_callback);

    /*Enable interrupt callback */
    PINT_EnableCallbackByIndex(PINT, kPINT_PinInt0);
}
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    /* PIN INITIALIZATION */
    GPIO_PinInit(GPIO, 0U, RED_LED, &OUTPUT_CONFIG);
    interrupt_init();

    while(1)
    {
    	GPIO_PinWrite(GPIO, 0U, RED_LED, ON);
    }
    return 0 ;
}
