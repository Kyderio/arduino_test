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

#include "os_wrapper.h"

void delay(unsigned long ms) {
    rtos_time_delay_ms(ms);
}

void delayMicroseconds(unsigned int us) {
    rtos_time_delay_us(us);
}

unsigned long millis(void) {
    return rtos_time_get_current_system_time_ms();
}

unsigned long micros(void) {
    return (unsigned long)rtos_time_get_current_system_time_us();
}

#ifdef __cplusplus
}
#endif
