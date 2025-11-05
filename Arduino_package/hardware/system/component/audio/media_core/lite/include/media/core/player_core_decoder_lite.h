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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE_DECODER_LITE_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE_DECODER_LITE_H
#include <vector>

#include "player_core_lite.h"

#include "media/codec/sw_media_codec_base.h"
#include "media/codec/sw_media_codec_factory.h"

namespace ameba::media
{

static const uint32_t kPortInput = 0;
static const uint32_t kPortOutput = 1;

class CodecBufferInfo;

class PlayerCoreLite::Decoder : public MessageHandler
{
public:
	Decoder(const sptr<Message> &notify,
			const sptr<Source> &source,
			const sptr<Renderer> &renderer = NULL);

	void Configure(const sptr<Message> &format);
	void Init();
	void SetRenderer(const sptr<Renderer> &renderer);

	void Pause();
	void Flush();
	void Resume(bool need_notify);
	void StartShutdown();
	void Start();

	res_t FillInputBuffer();
	res_t RequestSourceData(sptr<RBuffer> *data);
	int32_t Decode(sptr<RBuffer> &out);

	enum {
		kMsgEOS                 = 0x312,//'eos ',
		kMsgFlushCompleted      = 0x316,//'fcom',
		kMsgShutdownCompleted   = 0x00550208, //'shDC',
		kMsgError               = 0x31A,//'erro',
	};

protected:
	virtual ~Decoder();

private:
	enum {
		kMsgShutdown            = 0x00550202, //'shuD',
		kMsgFlush               = 0x00550204, //'flus',
	};

	enum {
		kMaxCodecBufferSize = 8192 * 4096 * 4,
	};

	sptr<Source> source_;
	sptr<Renderer> renderer_;
	SwMediaCodecBase *codec_;
	CODEC_BUFFERHEADERTYPE *in_header_;
	CODEC_BUFFERHEADERTYPE *out_header_;

	sptr<Message> input_format_;
	sptr<Message> output_format_;
	bool output_format_changed_;
	bool input_eos_;
	bool output_eos_;
	bool stop_status_;

	sptr<MessageLooper> decoder_looper_;
	std::list<sptr<RBuffer> > codec_specific_data_;
	RString component_name_;
	bool paused_;
	Mutex lock_;
	Condition resume_changed_;
	sptr<Message> notify_;

	bool decoder_thread_exit_;
	Condition decoder_thread_show_down_;

	int in_port_buffer_count_;

	res_t ConfigureCodec(const char *mime, const sptr<Message> &msg);
	void GetCodecSpecificData(const sptr<Message> &format);
	res_t SetMinBufferSize(uint32_t port_idx, size_t size);
	res_t AllocateHeader(int index);

	res_t SetupAACCodec(
		int32_t num_channels, int32_t sample_rate, int32_t bit_rate,
		int32_t aac_profile, bool is_adts, int32_t sbr_mode,
		int32_t max_output_channel_count,
		int32_t pcm_limiter_enable);

	res_t SetupRawAudioEncoding(
		uint32_t port_idx, int32_t sample_rate, int32_t num_channels,
		AudioEncoding encoding = kAudioEncodingPcm16bit);

	res_t GetPortFormat(uint32_t port_idx, sptr<Message> &notify);
	res_t GetOutputFormat(sptr<Message> *format) const;
	res_t GetInputFormat(sptr<Message> *format) const;

	void StopLooper();

	virtual void OnMessage(const sptr<Message> &msg);
	virtual void OnResume(bool need_notify);
	virtual void OnFlush();
	virtual void OnShutdown(bool need_notify);

	void DoFlush(bool need_notify);
	void HandleError(int32_t err);
	void HandleOutputFormatChange(const sptr<Message> &format);

	DISALLOW_COPY_AND_MOVE(Decoder);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE_DECODER_LITE_H
