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

/* EV721FC0 (RTL8721FCM) */

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
    {PA_2,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM           | PIO_UART                                         , MODE_NOT_INITIAL}, // AMB_D0
    {PB_20, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM           | PIO_UART                               | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D1
    {PA_26, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                      | PIO_I2C           | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D2
    {PA_25, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                      | PIO_I2C           | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D3
    {PA_24, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D4
    {PA_23, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D5
    {PA_22, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D6
    {PA_21, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D7
    {PA_18, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM | PIO_ADC                                          | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D8
    {PA_19, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM | PIO_ADC                                          | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D9
    {PA_28, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D10
    {PA_15, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM | PIO_ADC                      | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D11
    {PA_16, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D12
    {PA_20, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM | PIO_ADC                                          | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D13
    {PA_14, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM | PIO_ADC                      | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D14
    {PA_17, TYPE_DIGITAL | TYPE_ANALOG, PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM | PIO_ADC                      | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D15
    {PA_5,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D16
    {PB_26, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D17
    {PA_4,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D18
    {PB_25, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D19
    {PA_27, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D20
    {PB_24, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D21
    {PB_23, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D22
    {PB_22, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D23
    {PB_14, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D24
    {PB_17, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                          | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D25
    {PB_21, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                                    | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D26
    {PA_3,  TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                          | PIO_CAN           , MODE_NOT_INITIAL}, // AMB_D27
    {PB_19, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                          | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D28
    {PB_15, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D29
    {PB_16, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D30
    {PB_18, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                          | PIO_CAN | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D31
    {PB_13, TYPE_DIGITAL,               PIO_GPIO | PIO_GPIO_IRQ | PIO_PWM                                | PIO_SPI           | PIO_LCDC, MODE_NOT_INITIAL}, // AMB_D32
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
