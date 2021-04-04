/**
 * @file    LPC804_LED_Toggle_With_Sleep.c
 * @brief   Application entry point.
 */
/**** Includes ****/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC804.h"
#include "fsl_debug_console.h"
#include "time.h"
#include "fsl_pint.h"
#include "fsl_syscon_connections.h"
#include "fsl_ctimer.h"

/**** Define Macros ****/
#define ON						0U
#define OFF						1U
#define RED_LED					13U
#define SWITCH_2				12U
#define PORT_0					0U
#define GPIO_CLOCK				kCLOCK_Gpio0
#define GPIO_OUTPUT				1U
#define GPIO_INPUT				0U
#define PIN_INTERRUPT_PIN	 	kPINT_PinInt0
#define INTERRUPT_RISE_EDGE_STATE	kPINT_PinIntEnableRiseEdge
#define INTERRUPT_FALL_EDGE_STATE	kPINT_PinIntEnableFallEdge
#define match_value				10000000U
bool fsleep_mode = false;
bool fsleep_flag;
/**** Declare Functions ****/
void Init_Interrupt();
void Init_GPIO_Output(uint32_t);
void Init_GPIO_Input(uint32_t);
void Time_Delay(uint32_t);
void PIN_INTERRUPT_CALLBACK(pint_pin_int_t , uint32_t );
void Ctimer_Matchreg0_Callback();
void Ctimer_Interrupt_Init();
/**** Define Structures ****/
gpio_pin_config_t GPIO_OUTPUT_CONFIG = { GPIO_OUTPUT, OFF};
gpio_pin_config_t GPIO_INPUT_CONFIG = { GPIO_INPUT};
ctimer_callback_t ctimer_callback_table[] = {Ctimer_Matchreg0_Callback, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
ctimer_config_t ctimer0_config;
ctimer_match_config_t ctimer0_match_config = { match_value, true, true, kCTIMER_Output_NoAction, false, true};


/**** Define Functions ****/
void PIN_INTERRUPT_CALLBACK(pint_pin_int_t pintr, uint32_t pmatch_status)
{
	//Toggles RED_LED
	if(GPIO_PinRead(GPIO, PORT_0, RED_LED))
	GPIO_PinWrite(GPIO, PORT_0, RED_LED, ON);

	else
	GPIO_PinWrite(GPIO, PORT_0, RED_LED, OFF);
}
/* Initializes GPIO to Output mode, logic 0 */
void Init_GPIO_Output(uint32_t GPIO_PIN)
{
	GPIO_PinInit(GPIO, PORT_0, GPIO_PIN, &GPIO_OUTPUT_CONFIG);
}
/* Initalizes GPIO to Input mode */
void Init_GPIO_Input(uint32_t GPIO_PIN)
{
	GPIO_PinInit(GPIO, PORT_0, GPIO_PIN, &GPIO_INPUT_CONFIG);
}
/* Configures GPIO Interrupt for a specific pin at a specific state */
void Init_Interrupt(uint32_t PIN, uint32_t interrupt_state, uint32_t pint_interrupt_pin)
{
	uint32_t GpioPort0PinToPintsel = PIN + (PINTSEL_ID << SYSCON_SHIFT);
	// Attaching PINT peripheral to PIN
	SYSCON_AttachSignal(SYSCON, PIN_INTERRUPT_PIN, GpioPort0PinToPintsel);
	// Enable PIN Interrupt
	PINT_Init(PINT);
	// Configuring Callback Function
	PINT_PinInterruptConfig(PINT, pint_interrupt_pin, interrupt_state , PIN_INTERRUPT_CALLBACK);
	// Enabling Interrupt and Callback function
	PINT_EnableCallbackByIndex(PINT, pint_interrupt_pin);
}
/* Applys a time delay, pauses the code */
void Time_Delay(uint32_t ms)
{
	uint32_t i = 0;
	while(i < ms)
	{
		i++;
	}
}
/* Callback function for ctimer0 register 0
 * Puts the micro to sleep
 */
void Ctimer_Matchreg0_Callback()
{
	// Putting micro to sleep
		printf("Micro asleep /n");
		fsleep_mode = true;

}
/* Initializing and configuring ctimer0 */
void Ctimer_Interrupt_Init()
{
	CTIMER_GetDefaultConfig(&ctimer0_config);

	CTIMER_Init(CTIMER0, &ctimer0_config);

	CTIMER_RegisterCallBack(CTIMER0, ctimer_callback_table, kCTIMER_SingleCallback);

	CTIMER_SetupMatch(CTIMER0,	kCTIMER_Match_0, &ctimer0_match_config);

	CTIMER_StartTimer(CTIMER0);
}
int main(void)
{


	CLOCK_EnableClock(GPIO_CLOCK);
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    // Initialize GPIOs
    Init_GPIO_Input(SWITCH_2);
    Init_GPIO_Output(RED_LED);

    // Initialize Interrupt
    Init_Interrupt(SWITCH_2, INTERRUPT_RISE_EDGE_STATE, PIN_INTERRUPT_PIN);

    // Enables Ctimer0
    Ctimer_Interrupt_Init();


	while(1)
	{

		// Puts the micro to sleep, turns off RED_LED and restarts the timer on wakeup
		if(fsleep_mode)
		{
		GPIO_PinWrite(GPIO, PORT_0, RED_LED, OFF);
		POWER_EnterSleep();
		CTIMER_StartTimer(CTIMER0);
		fsleep_mode = false;
		}
	}
    return 0 ;
}
