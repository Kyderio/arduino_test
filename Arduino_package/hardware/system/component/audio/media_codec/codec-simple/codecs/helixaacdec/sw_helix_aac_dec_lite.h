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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_CODECS_HAACDEC_SW_HELIX_AAC_DEC_H
#define AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_CODECS_HAACDEC_SW_HELIX_AAC_DEC_H

#include "media/codec/sw_media_codec_base.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SwHelixAACDec SwHelixAACDec;

SwMediaCodecBase *SwHelixAACDec_Create(const char *name);

#ifdef __cplusplus
}
#endif

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_CODECS_HAACDEC_SW_HELIX_AAC_DEC_H
