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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE2_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE2_H

#include <atomic>

#include "cutils/parcel.h"

#include "media/utils/message_handler.h"
#include "player_driver_lite.h"

/**
 * @brief Defines the invoke method id of a player.
 *
 * @since 1.0
 * @version 1.0
 */
enum RTPlayerInvokeIds {
	/** This method id is responsible for setting extractor probe mode.
	 * The request flow is like this:
	 * size_t mode = 1; // 0: normal probe; 1: fast probe
	 * Parcel *request = Parcel_Create();
	 * Parcel_WriteInt32(request, RTPLAYER_INVOKE_ID_SET_PROBE_MODE);
	 * Parcel_WriteInt32(request, mode);
	 * RTPlayer_Invoke(player, request, NULL);
	 * Parcel_Destroy(request);
	 */
	RTPLAYER_INVOKE_ID_SET_PROBE_MODE = 0,

	/** This method id is responsible for setting buffering parameters for streaming source.
	 * The request flow is like this:
	 * size_t initial_ms = 500;
	 * size_t resume_ms = 1000;
	 * size_t max_buffer_duration_ms = 2000;
	 * Parcel *request = Parcel_Create();
	 * Parcel_WriteInt32(request, RTPLAYER_INVOKE_ID_SET_STREAMING_BUFFERING_PARAMS);
	 * Parcel_WriteInt32(request, initial_ms);
	 * Parcel_WriteInt32(request, resume_ms);
	 * Parcel_WriteInt32(request, max_buffer_duration_ms);
	 * RTPlayer_Invoke(player, request, NULL);
	 * Parcel_Destroy(request);
	 */
	RTPLAYER_INVOKE_ID_SET_STREAMING_BUFFERING_PARAMS = 1,

	/** This method id is responsible for setting extractor probe mode.
	 * The request flow is like this:
	 * size_t buffer_size = 256*1024;
	 * size_t prepared_timeout_ms = 2000;
	 * size_t socket_connect_timeout_ms = 500;
	 * size_t send_timeout_ms = 2000;
	 * size_t recv_timeout_ms = 2000;
	 * size_t read_retry_time_ms = 5000;
	 * Parcel *request = Parcel_Create();
	 * Parcel_WriteInt32(request, RTPLAYER_INVOKE_ID_SET_HTTP_PARAMS);
	 * Parcel_WriteInt32(request, buffer_size);
	 * Parcel_WriteInt32(request, prepared_timeout_ms);
	 * Parcel_WriteInt32(request, socket_connect_timeout_ms);
	 * Parcel_WriteInt32(request, send_timeout_ms);
	 * Parcel_WriteInt32(request, recv_timeout_ms);
	 * Parcel_WriteInt32(request, read_retry_time_ms);
	 * RTPlayer_Invoke(player, request, NULL);
	 * Parcel_Destroy(request);
	 */
	RTPLAYER_INVOKE_ID_SET_HTTP_PARAMS = 2,

	/** This method id is responsible for getting current time.
	 * The request flow is like this:
	 * Parcel *request = Parcel_Create();
	 * Parcel *reply = Parcel_Create();
	 * Parcel_WriteInt32(request, RTPLAYER_INVOKE_ID_GET_CURRENT_TIME);
	 * if (RTPlayer_Invoke(player, request, reply) == OK) {
	 *     int64_t media_us = Parcel_ReadInt64(reply);
	 * }
	 * Parcel_Destroy(request);
	 * Parcel_Destroy(reply);
	 */
	RTPLAYER_INVOKE_ID_GET_CURRENT_TIME = 3,
};

namespace ameba::media
{

class Message;
class MetaData;
class DataSource;
class AudioRenderSinkLite;
class PlayerDriverLite;

class PlayerCoreLite : public MessageHandler
{
public:
	explicit PlayerCoreLite();

	void Init(PlayerDriverLite *driver);

	void SetSourceAsync(const char *url);
	void SetSourceAsync(const sptr<DataSource> &source);

	void PrepareAsync();
	void Start();
	void Pause();
	void ResetAsync();
	void RewindAsync(int64_t rewind_time_us, bool need_notify = false);
	res_t SetVolume(float left, float right);
	res_t SetSpeed(float speed, float pitch);
	res_t Invoke(Parcel *request, Parcel *reply);

	void SetAudioRenderSinkLite(const sptr<AudioRenderSinkLite> &sink);
	res_t GetCurrentTime(int64_t *media_us);

protected:
	virtual ~PlayerCoreLite();

	virtual void OnMessage(const sptr<Message> &msg);

public:
	class Source;

private:
	class GenericSource;
	class RTSPSource;
	class Decoder;
	class Renderer;
	class Action;
	//class RewindAction;
	//class ResumeDecoderAction;
	class FlushDecoderAction;
	class DummyAction;
	class PlayerThread;

	enum {
		//kMsgSetSource                 = 0x00510101, //'stS',
		//kMsgPrepare                    = 0x00510102, //'prep',
		//kMsgScanSources             = 0x00510103, //'scan',
		//kMsgSetAudioRenderSinkLite  = 0x00510104, //'audS',

		//kMsgStart                          = 0x00510201, //'strt',
		kMsgReset                       = 0x00510202, //'rset',
		//kMsgPause                       = 0x00510205, //'paus',
		//kMsgResume                      = 0x00510206, //'rsme',
		//kMsgRewind                       = 0x00510207, //'rwd',

		kMsgSourceEvent             = 0x00510401, //'srcN',
		kMsgRendererEvent          = 0x00510404, //'renN',
		kMsgSinkEvent                = 0x00510405, //'audN',
		//kMsgSetSpeed                 = 0x00510406,
	};

	Mutex lock_;
	bool player_thread_exit_;
	Condition player_thread_shut_down_;

	PlayerDriverLite *driver_;
	Mutex source_lock_;
	sptr<Source> source_;

	int32_t audio_decoder_count_;
	Mutex decoder_lock_;

	sptr<Decoder> audio_decoder_;
	sptr<Renderer> renderer_;

	sptr<MessageLooper> renderer_looper_;
	int32_t renderer_count_;

	sptr<AudioRenderSinkLite> audio_sink_;

	std::list<sptr<Action> > pending_actions_;

	bool eos_;

	enum FlushStatus {
		NONE,
		STATE_FLUSHING_DECODER,
		STATE_FLUSHING_DECODER_SHUTDOWN,
		SHUTTING_DOWN_DECODER,
		STATE_FLUSHED,
		SHUT_DOWN,
	};

	enum FlushAction {
		FLUSH_ACTION_NONE,
		FLUSH_ACTION_FLUSH,
		FLUSH_ACTION_SHUTDOWN,
	};

	// Status of flush responses from the decoder and renderer.
	bool flush_complete_[2]; //0-render; 1- decoder
	FlushStatus audio_flush_status_;

	// Status of flush responses from the decoder and renderer.
	bool resume_pending_;

	bool started_;
	bool prepared_;
	bool resetting_;
	bool source_started_;

	// Pause state
	// two cases may cause pause
	// 1. request by client
	// 2. pause for internal buffering
	bool paused_;
	bool paused_by_client_;
	bool paused_for_buffering_;

	typedef enum {
		SOURCE_TYPE_NONE,
		SOURCE_TYPE_HTTP_LIVE,
		SOURCE_TYPE_RTSP,
		SOURCE_TYPE_GENERIC_URL,
		SOURCE_TYPE_GENERIC_FD,
		SOURCE_TYPE_MEDIA,
		SOURCE_TYPE_STREAM,
	} SOURCE_TYPE;

	std::atomic<SOURCE_TYPE> source_type_;

	res_t CreateDecoder(sptr<Decoder> *decoder);

	void OnStart(int64_t start_time_us = -1);
	void OnResume();
	void OnPause();

	void HandleFlushComplete(bool is_decoder);
	void FinishFlushIfPossible();
	void HandleDecoderError(res_t err);

	void FinishResume();
	void ActResumeDecoders(bool need_notify);
	void ActRewind(int64_t rewind_time_us);
	void ActDecoderFlush(FlushAction action);
	void FlushDecoder(bool shut_down);
	void ActReset();
	void ActPendingActions();

	void NotifyRewindComplete();

	void OnSourceNotify(const sptr<Message> &msg);

	DISALLOW_COPY_AND_MOVE(PlayerCoreLite);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE2_H
