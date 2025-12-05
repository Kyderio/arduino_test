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

#include "gpio_api.h"
//#include "pwmout_api.h"
#include "sys_api.h"

gpio_t *gpio_pin_struct[TOTAL_GPIO_PIN_NUM] = {NULL};

#define PinMode ArduinoPinMode
void pinMode(pin_size_t pinNumber, PinMode pinMode) {
    gpio_t *pGpio_t;

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

    // if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
    //     pinRemoveMode(pinNumber);
    // }

    if (((g_APinDescription[pinNumber].ulPinMode & GPIO_IRQ_MODE_ENABLED) == GPIO_IRQ_MODE_ENABLED) 
        && (pinMode == OUTPUT)) {
        // Pin mode changes from interrupt to output, input and interrupt can coexist
        pinRemoveInterrupt(pinNumber);
    }

    // if ((g_APinDescription[pinNumber].ulPinMode & MODE_NOT_INITIAL) == MODE_NOT_INITIAL) {
    if ((g_APinDescription[pinNumber].ulPinMode & GPIO_MODE_ENABLED) == 0) {
        pGpio_t = (gpio_t *)malloc(sizeof(gpio_t));
        if (pGpio_t == NULL) {
            printf("Allocate memory fail. \r\n");
            return;
        }
        memset(pGpio_t, 0, sizeof(gpio_t));
        gpio_pin_struct[pinNumber] = pGpio_t;
        gpio_init(pGpio_t, g_APinDescription[pinNumber].pinname);
    } else {
        pGpio_t = gpio_pin_struct[pinNumber];
    }

    switch (pinMode) {
        case INPUT:
            gpio_dir(pGpio_t, PIN_INPUT);
            gpio_mode(pGpio_t, PullDown);
            break;

        case OUTPUT:
            gpio_dir(pGpio_t, PIN_OUTPUT);
            gpio_mode(pGpio_t, PullNone);
            break;

        case INPUT_PULLUP:
            gpio_dir(pGpio_t, PIN_INPUT);
            gpio_mode(pGpio_t, PullUp);
            break;

        case INPUT_PULLDOWN:
            gpio_dir(pGpio_t, PIN_INPUT);
            gpio_mode(pGpio_t, PullDown);
            break;

        case OUTPUT_OPENDRAIN:
            //gpio_dir(pGpio_t, PIN_OUTPUT);
            //gpio_mode(pGpio_t, OpenDrain);
            break;

        // case INPUT_IRQ_FALL:
        //     gpio_irq_set((gpio_irq_t *)pGpio_t, IRQ_FALL, 1);
        //     gpio_irq_enable((gpio_irq_t *)pGpio_t);
        //     break;

        // case INPUT_IRQ_RISE:
        //     gpio_irq_set((gpio_irq_t *)pGpio_t, IRQ_RISE, 1);
        //     gpio_irq_enable((gpio_irq_t *)pGpio_t);
        //     break;

        // case INPUT_IRQ_LOW:
        //     gpio_irq_set((gpio_irq_t *)pGpio_t, IRQ_LOW, 1);
        //     gpio_irq_enable((gpio_irq_t *)pGpio_t);
        //     break;

        // case INPUT_IRQ_HIGH:
        //     gpio_irq_set((gpio_irq_t *)pGpio_t, IRQ_HIGH, 1);
        //     gpio_irq_enable((gpio_irq_t *)pGpio_t);
        //     break;

        // case INPUT_IRQ_CHANGE:
        //     gpio_irq_set((gpio_irq_t *)pGpio_t, IRQ_FALL_RISE, 1);
        //     gpio_irq_enable((gpio_irq_t *)pGpio_t);
        //     break;

        default:
            printf("Error Digital pin mode setup. \r\n");
            break;
    }
    g_APinDescription[pinNumber].ulPinMode &= ~(PIN_MODE_MASK | MODE_NOT_INITIAL);
    g_APinDescription[pinNumber].ulPinMode |= (pinMode << PIN_MODE_OFFSET) | GPIO_MODE_ENABLED;
}
#undef PinMode

void digitalWrite(pin_size_t pinNumber, PinStatus status) {
    gpio_t *pGpio_t;

    amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);
    // amb_ard_pin_check_fun(pinNumber, PIO_GPIO);

    // if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
    //     pinMode(pinNumber, (g_APinDescription[pinNumber].ulPinMode));
    // }

    pGpio_t = gpio_pin_struct[pinNumber];

    switch (status)
    {
        case LOW:
            gpio_write(pGpio_t, LOW);
            break;
        case HIGH:
            gpio_write(pGpio_t, HIGH);
            break;
        default:
            printf("Error pin status to write. \r\n");
            break;
    }
}

PinStatus digitalRead(pin_size_t pinNumber) {
    gpio_t *pGpio_t;
    int pin_status;

    amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);
    // amb_ard_pin_check_fun(pinNumber, PIO_GPIO);

    // if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED ) == PWM_MODE_ENABLED) {
    //     pinMode(pinNumber, (g_APinDescription[pinNumber].ulPinMode));
    // }

    pGpio_t = gpio_pin_struct[pinNumber];
    pin_status = gpio_read(pGpio_t);
    return (pin_status == 0)?LOW:HIGH;
}

// void digitalChangeDir(pin_size_t pinNumber, uint8_t direction) {
//     gpio_t *pGpio_t;
//     //u32 RegValue;

//     amb_ard_pin_check_type(pinNumber, TYPE_DIGITAL);
//     // amb_ard_pin_check_fun(pinNumber, PIO_GPIO);

//     if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED ) == PWM_MODE_ENABLED) {
//         pinMode(pinNumber, (g_APinDescription[pinNumber].ulPinMode));
//     }

//     pGpio_t = gpio_pin_struct[pinNumber];

//     gpio_dir(pGpio_t, direction);
// }

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
    // if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
    //     if ((g_APinDescription[pinNumber].ulPinAttribute & PIO_PWM) == PIO_PWM) {
    //         // The PWM pin can only be disabled
    //         pwmout_t *obj = (pwmout_t *)gpio_pin_struct[pinNumber];
    //         pwmout_free(obj);
    //         // free malloc
    //         free((pwmout_t *)gpio_pin_struct[pinNumber]);
    //         g_APinDescription[pinNumber].ulPinMode &= (~PWM_MODE_ENABLED);
    //     }
    // }
    if ((g_APinDescription[pinNumber].ulPinMode & GPIO_MODE_ENABLED) == GPIO_MODE_ENABLED) {
        if ((g_APinDescription[pinNumber].ulPinAttribute & PIO_GPIO) == PIO_GPIO) {
            //gpio_deinit(gpio_pin_struct[pinNumber], g_APinDescription[pinNumber].pinname);
            //gpio_t *gpio_obj = gpio_pin_struct[pinNumber];
            //gpio_deinit(gpio_obj);

            gpio_deinit(gpio_pin_struct[pinNumber]);
            free(gpio_pin_struct[pinNumber]);
            gpio_pin_struct[pinNumber] = NULL;
            g_APinDescription[pinNumber].ulPinMode &= (~GPIO_MODE_ENABLED);
        }
    }
    g_APinDescription[pinNumber].ulPinMode |= MODE_NOT_INITIAL;
}

#ifdef __cplusplus
}
#endif
