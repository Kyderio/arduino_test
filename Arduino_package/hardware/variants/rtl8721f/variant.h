/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* AMBGreen2 (RTL8721FCM) */

#ifndef _VARIANT_ARDUINO_AMEBA_
#define _VARIANT_ARDUINO_AMEBA_

#include "Arduino.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C"{
#include "PinNames.h"

// #define portOutputRegister(P) ((volatile uint32_t *)(0x40811000 + (P) * 0x400))
// #define portInputRegister(P)  ((volatile uint32_t *)(0x40811050 + (P) * 0x400))
// #define portModeRegister(P)   ((volatile uint32_t *)(0x40811004 + (P) * 0x400))

/*
 * Wait until enter debug mode
 *
 * Check DHCSR(0xE000EDF0) register and hold until bit C_DEBUGEN is set.
 * Use this function along with J-LINK or other debug tool
 **/
extern void wait_for_debug(void);
}
#endif

#define MAIN_THREAD_STACK_SIZE                  (4096 * 4)

#define TOTAL_GPIO_PIN_NUM                      (33)
//#define TOTAL_PWM_PIN_NUM                       (13)

#define digitalPinToInterrupt(p)    (((p)<TOTAL_GPIO_PIN_NUM)?(p):-1)
#define interruptToDigitalPin(i)    (((i)<TOTAL_GPIO_PIN_NUM)?(i):-1)

/* Digital pin mapping refer to g_APinDescription */
#define AMB_D0                                  0  // PA_2
#define AMB_D1                                  1  // PB_20
#define AMB_D2                                  2  // PA_26
#define AMB_D3                                  3  // PA_25
#define AMB_D4                                  4  // PA_24
#define AMB_D5                                  5  // PA_23
#define AMB_D6                                  6  // PA_22
#define AMB_D7                                  7  // PA_21
#define AMB_D8                                  8  // PA_18
#define AMB_D9                                  9  // PA_19
#define AMB_D10                                 10 // PA_28
#define AMB_D11                                 11 // PA_15
#define AMB_D12                                 12 // PA_16
#define AMB_D13                                 13 // PA_20
#define AMB_D14                                 14 // PA_14
#define AMB_D15                                 15 // PA_17
#define AMB_D16                                 16 // PA_5
#define AMB_D17                                 17 // PB_26
#define AMB_D18                                 18 // PA_4
#define AMB_D19                                 19 // PB_25
#define AMB_D20                                 20 // PA_27
#define AMB_D21                                 21 // PB_24
#define AMB_D22                                 22 // PB_23
#define AMB_D23                                 23 // PB_22
#define AMB_D24                                 24 // PB_14
#define AMB_D25                                 25 // PB_17
#define AMB_D26                                 26 // PB_21
#define AMB_D27                                 27 // PA_3
#define AMB_D28                                 28 // PB_19
#define AMB_D29                                 29 // PB_15
#define AMB_D30                                 30 // PB_16
#define AMB_D31                                 31 // PB_18
#define AMB_D32                                 32 // PB_13

/* Analog pin mapping */
#define A0                                      AMB_D13 // PA_20    3.3V    CH0
#define A1                                      AMB_D9  // PA_19    3.3V    CH1
#define A2                                      AMB_D8  // PA_18    3.3V    CH2
#define A3                                      AMB_D15 // PA_17    3.3V    CH3
#define A4                                      AMB_D11 // PA_15    3.3V    CH4
#define A5                                      AMB_D14 // PA_14    3.3V    CH5

/* LED pin mapping */
#define LED_BUILTIN                             AMB_D5

/* ADC/DAC pin mapping */
//#define FEATURE_ADC
//#define FEATURE_DAC

/* SPI pin mapping */
#define SPI_COPI                                AMB_D11
#define SPI_CIPO                                AMB_D12
#define SPI_SCK                                 AMB_D14
#define SPI_CS                                  AMB_D15
#define SPI1_COPI                               AMB_D24
#define SPI1_CIPO                               AMB_D29
#define SPI1_SCK                                AMB_D30
#define SPI1_CS                                 AMB_D32

/* TwoWire/I2C pin mapping */
#define I2C_SDA                                 AMB_D2
#define I2C_SCL                                 AMB_D3
//#define I2C1_SDA                                AMB_D23 // AMB_D23
//#define I2C1_SCL                                AMB_D24 // AMB_D24

/* IR Device pin mapping */
//#define IR_TX                                   AMB_D9 // AMB_D9 / AMB_D16 / AMB_D3
//#define IR_RX                                   AMB_D8 // AMB_D8 / AMB_D17 / AMB_D6

/* UART pin mapping */
// #define LOG_UART_MODIFIABLE_BAUD_RATE           1
#define SERIAL_ONE_UART_MODIFIABLE_BAUD_RATE    1
#define SERIAL_TWO_UART_MODIFIABLE_BAUD_RATE    1
#define LOG_TX                                  AMB_D1 // UART_LOG_TX   AMB_D1
#define LOG_RX                                  AMB_D0 // UART_LOG_RX   AMB_D0
//#define SERIAL1_TX                              AMB_D26 // HS_UART0_TX   AMB_D26 / AMB_D12
//#define SERIAL1_RX                              AMB_D25 // HS_UART0_RX   AMB_D25 / AMB_D11
//#define SERIAL1_RTS                             AMB_D24 // HS_UART0_RTS  AMB_D24 / AMB_D10
//#define SERIAL1_CTS                             AMB_D23 // HS_UART0_CTS  AMB_D23 / AMB_D13
//#define SERIAL2_TX                              AMB_D17 // LP_UART_TX    AMB_D17 / AMB_D1
//#define SERIAL2_RX                              AMB_D16 // LP_UART_RX    AMB_D16 / AMB_D0

/* SWD pin mapping */
//#define SWD_DATA                                AMB_D9
//#define SWD_CLK                                 AMB_D8

#endif /* _VARIANT_ARDUINO_AMEBA_ */
