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

/**
 * Player
 * @{
 *
 * @brief Provides player interfaces for applications.
 *
 * These player interfaces can be used to control playback of audio files and streams,
 * register callback functions, and control the feature status.
 * Playback control includs start, stop, pause, resume, rewind and so on.
 *
 * @since 1.0
 * @version 1.0
 */

/**
 * @file player_driver_lite.h
 *
 * @brief Declares the player interfaces for managing playback.
 *
 * @since 1.0
 * @version 1.0
 */

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_DRIVER_LITE_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_DRIVER_LITE_H

#include <memory>

#include "osal_cxx/mutex.h"
#include "osal_cxx/condition.h"

#include "cutils/parcel.h"

#include "media/utils/nocopyable.h"
#include "media/rtplayer_lite.h"
#include "media/common/media_track.h"

namespace ameba::media
{

class MessageLooper;
class DataSource;
class AudioRenderSinkLite;
class PlayerCoreLite;

/**
 * @brief Provides player interfaces for applications.
 *
 * The interfaces can be used to perform basic operations of a playback, such as starting a playback,
 * pausing audio during playing, resuming audio after pausing, rewinding to a specific position during playing or pausing,
 * querying information about a specified playback, and registering callback to monitor playback status change.
 */
class PlayerDriverLite
{
public:
	explicit PlayerDriverLite(RTPlayerLite *rtplayer, AudioSinkTypes type);
	virtual ~PlayerDriverLite();

	res_t SetSource(const char *url);
	res_t Prepare();
	res_t PrepareAsync();
	res_t Start();
	res_t Stop();
	res_t Pause();
	bool IsPlaying();
	res_t Rewind(int64_t msec);
	res_t GetCurrentTime(int64_t *msec);
	res_t GetDuration(int64_t *msec);
	res_t Reset();
	void SetPlayerCallback(RTPlayerLiteCallback *callback);
	res_t SetVolume(float left, float right);
	res_t SetSpeed(float speed, float pitch);
	res_t Invoke(Parcel *request, Parcel *reply);

	void NotifySetSourceCompleted(res_t err);
	void NotifyPrepareCompleted(res_t err);
	void NotifyResetComplete();
	void NotifyDuration(int64_t duration_us);
	void NotifyRewindComplete();
	void NotifyFlagsChanged(uint32_t flags);

	void NotifyStateChanged(int state);
	void NotifyInfo(int info, int extra);
	void NotifyError(int error, int extra);

private:
	res_t PrepareInternal();
	res_t StartInternal();

	void SetAudioRenderSinkLite(const sptr<AudioRenderSinkLite> &audio_sink);
	void NotifyStateChangedInternal(int state);
	void NotifyInfoInternal(int info, int extra);
	void NotifyErrorInternal(int error, int extra);
	void NotifyRewindCompleteInternal();

private:
	enum State {
		STATE_IDLE,
		STATE_SET_DATASOURCE_PENDING,
		STATE_UNPREPARED,
		STATE_PREPARING,
		STATE_PREPARED,
		STATE_RUNNING,
		STATE_PAUSED,
		STATE_RESET_IN_PROGRESS,
		STATE_STOPPED,                  // equivalent to PAUSED
		STATE_STOPPED_AND_PREPARING,    // equivalent to PAUSED, but rewinding
		STATE_STOPPED_AND_PREPARED,     // equivalent to PAUSED, but rewind complete
	};

	std::string GetStateStr(State state);

	mutable Mutex lock_;
	Condition condition_;

	State state_;
	bool async_prepare_;
	res_t async_result_;

	// The following are protected through "lock_"
	int64_t duration_us_;
	int64_t position_us_;
	bool rewinding_;

	sptr<MessageLooper> looper_;
	const sptr<PlayerCoreLite> player_;
	uint32_t flags_;
	sptr<AudioRenderSinkLite> audio_sink_;
	RTPlayerLite *rtplayer_;
	RTPlayerLiteCallback *player_cb_;
	bool eos_;

	DISALLOW_COPY_AND_MOVE(PlayerDriverLite);
};
}  // namespace ameba::media

#endif // AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_PLAYER_DRIVER_LITE_H
