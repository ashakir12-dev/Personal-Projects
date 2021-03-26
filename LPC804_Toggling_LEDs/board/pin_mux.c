/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: LPC804
package_id: LPC804M101JDH24
mcu_data: ksdk2_0
processor_version: 8.0.2
board: LPCXpresso804
pin_labels:
- {pin_num: '10', pin_signal: PIO0_11/ADC_6/WKTCLKIN, label: 'CN6[10]/CN8[3]/D4/PIO0_11/M_PIO0_11', identifier: LED_BLUE}
- {pin_num: '5', pin_signal: PIO0_12, label: 'S2/CN8[6]/CN6[5]/D3/M_PIO0_12/PIO0_12', identifier: LED_GREEN;S2}
- {pin_num: '4', pin_signal: PIO0_13/ADC_10, label: 'S1/CN8[4]/CN6[4]/D2/M_PIO0_13/PIO0_13', identifier: LED_RED;S1}
- {pin_num: '22', pin_signal: PIO0_0/ACMP_I1, label: 'CN7[3]/CN8[8]/JP2/PIO0_0', identifier: DEBUG_UART_RX}
- {pin_num: '7', pin_signal: PIO0_4/ADC_11, label: 'CN6[7]/CN8[7]/CN5[5]/JP24/PIO0_4', identifier: DEBUG_UART_TX}
- {pin_num: '9', pin_signal: SWDIO/PIO0_2, label: 'CN6[9]/CN1[2]/U1[17]/SWDIO_PIO0_2', identifier: DEBUG_SWD_SWDIO}
- {pin_num: '8', pin_signal: SWCLK/PIO0_3, label: 'CN6[8]/CN1[4]/U1[16]/SWCLK_PIO0_3', identifier: DEBUG_SWD_SWDCLK}
- {pin_num: '23', pin_signal: PIO0_14/ACMP_I3/ADC_2, label: 'CN7[2]/CN3[1]/JP4/PIO0_14', identifier: I2C_SCL}
- {pin_num: '20', pin_signal: PIO0_7/ADC_1/ACMPVREF, label: 'CN7[5]/CN3[2]/JP23/CN5[4]/PIO0_7', identifier: I2C_SDA}
- {pin_num: '6', pin_signal: RESETN/PIO0_5, label: 'CN6[6]/CN1[10]/S3/CN4[3]/U1[3]/U1[8]/TRST_P0_5', identifier: DEBUG_SWD_RESETN}
- {pin_num: '1', pin_signal: PIO0_18, label: 'CN6[1]/CN3[9]/PIO0_18'}
- {pin_num: '2', pin_signal: PIO0_16/ACMP_I4/ADC_3, label: 'CN6[2]/CN5[2]/U4[1]/PIO0_16'}
- {pin_num: '3', pin_signal: PIO0_17/ADC_9, label: 'CN6[3]/CN5[3]/PIO0_17'}
- {pin_num: '11', pin_signal: PIO0_10/ADC_7, label: 'CN6[11]/VR1/CN5[1]/PIO0_10'}
- {pin_num: '12', pin_signal: PIO0_21/ACMP_I5, label: 'CN6[12]/CN8[5]/PIO0_21'}
- {pin_num: '13', pin_signal: PIO0_20, label: 'CN7[12]/CN3[10]/PIO0_20'}
- {pin_num: '14', pin_signal: PIO0_15/ADC_8, label: 'CN7[11]/CN3[8]/PIO0_15'}
- {pin_num: '15', pin_signal: PIO0_1/ADC_0/ACMP_I2/CLKIN, label: 'CN7[10]/CN3[5]/CN5[6]/U4[6]/PIO0_1'}
- {pin_num: '16', pin_signal: PIO0_9/ADC_4, label: 'CN7[9]/CN3[6]/R13/U4[2]/PIO0_9/ISP_U0_TXD_DS'}
- {pin_num: '17', pin_signal: PIO0_8/ADC_5, label: 'CN7[8]/CN3[7]/R20/U4[5]/PIO0_8/ISP_U0_RXD_DS'}
- {pin_num: '18', pin_signal: VDD, label: 'CN7[7]/JP5/R37/VDD'}
- {pin_num: '19', pin_signal: VSS, label: GND}
- {pin_num: '21', pin_signal: VREFP, label: 'CN7[4]/JP7/MCU_VREFP'}
- {pin_num: '24', pin_signal: PIO0_19/DACOUT, label: 'CN7[1]/CN8[2]/PIO0_19'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "fsl_swm.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '4', peripheral: GPIO, signal: 'PIO0, 13', pin_signal: PIO0_13/ADC_10, identifier: LED_RED, direction: OUTPUT, gpio_init_state: 'false', mode: pullUp,
    opendrain: disabled}
  - {pin_num: '5', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, identifier: S2, direction: INPUT, mode: pullDown}
  - {pin_num: '10', peripheral: GPIO, signal: 'PIO0, 11', pin_signal: PIO0_11/ADC_6/WKTCLKIN, direction: OUTPUT, gpio_init_state: 'false', mode: pullUp, opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_11 (pin 10)  */
    GPIO_PinInit(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_PORT, BOARD_INITPINS_LED_BLUE_PIN, &LED_BLUE_config);

    gpio_pin_config_t S2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin 5)  */
    GPIO_PinInit(BOARD_INITPINS_S2_GPIO, BOARD_INITPINS_S2_PORT, BOARD_INITPINS_S2_PIN, &S2_config);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_13 (pin 4)  */
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_LED_RED_PIN, &LED_RED_config);

    IOCON->PIO[7] = ((IOCON->PIO[7] &
                      /* Mask bits to zero which are setting */
                      (~(IOCON_PIO_MODE_MASK | IOCON_PIO_OD_MASK)))

                     /* Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor
                      * enabled. */
                     | IOCON_PIO_MODE(PIO0_11_MODE_PULL_UP)

                     /* Open-drain mode.: Disable. */
                     | IOCON_PIO_OD(PIO0_11_OD_DISABLE));

    IOCON->PIO[2] = ((IOCON->PIO[2] &
                      /* Mask bits to zero which are setting */
                      (~(IOCON_PIO_MODE_MASK)))

                     /* Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-down. Pull-down
                      * resistor enabled. */
                     | IOCON_PIO_MODE(PIO0_12_MODE_PULL_DOWN));

    IOCON->PIO[1] = ((IOCON->PIO[1] &
                      /* Mask bits to zero which are setting */
                      (~(IOCON_PIO_MODE_MASK | IOCON_PIO_OD_MASK)))

                     /* Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor
                      * enabled. */
                     | IOCON_PIO_MODE(PIO0_13_MODE_PULL_UP)

                     /* Open-drain mode.: Disable. */
                     | IOCON_PIO_OD(PIO0_13_OD_DISABLE));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '10', peripheral: GPIO, signal: 'PIO0, 11', pin_signal: PIO0_11/ADC_6/WKTCLKIN, direction: OUTPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
  - {pin_num: '5', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, identifier: LED_GREEN, direction: OUTPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
  - {pin_num: '4', peripheral: GPIO, signal: 'PIO0, 13', pin_signal: PIO0_13/ADC_10, identifier: LED_RED, direction: OUTPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitLEDsPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_11 (pin 10)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_BLUE_GPIO, BOARD_INITLEDSPINS_LED_BLUE_PORT, BOARD_INITLEDSPINS_LED_BLUE_PIN, &LED_BLUE_config);

    gpio_pin_config_t LED_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin 5)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_GREEN_GPIO, BOARD_INITLEDSPINS_LED_GREEN_PORT, BOARD_INITLEDSPINS_LED_GREEN_PIN, &LED_GREEN_config);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_13 (pin 4)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_RED_GPIO, BOARD_INITLEDSPINS_LED_RED_PORT, BOARD_INITLEDSPINS_LED_RED_PIN, &LED_RED_config);

    const uint32_t LED_BLUE = (/* Selects pull-up function */
                               IOCON_PIO_MODE_PULLUP |
                               /* Enable hysteresis */
                               IOCON_PIO_HYS_EN |
                               /* Input not invert */
                               IOCON_PIO_INV_DI |
                               /* Disables Open-drain function */
                               IOCON_PIO_OD_DI);
    /* PIO0 PIN11 (coords: 10) is configured as GPIO, PIO0, 11. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_11, LED_BLUE);

    const uint32_t LED_GREEN = (/* Selects pull-up function */
                                IOCON_PIO_MODE_PULLUP |
                                /* Enable hysteresis */
                                IOCON_PIO_HYS_EN |
                                /* Input not invert */
                                IOCON_PIO_INV_DI |
                                /* Disables Open-drain function */
                                IOCON_PIO_OD_DI);
    /* PIO0 PIN12 (coords: 5) is configured as GPIO, PIO0, 12. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_12, LED_GREEN);

    const uint32_t LED_RED = (/* Selects pull-up function */
                              IOCON_PIO_MODE_PULLUP |
                              /* Enable hysteresis */
                              IOCON_PIO_HYS_EN |
                              /* Input not invert */
                              IOCON_PIO_INV_DI |
                              /* Disables Open-drain function */
                              IOCON_PIO_OD_DI);
    /* PIO0 PIN13 (coords: 4) is configured as GPIO, PIO0, 13. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_13, LED_RED);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '22', peripheral: USART0, signal: RXD, pin_signal: PIO0_0/ACMP_I1, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
  - {pin_num: '7', peripheral: USART0, signal: TXD, pin_signal: PIO0_4/ADC_11, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitDEBUG_UARTPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t DEBUG_UART_RX = (/* Selects pull-up function */
                                    IOCON_PIO_MODE_PULLUP |
                                    /* Enable hysteresis */
                                    IOCON_PIO_HYS_EN |
                                    /* Input not invert */
                                    IOCON_PIO_INV_DI |
                                    /* Disables Open-drain function */
                                    IOCON_PIO_OD_DI);
    /* PIO0 PIN0 (coords: 22) is configured as USART0, RXD. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_0, DEBUG_UART_RX);

    const uint32_t DEBUG_UART_TX = (/* Selects pull-up function */
                                    IOCON_PIO_MODE_PULLUP |
                                    /* Enable hysteresis */
                                    IOCON_PIO_HYS_EN |
                                    /* Input not invert */
                                    IOCON_PIO_INV_DI |
                                    /* Disables Open-drain function */
                                    IOCON_PIO_OD_DI);
    /* PIO0 PIN4 (coords: 7) is configured as USART0, TXD. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_4, DEBUG_UART_TX);

    /* USART0_TXD connect to P0_4 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_TXD, kSWM_PortPin_P0_4);

    /* USART0_RXD connect to P0_0 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_RXD, kSWM_PortPin_P0_0);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitSWD_DEBUGPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '8', peripheral: SWD, signal: SWCLK, pin_signal: SWCLK/PIO0_3, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
  - {pin_num: '9', peripheral: SWD, signal: SWDIO, pin_signal: SWDIO/PIO0_2, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
  - {pin_num: '6', peripheral: SYSCON, signal: RESETN, pin_signal: RESETN/PIO0_5, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitSWD_DEBUGPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitSWD_DEBUGPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t DEBUG_SWD_SWDIO = (/* Selects pull-up function */
                                      IOCON_PIO_MODE_PULLUP |
                                      /* Enable hysteresis */
                                      IOCON_PIO_HYS_EN |
                                      /* Input not invert */
                                      IOCON_PIO_INV_DI |
                                      /* Disables Open-drain function */
                                      IOCON_PIO_OD_DI);
    /* PIO0 PIN2 (coords: 9) is configured as SWD, SWDIO. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_2, DEBUG_SWD_SWDIO);

    const uint32_t DEBUG_SWD_SWDCLK = (/* Selects pull-up function */
                                       IOCON_PIO_MODE_PULLUP |
                                       /* Enable hysteresis */
                                       IOCON_PIO_HYS_EN |
                                       /* Input not invert */
                                       IOCON_PIO_INV_DI |
                                       /* Disables Open-drain function */
                                       IOCON_PIO_OD_DI);
    /* PIO0 PIN3 (coords: 8) is configured as SWD, SWCLK. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_3, DEBUG_SWD_SWDCLK);

    const uint32_t DEBUG_SWD_RESETN = (/* Selects pull-up function */
                                       IOCON_PIO_MODE_PULLUP |
                                       /* Enable hysteresis */
                                       IOCON_PIO_HYS_EN |
                                       /* Input not invert */
                                       IOCON_PIO_INV_DI |
                                       /* Disables Open-drain function */
                                       IOCON_PIO_OD_DI);
    /* PIO0 PIN5 (coords: 6) is configured as SYSCON, RESETN. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_5, DEBUG_SWD_RESETN);

    /* SWCLK connect to P0_3 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWCLK, true);

    /* SWDIO connect to P0_2 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWDIO, true);

    /* RESETN connect to P0_5 */
    SWM_SetFixedPinSelect(SWM0, kSWM_RESETN, true);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitI2CPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: I2C0, signal: SCL, pin_signal: PIO0_14/ACMP_I3/ADC_2, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
  - {pin_num: '20', peripheral: I2C0, signal: SDA, pin_signal: PIO0_7/ADC_1/ACMPVREF, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitI2CPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitI2CPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t I2C_SCL = (/* Selects pull-up function */
                              IOCON_PIO_MODE_PULLUP |
                              /* Enable hysteresis */
                              IOCON_PIO_HYS_EN |
                              /* Input not invert */
                              IOCON_PIO_INV_DI |
                              /* Disables Open-drain function */
                              IOCON_PIO_OD_DI);
    /* PIO0 PIN14 (coords: 23) is configured as I2C0, SCL. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_14, I2C_SCL);

    const uint32_t I2C_SDA = (/* Selects pull-up function */
                              IOCON_PIO_MODE_PULLUP |
                              /* Enable hysteresis */
                              IOCON_PIO_HYS_EN |
                              /* Input not invert */
                              IOCON_PIO_INV_DI |
                              /* Disables Open-drain function */
                              IOCON_PIO_OD_DI);
    /* PIO0 PIN7 (coords: 20) is configured as I2C0, SDA. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_7, I2C_SDA);

    /* I2C0_SDA connect to P0_7 */
    SWM_SetMovablePinSelect(SWM0, kSWM_I2C0_SDA, kSWM_PortPin_P0_7);

    /* I2C0_SCL connect to P0_14 */
    SWM_SetMovablePinSelect(SWM0, kSWM_I2C0_SCL, kSWM_PortPin_P0_14);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '4', peripheral: GPIO, signal: 'PIO0, 13', pin_signal: PIO0_13/ADC_10, identifier: S1, direction: INPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
  - {pin_num: '5', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, identifier: S2, direction: INPUT, mode: pullUp, invert: disabled, hysteresis: enabled,
    opendrain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitBUTTONsPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t S2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin 5)  */
    GPIO_PinInit(BOARD_INITBUTTONSPINS_S2_GPIO, BOARD_INITBUTTONSPINS_S2_PORT, BOARD_INITBUTTONSPINS_S2_PIN, &S2_config);

    gpio_pin_config_t S1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_13 (pin 4)  */
    GPIO_PinInit(BOARD_INITBUTTONSPINS_S1_GPIO, BOARD_INITBUTTONSPINS_S1_PORT, BOARD_INITBUTTONSPINS_S1_PIN, &S1_config);

    const uint32_t S2 = (/* Selects pull-up function */
                         IOCON_PIO_MODE_PULLUP |
                         /* Enable hysteresis */
                         IOCON_PIO_HYS_EN |
                         /* Input not invert */
                         IOCON_PIO_INV_DI |
                         /* Disables Open-drain function */
                         IOCON_PIO_OD_DI);
    /* PIO0 PIN12 (coords: 5) is configured as GPIO, PIO0, 12. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_12, S2);

    const uint32_t S1 = (/* Selects pull-up function */
                         IOCON_PIO_MODE_PULLUP |
                         /* Enable hysteresis */
                         IOCON_PIO_HYS_EN |
                         /* Input not invert */
                         IOCON_PIO_INV_DI |
                         /* Disables Open-drain function */
                         IOCON_PIO_OD_DI);
    /* PIO0 PIN13 (coords: 4) is configured as GPIO, PIO0, 13. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_13, S1);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
