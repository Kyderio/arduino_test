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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_AACDEC_SW_FLAC_DEC_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_AACDEC_SW_FLAC_DEC_H

#include "flac_decoder.h"
#include "media/codec/omx/sw_omx_component.h"

namespace ameba::media
{

struct SwFlacDec : public SwOMXComponent {
	SwFlacDec(const char *name,
			  const OMX_CALLBACKTYPE *callbacks,
			  OMX_PTR app_data,
			  OMX_COMPONENTTYPE **component);

protected:
	virtual ~SwFlacDec();

	virtual OMX_ERRORTYPE GetParameterInternal(
		OMX_INDEXTYPE index, OMX_PTR params);

	virtual OMX_ERRORTYPE SetParameterInternal(
		OMX_INDEXTYPE index, const OMX_PTR params);

	virtual void OnQueueFilled(OMX_U32 port_index);
	virtual void OnPortFlushCompleted(OMX_U32 port_index);
	virtual void OnPortEnableCompleted(OMX_U32 port_index, bool enabled);
	virtual void OnReset();

private:
	enum {
		kNumInputBuffers   = 4,
		kNumOutputBuffers  = 4,
	};

	FLACDecoder *flac_stream_decoder_wrap_;
	FLAC__StreamMetadata_StreamInfo stream_info_;
	size_t input_buffer_count_;
	bool has_stream_info_;
	bool signalled_error_;
	bool saw_input_eos_;
	bool finished_decoder_;

	enum {
		NONE,
		AWAITING_DISABLED,
		AWAITING_ENABLED
	} output_port_settings_change_;

	void InitPorts();
	void InitDecoder();
	bool IsConfigured() const;
	void DrainDecoder();

	DISALLOW_COPY_AND_MOVE(SwFlacDec);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_CODEC_CODECS_AACDEC_SW_FLAC_DEC_H

