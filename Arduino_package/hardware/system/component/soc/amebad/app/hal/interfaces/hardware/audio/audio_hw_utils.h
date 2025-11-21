/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @addtogroup HAL
 * @{
 *
 * @brief Declares the structures and interfaces for the Hardware Abstraction Layer (HAL) module.
 *
 * @since 1.0
 * @version 1.0
 */

/**
 * @file audio_hw_utils.h
 *
 * @brief Declares audio basic functions.
 *
 * @since 1.0
 * @version 1.0
 */


#ifndef AMEBA_HARDWARE_INTERFACES_HARDWARE_AUDIO_AUDIO_HW_UTILS_H
#define AMEBA_HARDWARE_INTERFACES_HARDWARE_AUDIO_AUDIO_HW_UTILS_H
#include <sys/types.h>
#include "hardware/audio/audio_hw_types.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline size_t GetAudioBytesPerSample(AudioHwFormat format)
{
	size_t size = 0;

	switch (format) {
	case AUDIO_HW_FORMAT_PCM_32_BIT:
		size = sizeof(int32_t);
		break;
	case AUDIO_HW_FORMAT_PCM_24_BIT:
		size = sizeof(uint8_t) * 3;
		break;
	case AUDIO_HW_FORMAT_PCM_16_BIT:
		size = sizeof(int16_t);
		break;
	case AUDIO_HW_FORMAT_PCM_8_BIT:
		size = sizeof(uint8_t);
		break;
	default:
		break;
	}
	return size;
}

static inline bool AudioIsLinearPCM(AudioHwFormat format)
{
	return ((format & AUDIO_HW_FORMAT_MAIN_MASK) == AUDIO_HW_FORMAT_PCM);
}

static inline AudioHwFormat AudioGetMainFormat(AudioHwFormat format)
{
	return (AudioHwFormat)(format & AUDIO_HW_FORMAT_MAIN_MASK);
}

static inline bool AudioCheckValidFormat(AudioHwFormat format)
{
	switch (format & AUDIO_HW_FORMAT_MAIN_MASK) {
	case AUDIO_HW_FORMAT_PCM:
		switch (format) {
		case AUDIO_HW_FORMAT_PCM_16_BIT:
		case AUDIO_HW_FORMAT_PCM_8_BIT:
		case AUDIO_HW_FORMAT_PCM_32_BIT:
		case AUDIO_HW_FORMAT_PCM_24_BIT:
			return true;
		default:
			return false;
		}

	default:
		return false;
	}
}

#ifdef __cplusplus
}
#endif

#endif  // AMEBA_HARDWARE_INTERFACES_HARDWARE_AUDIO_AUDIO_HW_UTILS_H
/** @} */
