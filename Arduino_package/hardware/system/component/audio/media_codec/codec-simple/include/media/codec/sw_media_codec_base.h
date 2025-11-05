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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_SW_MEDIA_CODEC_BASE_H
#define AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_SW_MEDIA_CODEC_BASE_H

#include <stdint.h>

#include "media/codec/sw_media_codec_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SwMediaCodecBase SwMediaCodecBase;

struct SwMediaCodecBase {
	int32_t (*Decode)(SwMediaCodecBase *self, CODEC_BUFFERHEADERTYPE *in_header, CODEC_BUFFERHEADERTYPE *out_header);
	status_t (*GetParameter)(SwMediaCodecBase *self, CODEC_INDEXTYPE index, void *params);
	status_t (*SetParameter)(SwMediaCodecBase *self, CODEC_INDEXTYPE index, const void *params);
	const char *(*GetName)(SwMediaCodecBase *self);
	status_t (*Destroy)(SwMediaCodecBase *self);
};

#ifdef __cplusplus
}
#endif

#endif /* AMEBA_FWK_MEDIA_PLAYBACK_RTCODEC_SW_MEDIA_CODEC_BASE_H */
