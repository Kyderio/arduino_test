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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_ADD_TIMER_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_ADD_TIMER_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class LightSettingsAddTimerView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t* light_settings_add_timer_root;
		lv_obj_t* light_settings_add_timer_title_lable;
		lv_obj_t* light_settings_add_timer_back;
		lv_obj_t* light_settings_add_timer_back_image;
		lv_obj_t* light_settings_add_timer_info_area;
		lv_obj_t* light_settings_add_timer_info_title;
		lv_obj_t* light_settings_add_timer_info_day_btn[7];
		lv_obj_t* light_settings_add_timer_info_day_label[7];
		lv_obj_t* light_settings_add_timer_open_area;
		lv_obj_t* light_settings_add_timer_open_title;
		lv_obj_t* light_settings_add_timer_open_line;
		lv_obj_t* light_settings_add_timer_open_switch;
		lv_obj_t* light_settings_add_timer_open_time_title;
		lv_obj_t* light_settings_add_timer_open_time_info;
		lv_obj_t* light_settings_add_timer_open_time_title_detail;
		lv_obj_t* light_settings_add_timer_open_time_title_detail_image;
		lv_obj_t* light_settings_add_timer_close_area;
		lv_obj_t* light_settings_add_timer_close_title;
		lv_obj_t* light_settings_add_timer_close_line;
		lv_obj_t* light_settings_add_timer_close_switch;
		lv_obj_t* light_settings_add_timer_close_time_title;
		lv_obj_t* light_settings_add_timer_close_time_info;
		lv_obj_t* light_settings_add_timer_close_time_title_detail;
		lv_obj_t* light_settings_add_timer_close_time_title_detail_image;
        lv_obj_t* light_settings_add_timer_ok_btn;
		lv_obj_t* light_settings_add_timer_cancel_btn;
	} Ui;
};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_ADD_TIMER_VIEW_H
