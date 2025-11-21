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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_CLOCK_DETAIL_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_CLOCK_DETAIL_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class ClockDetailView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t *clock_detail_root;
		lv_obj_t *clock_detail_cancel_button;
		lv_obj_t *clock_detail_ok_button;
		lv_obj_t *clock_detail_hour_time_roller;
		lv_obj_t *clock_detail_hour_label;
		lv_obj_t *clock_detail_minute_time_roller;
		lv_obj_t *clock_detail_minute_label;
		lv_obj_t *clock_detail_roller_line[2];
		lv_obj_t *clock_detail_settings_area;
		lv_obj_t *clock_detail_settings_title;
		lv_obj_t *clock_detail_settings_day_btn[7];
		lv_obj_t *clock_detail_settings_day_label[7];
		lv_obj_t *clock_detail_ringtone_area;
		lv_obj_t *clock_detail_ringtone_title;
		lv_obj_t *clock_detail_ringtone_line;
		lv_obj_t *clock_detail_ringtone_switch;
		lv_obj_t *clock_detail_ringtone_info;
		lv_obj_t *clock_detail_ringtone_info_detail;
		lv_obj_t *clock_detail_ringtone_info_detail_image;
	} Ui;
};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_CLOCK_DETAIL_VIEW_H
