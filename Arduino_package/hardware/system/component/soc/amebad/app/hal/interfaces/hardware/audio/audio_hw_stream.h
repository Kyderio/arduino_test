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
 * @file audio_hw_stream.h
 *
 * @brief Declares APIs for audio stream.
 *
 * @since 1.0
 * @version 1.0
 */


#ifndef AMEBA_HARDWARE_INTERFACES_HARDWARE_AUDIO_AUDIO_HW_STREAM_H
#define AMEBA_HARDWARE_INTERFACES_HARDWARE_AUDIO_AUDIO_HW_STREAM_H

#include "hardware/audio/audio_hw_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Provides the basic functions for audio streams including audio render/audio capture.
 * @since 1.0
 * @version 1.0
 */
struct AudioHwStream {

	/**
	 * @brief Return the sampling rate in Hz for a <b>AudioHwStream</b> object .
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @return Returns the sampling rate for the stream
	 * returns <b>0</b> value otherwise.
	 * @see SetSampleRate
	 */
	uint32_t (*GetSampleRate)(const struct AudioHwStream *stream);

	/**
	 * @brief Set the sampling rate in Hz to a <b>AudioHwStream</b> object .
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @param rate Indicates the sampling rate set to the audio hal stream.
	 * @return Returns returns <b>0</b> value.
	 * @see GetSampleRate
	 */
	int (*SetSampleRate)(struct AudioHwStream *stream, uint32_t rate);

	/**
	 * @brief Get size of input/output buffer in bytes for this stream for a <b>AudioHwStream</b> object ,It should be a multiple of the frame size
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @return Returns the buffer size  for the stream to render/capture
	 */
	size_t (*GetBufferSize)(const struct AudioHwStream *stream);

	/**
	 * @brief Return the channel mask for a <b>AudioHwStream</b> object .
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @return Returns the channel mask for the stream
	 * @see SetChannels
	 */
	uint32_t (*GetChannels)(const struct AudioHwStream *stream);

	/**
	 * @brief Set the channel mask to a <b>AudioHwStream</b> object .
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @param channel Indicates the channel mask set to the audio hal stream.
	 * @return Returns returns <b>0</b> value.
	 * @see GetChannels
	 */
	int (*SetChannels)(const struct AudioHwStream *stream, uint32_t channel);

	/**
	 * @brief Return the audio format for a <b>AudioHwStream</b> object .
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @return Returns the audio format for the stream
	 * @see SetFormat
	 */
	AudioHwFormat(*GetFormat)(const struct AudioHwStream *stream);

	/**
	 * @brief Set the audio format to a <b>AudioHwStream</b> object .
	 *
	 * @param stream Indicates the pointer to the audio hal stream to operate.
	 * @param format Indicates the audio format set to the audio hal stream.
	 * @return Returns returns <b>0</b> value.
	 * @see GetFormat
	 */
	int (*SetFormat)(struct AudioHwStream *stream, AudioHwFormat format);

	int (*Standby)(struct AudioHwStream *stream);

	/** dump the state of the audio input/output device */
	int (*Dump)(const struct AudioHwStream *stream, int fd);

	/** Return the set of device(s) which this stream is connected to */
	//audio_devices_t (*get_device)(const struct AudioHwStream *stream);

	// int (*set_device)(struct AudioHwStream *stream, audio_devices_t device);

	int (*SetParameters)(struct AudioHwStream *stream, const char *kvPairs);

	/*
	 * Returns a pointer to a heap allocated string. The caller is responsible
	 * for freeing the memory for it using free().
	 */
	char *(*GetParameters)(const struct AudioHwStream *stream, const char *keys);
};

typedef struct AudioHwStream AudioHwStream;


#ifdef __cplusplus
}
#endif

#endif  // AMEBA_HARDWARE_INTERFACES_HARDWARE_AUDIO_AUDIO_HW_STREAM_H
/** @} */
