/*
 * Copyright 2016-2020 NXP
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
 * @file    LPC804_Project_Practice.c
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

/* TODO: insert other definitions and declarations here. */
#define RED_LED				13U
#define BLUE_LED			11U
#define SW2					12U
#define DI_OUT				1U
#define DI_IN				0U
#define ON					0U
#define OFF					1U
#define P0					0U
#define SW2_STATUS			GPIO_PinRead(GPIO,P0,SW2)
gpio_pin_config_t OUT_CONFIG_OFF = {  1U , 1U };
gpio_pin_config_t OUT_CONFIG_ON = {  1U , 0U };
gpio_pin_config_t IN_CONFIG = { 0U, 0U };


int main(void) {

	bool status;
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

	/* Init GPIOs for output and input */
	GPIO_PinInit(GPIO,P0,RED_LED,&OUT_CONFIG_OFF);
	GPIO_PinInit(GPIO,P0,BLUE_LED,&OUT_CONFIG_OFF);
	GPIO_PinInit(GPIO,P0,SW2,&IN_CONFIG);

	/* Toggling LEDs using SW2  */
    while(1)
    {
    	 status = GPIO_PinRead(GPIO,P0,SW2);
    	if(!SW2_STATUS)
    	{
    		GPIO_PinWrite(GPIO,P0,RED_LED,ON);
    		GPIO_PinWrite(GPIO,P0,BLUE_LED,ON);

    	}
    	else
    	{
    		GPIO_PinWrite(GPIO,P0,RED_LED,OFF);
    		GPIO_PinWrite(GPIO,P0,BLUE_LED,OFF);

    	}
    }



    return 0 ;
}
