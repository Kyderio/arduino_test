/*
  Copyright (c) 2014 Arduino LLC.  All right reserved.

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

#include "os_wrapper.h"

#ifdef __cplusplus
}
#endif

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout) {
    uint32_t start_us, cur_us;

    amb_ard_pin_check_name(pin);
    amb_ard_pin_check_fun(pin, PIO_GPIO);

    // wait for any previous pulse to end
    start_us = (uint32_t)rtos_time_get_current_system_time_us();
    while (state == GPIO_ReadDataBit(g_APinDescription[pin].pinname)) {
        cur_us = (uint32_t)rtos_time_get_current_system_time_us();
        if (cur_us - start_us > timeout) return 0;
    }

    // wait for the pulse to start
    while (state != GPIO_ReadDataBit(g_APinDescription[pin].pinname)) {
        cur_us = (uint32_t)rtos_time_get_current_system_time_us();
        if (cur_us - start_us > timeout) return 0;
    }

    // wait for the pulse to stop
    start_us = (uint32_t)rtos_time_get_current_system_time_us();
    while (state == GPIO_ReadDataBit(g_APinDescription[pin].pinname)) {
        cur_us = (uint32_t)rtos_time_get_current_system_time_us();
        if (cur_us - start_us > timeout) return 0;
    }

    cur_us = (uint32_t)rtos_time_get_current_system_time_us();

    return cur_us - start_us;
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout) {
    pulseIn(pin, state, timeout);
}