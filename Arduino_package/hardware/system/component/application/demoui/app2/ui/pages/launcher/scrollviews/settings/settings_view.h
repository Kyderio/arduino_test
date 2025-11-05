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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_SETTINGS_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_SETTINGS_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class SettingsView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t *settings_root;
		lv_obj_t *settings_title_lable;
		lv_obj_t *settings_listview;
		lv_obj_t *settings_listview_line[7];
		lv_obj_t *settings_wifi_item;
		lv_obj_t *settings_wifi_circle;
		lv_obj_t *settings_wifi_image;
		lv_obj_t *settings_wifi_lable;
		lv_obj_t *settings_wifi_ssid;
		lv_obj_t *settings_wifi_enter;
		lv_obj_t *settings_speech_item;
		lv_obj_t *settings_speech_circle;
		lv_obj_t *settings_speech_image;
		lv_obj_t *settings_speech_lable;
		lv_obj_t *settings_speech_enter;
		lv_obj_t *settings_account_item;
		lv_obj_t *settings_account_circle;
		lv_obj_t *settings_account_image;
		lv_obj_t *settings_account_lable;
		lv_obj_t *settings_account_enter;
		lv_obj_t *settings_display_item;
		lv_obj_t *settings_display_circle;
		lv_obj_t *settings_display_image;
		lv_obj_t *settings_display_lable;
		lv_obj_t *settings_display_enter;
		lv_obj_t *settings_individuation_item;
		lv_obj_t *settings_individuation_circle;
		lv_obj_t *settings_individuation_image;
		lv_obj_t *settings_individuation_lable;
		lv_obj_t *settings_individuation_enter;
		lv_obj_t *settings_voice_item;
		lv_obj_t *settings_voice_circle;
		lv_obj_t *settings_voice_image;
		lv_obj_t *settings_voice_lable;
		lv_obj_t *settings_voice_enter;
		lv_obj_t *settings_guide_item;
		lv_obj_t *settings_guide_circle;
		lv_obj_t *settings_guide_image;
		lv_obj_t *settings_guide_lable;
		lv_obj_t *settings_guide_enter;
	} Ui;

private:

};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_SETTINGS_VIEW_H
