/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from PanKore
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_FWK_INCLUDE_TRACK_SHARED_H
#define AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_FWK_INCLUDE_TRACK_SHARED_H

#include <stdint.h>
#include <sys/types.h>
#include <time.h>

#include "audio/utils/minifloat.h"
#include "state_squeue.h"
//#include "osal_c/osal_sem.h"
#include "osal_c/osal_time.h"
#include "osal_cxx/threads.h"
#include "log/log.h"
#include "osal_cxx/refptr.h"
#include "raw_resampler_public.h"

//#define USE_C_CONDITION

#ifdef USE_C_CONDITION
#include "osal_c/osal_condition.h"
#else
#include "osal_cxx/mutex.h"
#include "osal_cxx/condition.h"
#endif

//#define   INT_MAX     0x7fffffff

//#define USE_SYSCALL;

namespace ameba::audio
{

// ----------------------------------------------------------------------------

#define SHARE_MEM_UNDERRUN   0x01
#define SHARE_MEM_FORCEREADY 0x02
#define SHARE_MEM_INVALID    0x04
#define SHARE_MEM_DISABLED   0x08
#define SHARE_MEM_LOOP_CYCLE 0x20
#define SHARE_MEM_LOOP_FINAL 0x40
#define SHARE_MEM_BUFFER_END 0x80
#define SHARE_MEM_OVERRUN   0x100
#define SHARE_MEM_INTERRUPT 0x200
#define SHARE_MEM_STREAM_END_DONE 0x400

#define MAX_RUN_OFFLOADED_TIMEOUT_MS 20000

struct ShareMemForTrackStreaming {
	volatile uint32_t read_ptr;
	volatile uint32_t write_ptr;
	volatile uint32_t flush_;
	//volatile int32_t read_ptr;
	//volatile int32_t write_ptr;
	//volatile int32_t flush_;
	volatile uint32_t underrun_frames;
};

typedef StateSQueue<AudioPlayRate> RateQueue;

// ----------------------------------------------------------------------------

struct share_mem_block {
//                            share_mem_block();
//                /*virtual*/ ~share_mem_block() { }

	uint64_t    server;
	uint32_t    pad1_;
	volatile    uint32_t     futex_;
	//volatile    int32_t     futex_;

#define SHARE_MEM_FUTEX_WAKE 1

//private:

	uint32_t    minimun;
	float_gain_pack left_right_volume;
	uint32_t    sample_rate;
	RateQueue::Shared playback_rate_queue;

	uint16_t    send_level;
	uint16_t    pad2_;

	// effective size of the buffer
	volatile    uint32_t   buffer_size_in_frames_;
	// min frames in buffer to start streaming
	volatile    uint32_t   start_threshold_in_frames_;

public:

	volatile    uint32_t     flags;
	//volatile    int32_t     flags;
	//OsalSem     cblk_sem_;
#ifdef USE_C_CONDITION
	osal_mutex_t   cblk_mutex_;
	osal_cond_t cblk_cond_;
#else
	Mutex *cblk_mutex_;
	Condition *cblk_cond_;
#endif

public:
	union {
		ShareMemForTrackStreaming   streaming;
		//ShareMemForTrackStatic      shared_static;
		int                         align[8];
	} u;

};


class Agent : public RefPtr
{
protected:
	Agent(share_mem_block *cblk, void *buffers, size_t frame_count, size_t frame_size, bool is_out,
		  bool client_in_server);
	virtual ~Agent() { }

public:
	struct Buffer {
		size_t  frame_count;
		void   *raw_data;
		size_t  non_config;
	};

	size_t FrameCount() const
	{
		return frame_count_;
	}
	uint32_t GetStartThresholdInFrames() const;
	uint32_t SetStartThresholdInFrames(uint32_t startThresholdInFrames);

protected:

	share_mem_block *const   cblk_;
	void *const     buffers_;
	const size_t    frame_count_;
	const size_t    frame_size_;
	const size_t    frame_count_p2_;
	const bool      is_out_;
	const bool      client_in_server_;
	bool            is_shut_down_;
	size_t          unreleased_;
};

class ClientAgent : public Agent
{
public:
	ClientAgent(share_mem_block *cblk, void *buffers, size_t frame_count, size_t frame_size,
				bool is_out, bool client_in_server);
	virtual ~ClientAgent() { }

	//static const struct timespec forever_;
	//static const struct timespec non_blocking_;
	static const struct timespec forever_;
	static const struct timespec non_blocking_;

	int32_t     GetAvailableBuffer(Buffer *buffer, const struct timespec *requested = NULL,
								   struct timespec *elapsed = NULL);
	void        ReleaseBufferHandled(Buffer *buffer);
	//void        IPCDied();
	void        Interrupt();
	uint64_t    GetPosition()
	{
		return epoch_ + cblk_->server;
	}
	void        SetUnit(size_t uint)
	{
		epoch_ = uint;
	}
	void        SetMinVal(size_t minimum)
	{
		if (minimum > UINT32_MAX) {
			minimum = UINT32_MAX;
		}
		cblk_->minimun = (uint32_t) minimum;
	}
	virtual size_t  GetDisalign();
	size_t      GetUnit() const
	{
		return epoch_;
	}
	size_t      GetInFrames();

private:
	size_t      epoch_;
};

class TrackClientAgent : public ClientAgent
{
public:
	TrackClientAgent(share_mem_block *cblk, void *buffers, size_t frame_count,
					 size_t frame_size, bool client_in_server = false)
		: ClientAgent(cblk, buffers, frame_count, frame_size, true /*is_out*/,
					  client_in_server),
		  playback_rate_mutator_(&cblk->playback_rate_queue) { }
	virtual ~TrackClientAgent() { }

	void        SetSLevel(float sLevel)
	{
		cblk_->send_level = uint16_t(sLevel * 0x1000);
	}

	void        SetStereoVolume(float_gain_pack volume)
	{
		cblk_->left_right_volume = volume;
	}

	void        SetSampleRate(uint32_t sample_rate)
	{
		cblk_->sample_rate = sample_rate;
	}

	void        SetPlayRate(const AudioPlayRate &playbackRate)
	{
		playback_rate_mutator_.Insert(playbackRate);
	}

	virtual void Flush();

	virtual uint32_t    GetXrunFrameCount() const
	{
		return cblk_->u.streaming.underrun_frames;
	}

	bool        PlayDoneClear();

	bool        GetPlayDone() const;

	int32_t       WaitPlayDone(const struct timespec *requested);

private:
	RateQueue::Mutant   playback_rate_mutator_;
};


class RecordClientAgent : public ClientAgent
{
public:
	RecordClientAgent(share_mem_block *cblk, void *buffers, size_t frame_count,
					  size_t frame_size)
		: ClientAgent(cblk, buffers, frame_count, frame_size,
					  false /*is_out*/, false /*client_in_server*/) { }
	~RecordClientAgent() { }
};

class ServerAgent : public Agent
{
protected:
	ServerAgent(share_mem_block *cblk, void *buffers, size_t frame_count, size_t frame_size,
				bool is_out, bool client_in_server);
public:
	virtual ~ServerAgent() { }

	virtual int32_t    GetAvailableBuffer(Buffer *buffer, bool ack_flush = false);

	virtual void     ReleaseBufferHandled(Buffer *buffer);

protected:
	size_t      avail_to_client_;
	int32_t     flush_;
};

class TrackServerAgent : public ServerAgent
{
public:
	TrackServerAgent(share_mem_block *cblk, void *buffers, size_t frame_count,
					 size_t frame_size, bool client_in_server = false, uint32_t sample_rate = 0)
		: ServerAgent(cblk, buffers, frame_count, frame_size, true /*is_out*/, client_in_server),
		  playback_rate_observer_(&cblk->playback_rate_queue)
	{
		cblk_->sample_rate = sample_rate;
		playback_rate_ = AUDIO_PLAYBACK_RATE_DEFAULT;
	}
protected:
	virtual ~TrackServerAgent() { }

public:
	uint32_t            GetSampleRate() const
	{
		return cblk_->sample_rate;
	}
	uint16_t            GetSLevel() const
	{
		return cblk_->send_level;
	}
	float_gain_pack     GetStereoVolume() const
	{
		return cblk_->left_right_volume;
	}

	virtual size_t      FramesReady();

	virtual void        ReadyMThreads() { }

	bool                SetPlayDone();

	virtual void        XrunFrames(uint32_t frame_count);

	virtual uint32_t    GetXrunFrameCount() const
	{
		return cblk_->u.streaming.underrun_frames;
	}

	virtual uint64_t    FramesHandled() const
	{
		return cblk_->server;
	}

	AudioPlayRate       GetPlaybackRate();

private:
	AudioPlayRate             playback_rate_;
	RateQueue::Viewer         playback_rate_observer_;
};

class RecordServerAgent : public ServerAgent
{
public:
	RecordServerAgent(share_mem_block *cblk, void *buffers, size_t frame_count,
					  size_t frame_size, bool client_in_server)
		: ServerAgent(cblk, buffers, frame_count, frame_size, false /*is_out*/, client_in_server) { }
protected:
	virtual ~RecordServerAgent() { }
};

// ----------------------------------------------------------------------------

}; // namespace ameba::audio

#endif // AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_FWK_INCLUDE_TRACK_SHARED_H
