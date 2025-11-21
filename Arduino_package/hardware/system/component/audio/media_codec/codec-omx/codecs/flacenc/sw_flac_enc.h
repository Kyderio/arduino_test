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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_AACDEC_SW_FLAC_ENC_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_AACDEC_SW_FLAC_ENC_H

#include "media/codec/omx/sw_omx_component.h"

#include "FLAC/stream_encoder.h"

namespace ameba::media
{

class SwFlacEnc : public SwOMXComponent
{
public:
	SwFlacEnc(const char *name,
			  const OMX_CALLBACKTYPE *callbacks,
			  OMX_PTR appData,
			  OMX_COMPONENTTYPE **component);

protected:
	virtual ~SwFlacEnc();

	virtual OMX_ERRORTYPE GetParameterInternal(
		OMX_INDEXTYPE index, OMX_PTR params);

	virtual OMX_ERRORTYPE SetParameterInternal(
		OMX_INDEXTYPE index, const OMX_PTR params);

	virtual void OnQueueFilled(OMX_U32 portIndex);

private:
	const unsigned int kNumBuffers = 2;
	const unsigned int kMaxNumSamplesPerFrame = 1152;
	const unsigned int KMaxChannels = 8;
	const unsigned int kMaxInputBufferSize = kMaxNumSamplesPerFrame * 3 * KMaxChannels;
	const unsigned int kMaxOutputBufferSize = 65536;    //TODO check if this can be reduced

	bool signalled_error_;

	OMX_U32 num_channels_;
	OMX_U32 sample_rate_;
	OMX_U32 compression_level_;
	OMX_U32 bits_;

	// should the data received by the callback be written to the output port
	bool        encoder_write_data_;
	bool        encoder_returned_encoded_data_;
	bool        saw_input_EOS_;
	bool        sent_output_EOS_;
	size_t      encoder_returned_Nb_bytes_;
	OMX_TICKS  current_input_timestamp_;

	FLAC__StreamEncoder *flac_stream_encoder_;

	void InitPorts();

	OMX_ERRORTYPE ConfigureEnc();

	// FLAC encoder callbacks
	// maps to encoderEncodeFlac()
	static FLAC__StreamEncoderWriteStatus FlacEncoderWriteCallback(
		const FLAC__StreamEncoder *encoder, const FLAC__byte buffer[],
		size_t bytes, uint32_t samples, uint32_t current_frame, void *client_data);

	FLAC__StreamEncoderWriteStatus OnEncodedFlacAvailable(
		const FLAC__byte buffer[],
		size_t bytes, unsigned samples, unsigned current_frame);

	// FLAC takes samples aligned on 32bit boundaries, use this buffer for the conversion
	// before passing the input data to the encoder
	FLAC__int32 *input_buffer_pcm32_;

	unsigned header_offset_;
	bool header_complete_;
	bool wrote_header_;
	char header_[128];

	// disable copy ctor
	SwFlacEnc(const SwFlacEnc &);
	SwFlacEnc &operator=(const SwFlacEnc &);
};

}

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_AACDEC_SW_FLAC_ENC_H


