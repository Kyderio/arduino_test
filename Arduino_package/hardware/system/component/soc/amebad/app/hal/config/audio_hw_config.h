/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef AMEBA_HARDWARE_AUDIO_AUDIO_HW_CONFIG_H
#define AMEBA_HARDWARE_AUDIO_AUDIO_HW_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

/*
 *Audio amplifier pin, if it's set as true, then amplifier is controlled by audio hal.
 *If it's set as false, then amplifier is controlled by user.
 *To be noticed, if user using amplifier, then k_audio_hw_use_headset should be set false.
 */
extern bool k_audio_hw_use_amplifier;

/*
 *Audio amplifier pin's initial state, some pin may defalut high, when system boot, if
 *so, set is true, otherwise, set is false;
 */
extern bool k_audio_hw_amplifier_pin_initial_state;

/*
 *Audio amplifier pin, if your board has no audio amplifier pin.
 */
extern uint32_t k_audio_hw_amplifier_pin;

/*
 *After enable amplifer, it need some time to be steady. For d demo board, it's 55ms.
 */
extern uint32_t k_audio_hw_amplifier_enable_time;

/*
 *After disable amplifer, it need some time to be steady. For d demo board, it's 180ms.
 */
extern uint32_t k_audio_hw_amplifier_disable_time;

/*
 *Audio headset settings.If user wants to play through headset, set it true.
 *To be noticed, if user using headset, then k_audio_hw_use_amplifier should be set false.
 */
extern bool k_audio_hw_use_headset;

/*
 *Debug hal time, 1: shows time log, 0: shows no time log.
 */
extern bool k_audio_hw_time_debug;

#endif
