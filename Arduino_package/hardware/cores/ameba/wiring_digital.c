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

#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "sys_api.h"

#ifdef __cplusplus
}
#endif

extern pwm_resource g_pwm_res[PWM_TIMER_NUM*PWM_INDEX_NUM];

#define PinMode ArduinoPinMode
void pinMode(pin_size_t pinNumber, PinMode pinMode) {
    amb_ard_pin_check_name(pinNumber);
    // amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);
    if ((pinMode != INPUT) && (pinMode != OUTPUT) && (pinMode != INPUT_PULLUP)
        && (pinMode != INPUT_PULLDOWN) && (pinMode != OUTPUT_OPENDRAIN)) {
        printf("Error Mode not supported. \r\n");
        return;
    }

    if (((g_APinDescription[pinNumber].ulPinMode & MODE_NOT_INITIAL) == 0)
        && ((g_APinDescription[pinNumber].ulPinMode & PIN_MODE_MASK) == pinMode)
        && ((g_APinDescription[pinNumber].ulPinMode & GPIO_MODE_ENABLED) == GPIO_MODE_ENABLED)) {
        // Nothing changes
        // printf("The pin mode is unchanged. \r\n");
        return;
    }

    // SWD_DATA, SWD_CLK
    if ((g_APinDescription[pinNumber].pinname == PA_18) || (g_APinDescription[pinNumber].pinname == PA_19)) {
        // If user needs to use SWD pins for GPIO, disable SWD debugging to free pins
        sys_jtag_off();
    }

    if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
        pinRemoveMode(pinNumber);
    }

    if (((g_APinDescription[pinNumber].ulPinMode & GPIO_IRQ_MODE_ENABLED) == GPIO_IRQ_MODE_ENABLED) 
        && (pinMode == OUTPUT)) {
        // Pin mode changes from interrupt to output, input and interrupt can coexist
        pinRemoveInterrupt(pinNumber);
    }

    // if ((g_APinDescription[pinNumber].ulPinMode & MODE_NOT_INITIAL) == MODE_NOT_INITIAL) {
    if ((g_APinDescription[pinNumber].ulPinMode & GPIO_MODE_ENABLED) == 0) {
        GPIO_InitTypeDef GPIO_InitStruct;

        /* Enable gpio clock and function */
        RCC_PeriphClockCmd(APBPeriph_GPIO, APBPeriph_GPIO_CLOCK, ENABLE);

        GPIO_InitStruct.GPIO_Pin = g_APinDescription[pinNumber].pinname;
        GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

        GPIO_Init(&GPIO_InitStruct);
    }

    switch (pinMode) {
        case INPUT:
            GPIO_Direction(g_APinDescription[pinNumber].pinname, GPIO_Mode_IN);
            PAD_PullCtrl(g_APinDescription[pinNumber].pinname, GPIO_PuPd_DOWN);
            break;

        case OUTPUT:
            GPIO_Direction(g_APinDescription[pinNumber].pinname, GPIO_Mode_OUT);
            PAD_PullCtrl(g_APinDescription[pinNumber].pinname, GPIO_PuPd_NOPULL);
            break;

        case INPUT_PULLUP:
            GPIO_Direction(g_APinDescription[pinNumber].pinname, GPIO_Mode_IN);
            PAD_PullCtrl(g_APinDescription[pinNumber].pinname, GPIO_PuPd_UP);
            break;

        case INPUT_PULLDOWN:
            GPIO_Direction(g_APinDescription[pinNumber].pinname, GPIO_Mode_IN);
            PAD_PullCtrl(g_APinDescription[pinNumber].pinname, GPIO_PuPd_DOWN);
            break;

        case OUTPUT_OPENDRAIN:
            GPIO_Direction(g_APinDescription[pinNumber].pinname, GPIO_Mode_OUT);
            PAD_PullCtrl(g_APinDescription[pinNumber].pinname, GPIO_PuPd_UP);
            break;

        default:
            printf("Error Digital pin mode setup. \r\n");
            break;
    }
    g_APinDescription[pinNumber].ulPinMode &= ~(PIN_MODE_MASK | MODE_NOT_INITIAL);
    g_APinDescription[pinNumber].ulPinMode |= (pinMode << PIN_MODE_OFFSET) | GPIO_MODE_ENABLED;
}
#undef PinMode

void digitalWrite(pin_size_t pinNumber, PinStatus status) {
    amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);
    // amb_ard_pin_check_fun(pinNumber, PIO_GPIO);

    if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
        pinMode(pinNumber, OUTPUT);
    }

    switch (status)
    {
        case LOW:
            GPIO_WriteBit(g_APinDescription[pinNumber].pinname, LOW);
            break;
        case HIGH:
            GPIO_WriteBit(g_APinDescription[pinNumber].pinname, HIGH);
            break;
        default:
            printf("Error pin status to write. \r\n");
            break;
    }
}

PinStatus digitalRead(pin_size_t pinNumber) {
    int pin_status;

    amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);
    // amb_ard_pin_check_fun(pinNumber, PIO_GPIO);

    if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED ) == PWM_MODE_ENABLED) {
        pinMode(pinNumber, INPUT);
    }

    pin_status = GPIO_ReadDataBit(g_APinDescription[pinNumber].pinname);
    return (pin_status == 0)?LOW:HIGH;
}

/**************************** Extend API by RTK ***********************************/
uint32_t digitalPinToPort(pin_size_t pinNumber) {
    uint32_t pin_name;

    amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);

    pin_name = g_APinDescription[pinNumber].pinname;
    return PORT_NUM(pin_name);
}

uint32_t digitalPinToBitMask(pin_size_t pinNumber) {
    uint32_t pin_name;

    amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);

    pin_name = (g_APinDescription[pinNumber].pinname);

    return (1 << PIN_NUM(pin_name));
}

void pinRemoveMode(pin_size_t pinNumber) {
    if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
        if ((g_APinDescription[pinNumber].ulPinAttribute & PIO_PWM) == PIO_PWM) {
            /* Find and disable pwm */
            for (int i = 0; i < PWM_TIMER_NUM*PWM_INDEX_NUM; i++) {
                if ((g_pwm_res[i].pin == pinNumber) && (g_pwm_res[i].alloc == true)) {
                    RTIM_CCxCmd(TIMx[g_pwm_res[i].pwmtimer_idx], g_pwm_res[i].pwm_idx, TIM_CCx_Disable);
                    RTIM_Cmd(TIMx[g_pwm_res[i].pwmtimer_idx], DISABLE);
                    RCC_PeriphClockCmd(APBPeriph_TIMx[g_pwm_res[i].pwmtimer_idx], APBPeriph_TIMx_CLOCK[g_pwm_res[i].pwmtimer_idx], DISABLE);
                    Pinmux_Config(g_APinDescription[pinNumber].pinname, PINMUX_FUNCTION_GPIO);

                    g_pwm_res[i].pin = TOTAL_GPIO_PIN_NUM;
                    g_pwm_res[i].alloc = false;
                    g_APinDescription[pinNumber].ulPinMode &= (~PWM_MODE_ENABLED);
                    break;
                }
            }
        }
    }
    if ((g_APinDescription[pinNumber].ulPinMode & GPIO_MODE_ENABLED) == GPIO_MODE_ENABLED) {
        if ((g_APinDescription[pinNumber].ulPinAttribute & PIO_GPIO) == PIO_GPIO) {
            GPIO_DeInit(g_APinDescription[pinNumber].pinname);
            g_APinDescription[pinNumber].ulPinMode &= (~GPIO_MODE_ENABLED);
        }
    }
    g_APinDescription[pinNumber].ulPinMode |= MODE_NOT_INITIAL;
}
