/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

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
#include "gpio_irq_api.h"

//gpio_irq_t *gpio_irq_pin_struct[TOTAL_GPIO_PIN_NUM] = {NULL};
gpio_irq_t *gpio_irq_pin_struct[TOTAL_GPIO_PIN_NUM];
voidFuncPtr gpio_irq_handler_list[TOTAL_GPIO_PIN_NUM] = {NULL};

static void gpioIrqHandler(uint32_t id, gpio_irq_event event) {
    if (gpio_irq_handler_list[id] != NULL) {
        gpio_irq_handler_list[id]();
    }
}

void attachInterrupt(pin_size_t interruptNumber, voidFuncPtr callback, PinStatus mode) {
    gpio_irq_t *pGpio_irq_t;
    //if (g_APinDescription[pin].ulPinType != PIO_GPIO_IRQ) {
    // if ((g_APinDescription[interruptNumber].ulPinMode & GPIO_IRQ_MODE_ENABLED) == 0) {
    //    pinRemoveMode(interruptNumber);
    //}
    amb_ard_pin_check_name(interruptNumber);
    // amb_ard_pin_check_type(interruptNumber, TYPE_DIGITAL);
    if ((mode != LOW) && (mode != HIGH) && (mode != CHANGE) && (mode != FALLING)
        && (mode != RISING)) {
        printf("Error Mode not supported. \r\n");
        return;
    }

    if (((g_APinDescription[interruptNumber].ulPinMode & MODE_NOT_INITIAL) == 0)
        && ((g_APinDescription[interruptNumber].ulPinMode & PIN_IRQ_MASK) == mode)
        && ((g_APinDescription[interruptNumber].ulPinMode & GPIO_IRQ_MODE_ENABLED) == GPIO_MODE_ENABLED)
        && gpio_irq_handler_list[interruptNumber] == callback) {
        // Nothing changes
        printf("The pin mode is unchanged. \r\n");
        return;
    }

    // SWD_DATA, SWD_CLK
    if ((g_APinDescription[interruptNumber].pinname == PA_18) || (g_APinDescription[interruptNumber].pinname == PA_19)) {
        // If user needs to use SWD pins for GPIO, disable SWD debugging to free pins
        sys_jtag_off();
    }

    // if ((g_APinDescription[interruptNumber].ulPinMode & PWM_MODE_ENABLED) == PWM_MODE_ENABLED) {
    //     pinRemoveMode(interruptNumber);
    // }

    if (((g_APinDescription[interruptNumber].ulPinMode & GPIO_MODE_ENABLED) == GPIO_MODE_ENABLED) && 
            ((g_APinDescription[interruptNumber].ulPinMode & PIN_MODE_MASK) == (OUTPUT << PIN_MODE_OFFSET))) {
        // Pin mode changes from output to interrupt, input and interrupt can coexist
        pinRemoveMode(interruptNumber);
    }

    if ((g_APinDescription[interruptNumber].ulPinMode & GPIO_IRQ_MODE_ENABLED) == 0) {
        pGpio_irq_t = (gpio_irq_t *)malloc(sizeof(gpio_irq_t));
        if (pGpio_irq_t == NULL) {
            printf("Allocate memory fail. \r\n");
            return;
        }
        memset(pGpio_irq_t, 0, sizeof(gpio_irq_t));
        gpio_irq_pin_struct[interruptNumber] = pGpio_irq_t;
        gpio_irq_init(pGpio_irq_t, g_APinDescription[interruptNumber].pinname, gpioIrqHandler, interruptNumber);
    } else {
        pGpio_irq_t = gpio_irq_pin_struct[interruptNumber];
    }

    switch(mode) {
        case LOW:
            digitalSetIrqHandler(interruptNumber, callback);
            gpio_irq_set(pGpio_irq_t, IRQ_LOW, 1);
            gpio_irq_enable(pGpio_irq_t);
            break;

        case HIGH:
            digitalSetIrqHandler(interruptNumber, callback);
            gpio_irq_set(pGpio_irq_t, IRQ_HIGH, 1);
            gpio_irq_enable(pGpio_irq_t);
            break;

        case CHANGE:
            digitalSetIrqHandler(interruptNumber, callback);
            gpio_irq_set(pGpio_irq_t, IRQ_FALL_RISE, 1);
            gpio_irq_enable(pGpio_irq_t);
            break;
    
        case FALLING:
            digitalSetIrqHandler(interruptNumber, callback);
            gpio_irq_set(pGpio_irq_t, IRQ_FALL, 1);
            gpio_irq_enable(pGpio_irq_t);
            break;

        case RISING:
            digitalSetIrqHandler(interruptNumber, callback);
            gpio_irq_set(pGpio_irq_t, IRQ_RISE, 1);
            gpio_irq_enable(pGpio_irq_t);
            break;

        default:
            break;
    }

    g_APinDescription[interruptNumber].ulPinMode &= ~(PIN_IRQ_MASK | MODE_NOT_INITIAL);
    g_APinDescription[interruptNumber].ulPinMode |= (mode << PIN_IRQ_OFFSET) | GPIO_IRQ_MODE_ENABLED;
}

void detachInterrupt(pin_size_t interruptNumber) {
    if (g_APinDescription[interruptNumber].ulPinType == PIO_GPIO_IRQ) {
        digitalClearIrqHandler(interruptNumber);
        pinRemoveInterrupt(interruptNumber);
    }
}

/**************************** Extend API by RTK ***********************************/
uint32_t digitalSetIrqHandler(pin_size_t interruptNumber, voidFuncPtr callback) {
    gpio_irq_handler_list[interruptNumber] = callback;
    return 0;
}

uint32_t digitalClearIrqHandler(pin_size_t interruptNumber) {
    gpio_irq_handler_list[interruptNumber] = NULL;
    return 0;
}

void pinRemoveInterrupt(pin_size_t interruptNumber) {
    if ((g_APinDescription[interruptNumber].ulPinMode & GPIO_IRQ_MODE_ENABLED) == GPIO_IRQ_MODE_ENABLED) {
        if ((g_APinDescription[interruptNumber].ulPinAttribute & PIO_GPIO_IRQ) == PIO_GPIO_IRQ) {
            gpio_irq_set(gpio_irq_pin_struct[interruptNumber], IRQ_NONE, 0);
            gpio_irq_deinit(gpio_irq_pin_struct[interruptNumber]);
            free(gpio_irq_pin_struct[interruptNumber]);
            gpio_irq_pin_struct[interruptNumber] = NULL;
            g_APinDescription[interruptNumber].ulPinMode &= (~GPIO_IRQ_MODE_ENABLED);
        }
    }
    g_APinDescription[interruptNumber].ulPinMode |= MODE_NOT_INITIAL;
}

bool isInterruptAttached(pin_size_t interruptNumber) {
    amb_ard_pin_check_name(interruptNumber);
    if (gpio_irq_pin_struct[interruptNumber] == NULL) {
        return false;
    } else {
        return true;
    }
}

void disAttachedInterrupt(pin_size_t interruptNumber) {
    gpio_irq_t *pGpio_irq_t;

    amb_ard_pin_check_name(interruptNumber);
    if (isInterruptAttached(interruptNumber)) {
        pGpio_irq_t = gpio_irq_pin_struct[interruptNumber];
        gpio_irq_disable(pGpio_irq_t);
    }
}

void enAttachedInterrupt(pin_size_t interruptNumber) {
    gpio_irq_t *pGpio_irq_t;

    amb_ard_pin_check_name(interruptNumber);
    if (isInterruptAttached(interruptNumber)) {
        pGpio_irq_t = gpio_irq_pin_struct[interruptNumber];
        gpio_irq_enable(pGpio_irq_t);
    }
}
