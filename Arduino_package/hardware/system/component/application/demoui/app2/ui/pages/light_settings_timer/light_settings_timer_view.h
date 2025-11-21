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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_TIMER_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_TIMER_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class LightSettingsTimerView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t* light_settings_timer_root;
		lv_obj_t* light_settings_timer_title_lable;
		lv_obj_t* light_settings_timer_back;
		lv_obj_t* light_settings_timer_back_image;
		lv_obj_t** light_settings_timer_area_list;
		lv_obj_t** light_settings_timer_remind_lable_list;
		lv_obj_t** light_settings_timer_info_lable_list;
		lv_obj_t** light_settings_timer_switch_list;
		lv_obj_t* light_settings_timer_add_button_bg;
		lv_obj_t* light_settings_timer_add_button;
	} Ui;
};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_TIMER_VIEW_H
