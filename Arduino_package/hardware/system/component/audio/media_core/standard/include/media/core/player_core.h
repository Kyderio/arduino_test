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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE_H

#include <atomic>

#include "media/parcel.h"

#include "media/utils/message_handler.h"
#include "player_driver.h"

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

	/** This method id is responsible for enable cache and set cache parameters.
	 * The request flow is like this:
	 * int32_t cache_enable = 1;
	 * char* prefix = "fat://";
	 * char* cache_dir = "cache";
	 * int32_t max_cache_count = 100;
	 * Parcel *request = Parcel_Create();
	 * Parcel_WriteInt32(request, RTPLAYER_INVOKE_ID_SET_CACHE_PARAMS);
	 * Parcel_WriteInt32(request, cache_enable);
	 * Parcel_WriteCString(request, prefix);
	 * Parcel_WriteCString(request, cache_dir);
	 * Parcel_WriteInt32(request, max_cache_count);
	 * RTPlayer_Invoke(player, request, NULL);
	 * Parcel_Destroy(request);
	 */
	RTPLAYER_INVOKE_ID_SET_CACHE_PARAMS = 4,

	/** This method id is responsible for setting bt parameters for bt output.
	 * The request flow is like this:
	 * int32_t sample_rate = 48000;
	 * int32_t channels = 2;
	 * int32_t bits = 16;
	 * int32_t size = 1024;
	 * Parcel *request = Parcel_Create();
	 * Parcel_WriteInt32(request, RTPLAYER_INVOKE_ID_SET_AUDIO_Params);
	 * Parcel_WriteInt32(request, sample_rate);
	 * Parcel_WriteInt32(request, channels);
	 * Parcel_WriteInt32(request, bits);
	 * Parcel_WriteInt32(request, size);
	 * RTPlayer_Invoke(player, request, NULL);
	 * Parcel_Destroy(request);
	 */
	RTPLAYER_INVOKE_ID_SET_AUDIO_Params = 1111,

	RTPLAYER_INVOKE_ID_SET_AUDIO_VOLUME = 1112,
};

namespace ameba::media
{

class Message;
class MetaData;
class DataSource;
class AudioRenderSink;
class PlayerDriver;

class PlayerCore : public MessageHandler
{
public:
	explicit PlayerCore();

	void Init(PlayerDriver *driver);

	void SetSourceAsync(const char *url);
	void SetSourceAsync(RTDataSource *source);

	void PrepareAsync();
	void Start();
	void Pause();
	void ResetAsync();
	void RewindAsync(int64_t rewind_time_ns, bool need_notify = false);
	res_t SetVolume(float left, float right);
	res_t SetSpeed(float speed, float pitch);
	res_t Invoke(Parcel *request, Parcel *reply);

	void SetAudioRenderSink(const sptr<AudioRenderSink> &sink);
	res_t GetCurrentTime(int64_t *media_ns);

protected:
	virtual ~PlayerCore();

	virtual void OnMessage(const sptr<Message> &msg);

public:
	class Source;

private:
	class Decoder;
	class DecoderBase;
	class GenericSource;
	class RTSPSource;
	class Renderer;
	class Action;
	class RewindAction;
	class ResumeDecoderAction;
	class FlushDecoderAction;
	class DummyAction;

	enum {
		kMsgSetSource                 = 0x00510101, //'stS',
		kMsgPrepare                    = 0x00510102, //'prep',
		kMsgScanSources             = 0x00510103, //'scan',
		kMsgSetAudioRenderSink  = 0x00510104, //'audS',
		//kWhatMoreDataQueued             = 'more',
		//kWhatConfigPlayback             = 'cfPB',
		//kWhatConfigSync                 = 'cfSy',
		//kWhatGetPlaybackSettings        = 'gPbS',
		//kWhatGetSyncSettings            = 'gSyS',
		kMsgStart                          = 0x00510201, //'strt',
		kMsgReset                       = 0x00510202, //'rset',
		kMsgPause                       = 0x00510205, //'paus',
		kMsgResume                      = 0x00510206, //'rsme',
		kMsgRewind                       = 0x00510207, //'rwd',

		kMsgSourceEvent             = 0x00510401, //'srcN',
		kMsgRendererEvent          = 0x00510404, //'renN',
		kMsgSinkEvent                = 0x00510405, //'audN',
		//kWhatClosedCaptionNotify        = 'capN',
		//kWhatPollDuration               = 'polD',
		//kWhatGetTrackInfo               = 'gTrI',
		//kWhatGetSelectedTrack           = 'gSel',
		//kWhatSelectTrack                = 'selT',
		//kWhatGetBufferingSettings       = 'gBus',
		//kWhatSetBufferingSettings       = 'sBuS',
		//kMsgPrepareDrm                 = 'pDrm',
		//kMsgReleaseDrm                 = 'rDrm',
		//kWhatMediaClockNotify           = 'mckN',
		kMsgSetSpeed                 = 0x00510406,
		kMsgSetVolume                 = 0x00510407,
		kMsgInvoke                 = 0x00510408,
	};

	PlayerDriver *driver_;
	Mutex source_lock_;
	sptr<Source> source_;

	sptr<DecoderBase> audio_decoder_;
	int32_t audio_decoder_count_;
	Mutex decoder_lock_;

	sptr<Renderer> renderer_;
	sptr<MessageLooper> renderer_looper_;
	int32_t renderer_count_;

	sptr<AudioRenderSink> audio_sink_;

	int64_t previous_rewind_time_ns_;

	std::list<sptr<Action> > pending_actions_;

	bool eos_;

	bool scan_sources_pending_;
	int32_t scan_sources_count_;

	float volume_factor_;

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

	res_t CreateDecoder(sptr<DecoderBase> *decoder);

	void OnStart(int64_t start_time_ns = -1);
	void OnResume();
	void OnPause();

	void HandleFlushComplete(bool is_decoder);
	void FinishFlushIfPossible();

	void FinishResume();
	void ActResumeDecoders(bool need_notify);
	void ActRewind(int64_t rewind_time_ns);
	void ActDecoderFlush(FlushAction action);
	void FlushDecoder(bool shut_down);
	void ActReset();
	void ActPendingActions();

	void postScanSources();

	void NotifyRewindComplete();

	void OnSourceNotify(const sptr<Message> &msg);

	void OnSetSpeed(float speed, float pitch);

	void OnSetVolume(float left, float right);

	void OnInvoke(const sptr<Message> &msg);

	DISALLOW_COPY_AND_MOVE(PlayerCore);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_CORE_H
