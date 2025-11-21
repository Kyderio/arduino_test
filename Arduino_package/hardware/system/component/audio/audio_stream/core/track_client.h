/*
 * Copyright (c) 2021 Realtek, LLC.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_FWK_INCLUDE_TRACK_CLIENT_H
#define AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_FWK_INCLUDE_TRACK_CLIENT_H

#include "osal_cxx/errors.h"
#include "osal_cxx/refptr.h"
#include "osal_c/osal_time.h"
#include "osal_c/osal_mutex.h"
#include "audio_system.h"
#include "audio/audio_time.h"
#include "audio/audio_track.h"
#include "raw_resampler_public.h"

namespace ameba::audio
{

struct share_mem_block;
class TrackClientAgent;
class OutTrack;

class TrackClient
{
public:
	class Buffer
	{
	public:

		size_t      frame_count;
		size_t      size;

		union {
			void       *raw;
			short      *i16;
			int8_t     *i8;
		};
	};

	TrackClient();
	~TrackClient();

	size_t        GetMinBufferFrames(uint32_t category_type, uint32_t sample_rate);
	size_t        GetMinBufferBytes(uint32_t category_type, uint32_t sample_rate, uint32_t format, uint32_t channel_count);
	res_t         Init(const RTAudioTrackConfig *config);

	res_t         SetFormat(uint32_t format);
	uint32_t      GetFormat() const
	{
		return format_;
	}
	uint32_t      GetCategory() const
	{
		return category_type_;
	}
	size_t        FrameCount() const
	{
		return frame_count_;
	}
	int32_t       SetStartThresholdInBytes(size_t bytes);
	int32_t       GetStartThresholdInBytes();
	res_t         Start();
	void          Stop();
	bool          Stopped() const;
	void          Flush();
	void          Pause();
	void          Release();
	res_t         SetVolume(float left, float right);
	res_t         SetVolume(float volume);
	float         GetVolume();
	res_t         SetMute(bool muted);
	bool          GetMuted();
	res_t         SetSampleRate(uint32_t sample_rate);
	uint32_t      GetSampleRate() const;
	uint32_t      GetOriginalSampleRate() const;
	res_t         SetChannelCount(uint32_t channel);
	uint32_t      GetChannelCount() const
	{
		return channel_count_;
	}
	void          UpdateLatencyLocked();
	uint32_t      GetLatency();
	res_t         GetPosition(uint32_t *position);
	res_t         GetAvailableBuffer(Buffer *track_buf, int32_t waitCount,
									 size_t *non_contig = NULL);
	void          ReleaseBufferHandled(const Buffer *track_buf);
	int32_t       Write(const void *buffer, size_t size, bool blocking = true);
	res_t         SetParameters(const char *params);
	char         *GetParameters(const char *keys);
	res_t         SetPlayRate(RTAudioPlaybackRate rate);
	res_t         GetPlaybackRate(RTAudioPlaybackRate *rate);
	res_t         GetTimestamp(RTAudioTimestamp *timestamp);

protected:
	TrackClient(const TrackClient &other);
	TrackClient   &operator = (const TrackClient &other);

	res_t         CreateTrackLocked();
	void          FlushLocked();
	res_t         RestoreTrackLocked(const char *from);
	uint32_t      UpdateAndGetPositionLocked();

private:

	res_t         GetAvailableBuffer(Buffer *track_buf, const struct timespec *requested,
									 struct timespec *elapsed = NULL, size_t *non_contig = NULL);

	sptr<OutTrack>          if_audio_track_;
	share_mem_block        *cblk_;

	float                   volume_[2];
	mutable uint32_t        sample_rate_;
	uint32_t                origin_sample_rate_;
	AudioPlayRate           playback_rate_;
	size_t                  frame_count_;
	size_t                  requested_frame_count_;

	uint32_t                format_;
	uint32_t                category_type_;
	uint32_t                channel_count_;

	size_t                  frame_size_;

	res_t                   status_;

	uint32_t                latency_;
	uint32_t                af_latency_;

	enum State {
		STATE_ACTIVE,
		STATE_STOPPED,
		STATE_PAUSED,
		STATE_PAUSED_STOPPING,
		STATE_FLUSHED,
		STATE_STOPPING,
	}                       track_state_;

	void                   *user_data_;

	uint32_t                noti_frames_request_;
	uint32_t                noti_frames_request__act_;

	uint64_t                server_;
	uint64_t                position_;
	uint64_t                released_;

	OSAL_DECLARE_MUTEX(lock_);

	sptr<TrackClientAgent>  client_proxy_;

	bool                    in_underrun_;

private:

	uint32_t                sequence_;

};

}; // namespace ameba::audio

#endif
