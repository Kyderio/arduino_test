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

/* EV721FL0 (RTL8721FLM) */

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

//#include "PinNames.h"

/*
 * Pins descriptions
 */
PinDescription g_APinDescription[TOTAL_GPIO_PIN_NUM]=
{
    {PA_2,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ           | PIO_UART                                         , MODE_NOT_INITIAL}, // AMB_D0 
    {PB_20, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ           | PIO_UART                                         , MODE_NOT_INITIAL}, // AMB_D1 
    {PA_22, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                      | PIO_I2C                     | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D2 
    {PA_23, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                      | PIO_I2C                     | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D3 
    {PA_25, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D4 
    {PA_24, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D5 
    {PA_29, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D6 
    {PA_26, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D7 
    {PB_4,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D8 
    {PB_3,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D9 
    {PB_5,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D10
    {PB_6,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D11
    {PB_7,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D12
    {PB_8,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D13
    {PB_9,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D14
    {PB_10, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D15
    {PB_11, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D16
    {PB_16, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D17
    {PB_23, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D18
    {PB_22, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D19
    {PB_14, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D20
    {PB_12, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D21
    {PB_17, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D22
    {PB_15, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D23
    {PB_18, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D24
    {PB_21, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D25
    {PA_6,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                          | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D26
    {PA_7,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                          | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D27
    {PA_8,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D28
    {PA_10, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D29
    {PA_11, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D30
    {PA_9,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D31
    {PA_17, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                      | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D32
    {PA_16, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D33
    {PA_13, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D34
    {PB_13, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                      | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D35
    {PA_14, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                      | PIO_SPI | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D36
    {PA_15, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                      | PIO_SPI | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D37
    {PC_0,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D38
    {PC_1,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D39
    {PB_30, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D40
    {PB_31, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D41
    {PB_28, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D42
    {PB_29, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D43
    {PB_26, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D44
    {PB_27, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D45
    {PB_24, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D46
    {PB_25, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D47
    {PA_4,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D48
    {PA_3,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D49
    {PB_0,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D50
    {PA_31, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D51
    {PA_30, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D52
    {PA_27, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D53
    {PA_21, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D54
    {PA_28, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D55
    {PA_20, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                                                    , MODE_NOT_INITIAL}, // AMB_D56
    {PA_5,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D57
    {PA_18, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                                | PIO_CAN           , MODE_NOT_INITIAL}, // AMB_D58
    {PA_19, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_ADC                                                    , MODE_NOT_INITIAL}, // AMB_D59
    {PB_19, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ                                                              , MODE_NOT_INITIAL}, // AMB_D60
};

#ifdef __cplusplus
} // extern C
#endif

void serialEvent() __attribute__((weak));
bool Serial_available() __attribute__((weak));

// ----------------------------------------------------------------------------

void serialEventRun(void)
{
    if (Serial_available && serialEvent && Serial_available()) serialEvent();
}

void init(void)
{

}

// ----------------------------------------------------------------------------

void wait_for_debug(void) {
    while (((CoreDebug->DHCSR) & CoreDebug_DHCSR_C_DEBUGEN_Msk) == 0) {
        asm("nop");
    }
    delay(1000);
}
