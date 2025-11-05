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
 * @file audio_control.h
 *
 * @brief Provides APIs of the audio control, such as volume, mute, input devices.
 *
 *
 * @since 1.0
 * @version 1.0
 */

#ifndef AUDIO_TEST_AUDIO_DRC_H
#define AUDIO_TEST_AUDIO_DRC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct RTAudioDrc;

#define KNEE_POINT_NUM_MAX  4

/**
 * @brief Defines the audio drc knee configs.
 *
 * @since 1.0
 * @version 1.0
 */
struct RTAudioDrcKneePoint {
    /** threshold (dB) */
    float threshold_db;
    /** ratio */
    float ratio;
};

/**
 * @brief Defines the audio drc configs.
 *
 * @since 1.0
 * @version 1.0
 */
struct RTAudioDrcConfig {
    /** number of knee point */
    int num_of_knee_point;
    /** Attack time (sec) */
    float attack_time;
    /** Release time (sec) */
    float release_time;
    /** Makeup Gain (dB) */
    float makeup_gain;
    /** knee points of drc */
    struct RTAudioDrcKneePoint knee_point[KNEE_POINT_NUM_MAX];
};

/**
 * @brief Defines the split frequencies of 3 bands drc.
 *
 * @since 1.0
 * @version 1.0
 */
struct RTAudioDrcSplitFreq {
    /** crossover freq. low (Hz) */
    int fc_lo;
    /** crossover freq. high (Hz) */
    int fc_hi;
};

/**
 * @brief Defines all the audio drc 3 bands configs.
 *
 * @since 1.0
 * @version 1.0
 */
struct RTAudioMultiBandsDrcConfig {
    /** fc_low fc_high of 3 bands. */
    struct RTAudioDrcSplitFreq split_freq;
    /** config of low band. */
    struct RTAudioDrcConfig drc_band_low;
    /** config of middle band. */
    struct RTAudioDrcConfig drc_band_mid;
    /** config of high band. */
    struct RTAudioDrcConfig drc_band_high;
};

/**
 * @brief multi bands drc create & initialize & start
 *
 *  @param drc_config: input multi bands drc config setting
 *  @param sample_rate: sample rate (support: 8K, 16K, 32K, 44.1K, 48K, 88.2K, 96K, 192K)
 *  @param frame_count: frame size: must be multiple of 1ms's frame count
 *  @param channel_count: number of channels
 *  @param bits: bits of audio sample
 *  @return Returns RTAudioDrc pointer
 */
struct RTAudioDrc *RTAudioMultiBandsDrc_Create(struct RTAudioMultiBandsDrcConfig *drc_config,
                        float sample_rate, int32_t frame_count, int32_t channel_count, int32_t bits);

/**
 * @brief multi bands drc close & release memory
 *
 * @param audio_drc: RTAudioDrc pointer
 */
void RTAudioMultiBandsDrc_Release(struct RTAudioDrc *audio_drc);

/**
 * @brief multi bands drc main process
 *
 * @param audio_drc: RTAudioDrc pointer
 * @param in_buf: PCM input buffer
 * @param out_buf: PCM output buffer
 */
void RTAudioMultiBandsDrc_Process(struct RTAudioDrc *audio_drc, int8_t *in_buf, int8_t *out_buf);

/**
 * @brief DRC create & initialize & start
 *
 *  @param drc_config: input DRC config setting
 *  @param sample_rate: sample rate (support: 8K, 16K, 32K, 44.1K, 48K, 88.2K, 96K, 192K)
 *  @param frame_count: frame size: must be multiple of 1ms's frame count
 *  @param channel_count: number of channels
 *  @param bits: bits of audio sample
 *  @return Returns RTAudioDrc pointer
 */
struct RTAudioDrc *RTAudioDrc_Create(struct RTAudioDrcConfig *drc_config,
                        float sample_rate, int32_t frame_count, int32_t channel_count, int32_t bits);

/**
 * @brief DRC close & release memory
 *
 * @param audio_drc: RTAudioDrc pointer
 */
void RTAudioDrc_Release(struct RTAudioDrc *audio_drc);

/**
 * @brief DRC main process
 *
 *  @param audio_drc: RTAudioDrc pointer
 *  @param in_buf: PCM input buffer
 *  @param out_buf: PCM output buffer
 */
void RTAudioDrc_Process(struct RTAudioDrc *audio_drc, int8_t *in_buf, int8_t *out_buf);

#ifdef __cplusplus
}
#endif

#endif