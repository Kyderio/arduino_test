/*
  Arduino.h - Main include file for the Arduino SDK
  Copyright (c) 2014 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Arduino_h
#define Arduino_h

/* Rename symbol PinMode into ArduinoPinMode for all the file Common.h
 * Functions using PinMode should be redeclared with the correct PinMode symbol */
#define PinMode ArduinoPinMode
#include "api/Common.h"
#include "api/ArduinoAPI.h"
#undef PinMode

#define AMEBA_ARDUINO_Pin_Mapping_Check
#ifdef Arduino_STD_PRINTF
#include <stdio.h>
#endif // Arduino_STD_PRINTF

#ifdef __cplusplus

using namespace arduino;

extern "C"{
#endif // __cplusplus

#define interrupts()   __enable_irq()
#define noInterrupts() __disable_irq()

extern uint32_t SystemCoreClock;
#define clockCyclesPerMicrosecond()     (SystemCoreClock / 1000000L)
#define clockCyclesToMicroseconds(a)    (((a) * 1000L) / (SystemCoreClock / 1000L))
#define microsecondsToClockCycles(a)    ((a) * (SystemCoreClock / 1000000L))

#define NOT_INITIAL                     (1UL<<0)
#define PIO_GPIO                        (1UL<<1)
#define PIO_PWM                         (1UL<<2)
#define PIO_I2C                         (1UL<<3)
#define PIO_ADC                         (1UL<<4)
#define PIO_DAC                         (1UL<<5)
#define PIO_GPIO_IRQ                    (1UL<<6)
#define PIO_IR                          (1UL<<7)
#define PIO_UART                        (1UL<<8)
#define PIO_SPI                         (1UL<<9)
#define PIO_CAN                         (1UL<<10)
#define PIO_LCDC                        (1UL<<11)

//#define TYPE_ANALOG                     (1UL<<7)
//#define TYPE_DIGITAL                    (1UL<<8)
#define TYPE_ANALOG                     (1UL<<21)
#define TYPE_DIGITAL                    (1UL<<22)

// Pin mode 
// bit0 ~ bit3       "GPIO mode"
// bit4 ~ bit7       "GPIO_IRQ mode"
#define PIN_MODE_MASK                   (0xF)
#define PIN_MODE_OFFSET                 (0)
#define PIN_IRQ_MASK                    (0xF0)
#define PIN_IRQ_OFFSET                  (0x4)
#define MODE_NOT_INITIAL                (1UL<<31)
#define PWM_MODE_ENABLED                (1UL<<30)
#define GPIO_MODE_ENABLED               (1UL<<29)
#define GPIO_IRQ_MODE_ENABLED           (1UL<<28)

/* Types used for the tables below */
typedef struct _PinDescription
{
    // HW PinNames
    uint32_t    pinname;
    // Current Pin Type
    uint32_t    ulPinType;
    // Supported Pin Function
    uint32_t    ulPinAttribute;
    // Current Pin Mode
    uint32_t    ulPinMode;
} PinDescription;

/* Pins table to be instantiated into variant.cpp */
extern PinDescription g_APinDescription[];

#ifdef __cplusplus
} // extern "C"
#endif

// Include board variant
#include "pins_arduino.h"
//#include "variant.h"
// ameba - arduino pin mapping function check
#include "amb_ard_pin_check.h"
#include "WInterrupts.h"
#include "wiring_digital.h"
#include "wiring_analog.h"

// ARM toolchain doesn't provide itoa etc, provide them
#include "api/itoa.h"

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif // abs

#define abs(x) ((x)>0?(x):-(x))


#ifdef __cplusplus
#include "LOGUARTClass.h"
#endif

#endif // Arduino_h
