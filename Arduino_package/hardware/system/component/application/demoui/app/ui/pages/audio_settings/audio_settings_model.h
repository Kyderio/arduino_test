/*
 * Copyright (c) 2022 Realtek, LLC.
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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_AUDIO_SETTINGS_AUDIO_MODEL_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_AUDIO_SETTINGS_AUDIO_MODEL_H

#include <stdint.h>
#include <stddef.h>
#include <sys/cdefs.h>
#include <map>

struct AudioStateListenerImpl;
namespace Page
{

class VolumeListener
{
public:
	virtual void AudioVolumeChange(const char *group_name, uint32_t volume) = 0;
	virtual void AudioMuteChange(const char *group_name, bool mute) = 0;
	virtual     ~VolumeListener() = default;
};

class AudioSettingsModel
{
public:
	AudioSettingsModel();
	~AudioSettingsModel();

	void          SetGroupVolume(const char *group_name, uint32_t index);
	uint32_t      GetGroupVolume(const char *group_name);
	void          SetGroupMute(const char *group_name, bool mute);
	bool          GetGroupMute(const char *group_name);
	void          RegisterVolumeListener(VolumeListener *listener);
	void          UnRegisterVolumeListener(VolumeListener *listener);
	void          AudioVolumeChange(const char *group_name, uint32_t volume);
	void          AudioMuteChange(const char *group_name, bool mute);

public:
	static const constexpr char *media_group = "media";
	static const constexpr char *tts_group = "tts";
	static const constexpr char *beep_group = "beep";

private:
	std::map<char *, uint32_t>      group_volumes_;
	std::map<char *, uint32_t>      group_muted_;
	VolumeListener                *volume_listener_;
};

}

#endif
