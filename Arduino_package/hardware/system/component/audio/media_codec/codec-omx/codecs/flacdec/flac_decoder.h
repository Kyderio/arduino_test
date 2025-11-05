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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_FLACDEC_FLAC_DECODER_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_FLACDEC_FLAC_DECODER_H

#include "osal_cxx/errors.h"
#include "media/utils/nocopyable.h"

#include "FLAC/stream_decoder.h"

namespace ameba::media
{

// packet based FLAC decoder, wrapps libFLAC stream decoder.
class FLACDecoder
{

public:
	enum {
		kMaxChannels = 8,
	};

	static FLACDecoder *Create();

	FLAC__StreamMetadata_StreamInfo GetStreamInfo() const
	{
		return stream_info_;
	}

	res_t ParseMetadata(const uint8_t *in_buffer, size_t in_buffer_len);
	res_t DecodeOneFrame(const uint8_t *in_buffer, size_t in_buffer_len,
						 unsigned char *out_buffer, size_t *out_buffer_len);
	void Flush();
	virtual ~FLACDecoder();

protected:
	FLACDecoder();

private:
	// stream properties
	unsigned GetMaxBlockSize() const
	{
		return stream_info_.max_blocksize;
	}
	unsigned GetSampleRate() const
	{
		return stream_info_.sample_rate;
	}
	unsigned GetChannels() const
	{
		return stream_info_.channels;
	}
	unsigned GetBitsPerSample() const
	{
		return stream_info_.bits_per_sample;
	}
	FLAC__uint64 GetTotalSamples() const
	{
		return stream_info_.total_samples;
	}

	res_t AddDataToBuffer(const uint8_t *in_buffer, size_t in_buffer_len);

	FLAC__StreamDecoder *decoder_;

	uint8_t *buffer_;  // cache input bit stream data
	size_t buffer_len_;  // the memory size of |mBuffer|
	size_t buffer_pos_;  // next byte to read in |mBuffer|
	// size of input data stored in |mBuffer|, always started at offset 0
	size_t buffer_data_size_;

	// cached when the STREAMINFO metadata is parsed by libFLAC
	FLAC__StreamMetadata_StreamInfo stream_info_;
	bool stream_info_valid_;

	// cached when a decoded PCM block is "written" by libFLAC decoder
	bool write_requested_;
	bool write_completed_;
	FLAC__FrameHeader write_header_;
	FLAC__int32 const *write_buffer_[kMaxChannels];

	// most recent error reported by libFLAC decoder
	FLAC__StreamDecoderErrorStatus error_status_;

	void (*copy_)(unsigned char *dst, const int *src[kMaxChannels], unsigned num_samples, unsigned num_channels);

	res_t Init();

	// FLAC stream decoder callbacks as C++ instance methods
	FLAC__StreamDecoderReadStatus ReadCallback(FLAC__byte buffer[], size_t *bytes);
	FLAC__StreamDecoderWriteStatus WriteCallback(
		const FLAC__Frame *frame, const FLAC__int32 *const buffer[]);
	void MetadataCallback(const FLAC__StreamMetadata *metadata);
	void ErrorCallback(FLAC__StreamDecoderErrorStatus status);

	DISALLOW_COPY_AND_MOVE(FLACDecoder);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_FLACDEC_FLAC_DECODER_H
