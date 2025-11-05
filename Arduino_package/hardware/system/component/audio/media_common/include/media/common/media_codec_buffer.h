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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_COMMON_MEDIA_COMMON_MEDIA_CODEC_BUFFER_H
#define AMEBA_FWK_MEDIA_PLAYBACK_COMMON_MEDIA_COMMON_MEDIA_CODEC_BUFFER_H

#include <sys/types.h>
#include <stdint.h>

#include "osal_cxx/errors.h"
#include "osal_cxx/refptr.h"

namespace ameba::media
{

class MediaCodecBuffer : public RefPtr
{
public:
	MediaCodecBuffer(size_t capacity);

	virtual ~MediaCodecBuffer();

	uint8_t *Base();
	uint8_t *Data();
	size_t Capacity() const;
	size_t Size() const;
	size_t Offset() const;
	uint32_t BufferId() const;
	int64_t TimeStamp() const;
	uint32_t Flag() const;

	void SetRange(size_t offset, size_t size);
	void SetBufferId(uint32_t buffer_id);
	void SetTimeStamp(int64_t time_stamp);
	void SetFlag(uint32_t flag);

	//virtual res_t SetRange(size_t offset, size_t size);

private:
	uint32_t buffer_id_;
	int64_t time_stamp_;

	uint8_t *buf_;      /**< A reference to a data buffer */
	uint32_t offset_;   /**< Buffer offset */
	uint32_t length_;   /**< Length of valid data */
	uint32_t capacity_; /**< Total size of buffer blocks*/
	uint32_t flag_;

	//bool eos_;
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_COMMON_MEDIA_COMMON_MEDIA_CODEC_BUFFER_H