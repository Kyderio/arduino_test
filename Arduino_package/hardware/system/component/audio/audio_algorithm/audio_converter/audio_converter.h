
/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup Audio
 * @{
 *
 * @brief Declares APIs for audio framework.
 *
 *
 * @since 1.0
 * @version 1.0
 */

/**
 * @file audio_converter.h
 *
 * @brief Provides APIs of the audio converter.
 *
 *
 * @since 1.0
 * @version 1.0
 */

#ifndef AMEBA_AUDIO_INTERFACES_AUDIO_AUDIO_CONVERTER_H
#define AMEBA_AUDIO_INTERFACES_AUDIO_AUDIO_CONVERTER_H

#include <stdint.h>
#include "audio/audio_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines all the audio convert qualities.
 *
 * @since 1.0
 * @version 1.0
 */
enum {
	/** Invalid converter */
	RTAudio_CONVERT_INVALID        = 0x0u,
	RTAudio_CONVERT_LOW            = 0x1u,
	RTAudio_CONVERT_MID            = 0x2u,
	RTAudio_CONVERT_HIGH           = 0x3u,
	RTAudio_CONVERT_VERY_HIGH      = 0x4u,
	RTAudio_CONVERT_MAX            = 0x5u,
};

/**
 * @brief Defines all the audio resample types.
 *
 * @since 1.0
 * @version 1.0
 */
enum {
	/** Invalid converter */
	RTAudio_RESAMPLE_NONE          = 0x0u,
	/** soxr resampler */
	RTAudio_RESAMPLE_SOXR          = 0x1u,
	/** speex resampler */
	RTAudio_RESAMPLE_SPEEX         = 0x2u,
	/** resampler count */
	RTAudio_RESAMPLE_MAX           = 0x3u,
};

struct RTAudioConverter;

/**
 * @brief Defines all the audio converter configs.
 *
 * @since 1.0
 * @version 1.0
 */
struct RTAudioConverterConfig {
	/** the input rate of samples */
	uint32_t in_rate;
	/** the output rate of samples */
	uint32_t out_rate;
	/** the input channels of samples. Now only support in_channels == out_channels */
	uint32_t in_channels;
	/** the output channels of samples. Now only support in_channels == out_channels */
	uint32_t out_channels;
	/** input format of samples */
	uint32_t in_format;
	/** onput format of samples */
	uint32_t out_format;
	/** the quality of audio convertion */
	uint32_t quality;
	/** the resample engine type of audio convertion */
	uint32_t resample_type;
};

/**
 * @brief Init engine of converter.
 *
 * @param config the configuration to setup convert engines.
 * @return Returns the created pointer of RTAudioConverter.
 * @since 1.0
 * @version 1.0
 */
struct RTAudioConverter *RTAudioConverter_Create(struct RTAudioConverterConfig *config);

/**
 * @brief Release RTAudioConverter.
 */
void RTAudioConverter_Destroy(struct RTAudioConverter *converter);

/**
 * @brief Do convert.
 *
 * @param converter is the pointer of struct RTAudioConverter.
 * @param in_buf the input data's buffer pointer.
 * @param in_frames the samples to convert from in_buf.
 * @param in_done the samples actually converted by convert engine.
 * @param obuf the output data's buffer pointer.
 * @param out_frames the samples to convert to obuf.
 * @param out_done the samples actually output to obuf by convert engine.
 * @return Returns a value listed below: \n
 * int32_t | Description
 * ----------------------| -----------------------
 * AUDIO_OK | the operation is successful.
 * AUDIO_ERR_INVALID_OPERATION | param not supported.
 * @since 1.0
 * @version 1.0
 */
int32_t RTAudioConverter_Process(struct RTAudioConverter *converter, int8_t *in_buf, uint32_t in_frames,
								 uint32_t *in_done, int8_t *obuf, uint32_t out_frames, uint32_t *out_done);

#ifdef __cplusplus
}
#endif

#endif
