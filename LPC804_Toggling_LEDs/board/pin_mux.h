/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor enabled. */
#define PIO0_11_MODE_PULL_UP 0x02u
/*!
 * @brief Open-drain mode.: Disable. */
#define PIO0_11_OD_DISABLE 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Pull-down.
 * Pull-down resistor enabled.
 */
#define PIO0_12_MODE_PULL_DOWN 0x01u
/*!
 * @brief Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor enabled. */
#define PIO0_13_MODE_PULL_UP 0x02u
/*!
 * @brief Open-drain mode.: Disable. */
#define PIO0_13_OD_DISABLE 0x00u

/*! @name PIO0_13 (number 4), S1/CN8[4]/CN6[4]/D2/M_PIO0_13/PIO0_13
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_RED_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_RED_GPIO_PIN_MASK (1U << 13U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LED_RED_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITPINS_LED_RED_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_RED_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO0_12 (number 5), S2/CN8[6]/CN6[5]/D3/M_PIO0_12/PIO0_12
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_S2_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_S2_GPIO_PIN_MASK (1U << 12U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_S2_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITPINS_S2_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_S2_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
                                                    /* @} */

/*! @name PIO0_11 (number 10), CN6[10]/CN8[3]/D4/PIO0_11/M_PIO0_11
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_BLUE_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_BLUE_GPIO_PIN_MASK (1U << 11U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LED_BLUE_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITPINS_LED_BLUE_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_BLUE_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_HYS_EN 0x20u      /*!<@brief Enable hysteresis */
#define IOCON_PIO_INV_DI 0x00u      /*!<@brief Input not invert */
#define IOCON_PIO_MODE_PULLUP 0x10u /*!<@brief Selects pull-up function */
#define IOCON_PIO_OD_DI 0x00u       /*!<@brief Disables Open-drain function */

/*! @name PIO0_11 (number 10), CN6[10]/CN8[3]/D4/PIO0_11/M_PIO0_11
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLEDSPINS_LED_BLUE_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_BLUE_GPIO_PIN_MASK (1U << 11U) /*!<@brief GPIO pin mask */
#define BOARD_INITLEDSPINS_LED_BLUE_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITLEDSPINS_LED_BLUE_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_INITLEDSPINS_LED_BLUE_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                              /* @} */

/*! @name PIO0_12 (number 5), S2/CN8[6]/CN6[5]/D3/M_PIO0_12/PIO0_12
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLEDSPINS_LED_GREEN_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_GREEN_GPIO_PIN_MASK (1U << 12U) /*!<@brief GPIO pin mask */
#define BOARD_INITLEDSPINS_LED_GREEN_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITLEDSPINS_LED_GREEN_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_INITLEDSPINS_LED_GREEN_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PIO0_13 (number 4), S1/CN8[4]/CN6[4]/D2/M_PIO0_13/PIO0_13
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLEDSPINS_LED_RED_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITLEDSPINS_LED_RED_GPIO_PIN_MASK (1U << 13U) /*!<@brief GPIO pin mask */
#define BOARD_INITLEDSPINS_LED_RED_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITLEDSPINS_LED_RED_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_INITLEDSPINS_LED_RED_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                             /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_HYS_EN 0x20u      /*!<@brief Enable hysteresis */
#define IOCON_PIO_INV_DI 0x00u      /*!<@brief Input not invert */
#define IOCON_PIO_MODE_PULLUP 0x10u /*!<@brief Selects pull-up function */
#define IOCON_PIO_OD_DI 0x00u       /*!<@brief Disables Open-drain function */

/*! @name PIO0_0 (number 22), CN7[3]/CN8[8]/JP2/PIO0_0
  @{ */
/*!
 * @brief PORT device index: 0 */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PORT 0U
/*!
 * @brief PORT pin number */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PIN 0U
/*!
 * @brief PORT pin mask */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PIN_MASK (1U << 0U)
/* @} */

/*! @name PIO0_4 (number 7), CN6[7]/CN8[7]/CN5[5]/JP24/PIO0_4
  @{ */
/*!
 * @brief PORT device index: 0 */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PORT 0U
/*!
 * @brief PORT pin number */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PIN 4U
/*!
 * @brief PORT pin mask */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PIN_MASK (1U << 4U)
/* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_HYS_EN 0x20u      /*!<@brief Enable hysteresis */
#define IOCON_PIO_INV_DI 0x00u      /*!<@brief Input not invert */
#define IOCON_PIO_MODE_PULLUP 0x10u /*!<@brief Selects pull-up function */
#define IOCON_PIO_OD_DI 0x00u       /*!<@brief Disables Open-drain function */

/*! @name SWCLK (number 8), CN6[8]/CN1[4]/U1[16]/SWCLK_PIO0_3
  @{ */
/*!
 * @brief PORT device index: 0 */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_PORT 0U
/*!
 * @brief PORT pin number */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_PIN 3U
/*!
 * @brief PORT pin mask */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDCLK_PIN_MASK (1U << 3U)
/* @} */

/*! @name SWDIO (number 9), CN6[9]/CN1[2]/U1[17]/SWDIO_PIO0_2
  @{ */
/*!
 * @brief PORT device index: 0 */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_PORT 0U
/*!
 * @brief PORT pin number */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_PIN 2U
/*!
 * @brief PORT pin mask */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_SWDIO_PIN_MASK (1U << 2U)
/* @} */

/*! @name RESETN (number 6), CN6[6]/CN1[10]/S3/CN4[3]/U1[3]/U1[8]/TRST_P0_5
  @{ */
/*!
 * @brief PORT device index: 0 */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_PORT 0U
/*!
 * @brief PORT pin number */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_PIN 5U
/*!
 * @brief PORT pin mask */
#define BOARD_INITSWD_DEBUGPINS_DEBUG_SWD_RESETN_PIN_MASK (1U << 5U)
/* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSWD_DEBUGPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_HYS_EN 0x20u      /*!<@brief Enable hysteresis */
#define IOCON_PIO_INV_DI 0x00u      /*!<@brief Input not invert */
#define IOCON_PIO_MODE_PULLUP 0x10u /*!<@brief Selects pull-up function */
#define IOCON_PIO_OD_DI 0x00u       /*!<@brief Disables Open-drain function */

/*! @name PIO0_14 (number 23), CN7[2]/CN3[1]/JP4/PIO0_14
  @{ */
#define BOARD_INITI2CPINS_I2C_SCL_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITI2CPINS_I2C_SCL_PIN 14U                   /*!<@brief PORT pin number */
#define BOARD_INITI2CPINS_I2C_SCL_PIN_MASK (1U << 14U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO0_7 (number 20), CN7[5]/CN3[2]/JP23/CN5[4]/PIO0_7
  @{ */
#define BOARD_INITI2CPINS_I2C_SDA_PORT 0U                  /*!<@brief PORT device index: 0 */
#define BOARD_INITI2CPINS_I2C_SDA_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITI2CPINS_I2C_SDA_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitI2CPins(void); /* Function assigned for the Cortex-M0P */

#define IOCON_PIO_HYS_EN 0x20u      /*!<@brief Enable hysteresis */
#define IOCON_PIO_INV_DI 0x00u      /*!<@brief Input not invert */
#define IOCON_PIO_MODE_PULLUP 0x10u /*!<@brief Selects pull-up function */
#define IOCON_PIO_OD_DI 0x00u       /*!<@brief Disables Open-drain function */

/*! @name PIO0_13 (number 4), S1/CN8[4]/CN6[4]/D2/M_PIO0_13/PIO0_13
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITBUTTONSPINS_S1_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITBUTTONSPINS_S1_GPIO_PIN_MASK (1U << 13U) /*!<@brief GPIO pin mask */
#define BOARD_INITBUTTONSPINS_S1_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITBUTTONSPINS_S1_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_INITBUTTONSPINS_S1_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*! @name PIO0_12 (number 5), S2/CN8[6]/CN6[5]/D3/M_PIO0_12/PIO0_12
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITBUTTONSPINS_S2_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITBUTTONSPINS_S2_GPIO_PIN_MASK (1U << 12U) /*!<@brief GPIO pin mask */
#define BOARD_INITBUTTONSPINS_S2_PORT 0U                   /*!<@brief PORT device index: 0 */
#define BOARD_INITBUTTONSPINS_S2_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_INITBUTTONSPINS_S2_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBUTTONsPins(void); /* Function assigned for the Cortex-M0P */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
