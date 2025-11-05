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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_AUDIO_SETTINGS_AUDIO_VIEW_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_AUDIO_SETTINGS_AUDIO_VIEW_H

#include "app_common.h"

namespace Page
{

class AudioSettingsView
{
public:
	void Create(lv_obj_t *root);
	void Mute(bool mute);
	void MuteMedia(bool mute);
	void MuteTTS(bool mute);
	void MuteBeep(bool mute);

public:
	struct {
		lv_obj_t *panel_direction_left;
		lv_obj_t *image_direct_left;
		lv_obj_t *label_title;
		lv_obj_t *panel_mute_switch;
		lv_obj_t *label_mute;
		lv_obj_t *switch_mute;
		lv_obj_t *panel_media_volume;
		lv_obj_t *label_media_volume;
		lv_obj_t *slider_media_volume;
		lv_obj_t *panel_media_volume_icon;
		lv_obj_t *image_media_volume_icon;
		lv_obj_t *panel_tts_volume;
		lv_obj_t *label_tts_volume;
		lv_obj_t *slider_tts_volume;
		lv_obj_t *panel_tts_volume_icon;
		lv_obj_t *image_tts_volume_icon;
		lv_obj_t *panel_beep_volume;
		lv_obj_t *label_beep_volume;
		lv_obj_t *slider_beep_volume;
		lv_obj_t *panel_beep_volume_icon;
		lv_obj_t *image_beep_volume_icon;
	} Ui;
};

}

#endif // AMEBA_APPS_PANGU_APP_UI_PAGES_AUDIO_SETTINGS_AUDIO_VIEW_H
