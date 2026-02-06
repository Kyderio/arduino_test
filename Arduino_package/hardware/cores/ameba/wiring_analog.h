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

#ifndef _WIRING_ANALOG_
#define _WIRING_ANALOG_

#include "Arduino.h"

#define AR_DEFAULT  0
#define PWM_TIMER_NUM   4
#define PWM_INDEX_NUM   4

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t pwmtimer_idx;
    uint8_t pwm_idx;
    pin_size_t pin;
    bool alloc;
} pwm_resource;

/**************************** Extend API by RTK ***********************************/
/**
 * @brief Get voltage in mV according to conversion data.
 * @param valueRead ADC conversion data from normal channel.
 * @return Normal voltage in mV.
 */
extern int analogConvertVoltage(int valueRead);

/**
 * @brief Set analog output period time.
 * @param us The analog output period time in us (default is 1000us).
 * @return None.
 */
extern void analogWritePeriod(int us);

#ifdef __cplusplus
}
#endif

#endif