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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_AIR_CONDITION_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_AIR_CONDITION_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class AirContionView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t *air_condition_root;
		lv_obj_t *air_condition_title_lable;
		lv_obj_t *air_condition_switch;
		lv_obj_t *air_condition_lmeter_bg;
		lv_obj_t *air_condition_lmeter;
		lv_obj_t *air_condition_spinbox;
		lv_obj_t *air_condition_btn_plus;
		lv_obj_t *air_condition_btn_minus;
		lv_obj_t *air_condition_mode_lable;
		lv_obj_t *air_condition_cooling_area;
		lv_obj_t *air_condition_cooling_circle;
		lv_obj_t *air_condition_cooling_circle_bg;
		lv_obj_t *air_condition_cooling_icon;
		lv_obj_t *air_condition_cooling_lable;
		lv_obj_t *air_condition_warning_area;
		lv_obj_t *air_condition_warning_circle;
		lv_obj_t *air_condition_warning_circle_bg;
		lv_obj_t *air_condition_warning_icon;
		lv_obj_t *air_condition_warning_lable;
		lv_obj_t *air_condition_xeransis_area;
		lv_obj_t *air_condition_xeransis_circle;
		lv_obj_t *air_condition_xeransis_circle_bg;
		lv_obj_t *air_condition_xeransis_icon;
		lv_obj_t *air_condition_xeransis_lable;
		lv_obj_t *air_condition_auto_area;
		lv_obj_t *air_condition_auto_circle;
		lv_obj_t *air_condition_auto_circle_bg;
		lv_obj_t *air_condition_auto_icon;
		lv_obj_t *air_condition_auto_lable;
		lv_obj_t *air_condition_blowing_area;
		lv_obj_t *air_condition_blowing_circle;
		lv_obj_t *air_condition_blowing_circle_bg;
		lv_obj_t *air_condition_blowing_icon;
		lv_obj_t *air_condition_blowing_lable;
		lv_obj_t *air_condition_wind_speed_area;
		lv_obj_t *air_condition_wind_speed_circle;
		lv_obj_t *air_condition_wind_speed_circle_bg;
		lv_obj_t *air_condition_wind_speed_icon;
		lv_obj_t *air_condition_wind_speed_lable;
		lv_obj_t *air_condition_swing_area;
		lv_obj_t *air_condition_swing_circle;
		lv_obj_t *air_condition_swing_circle_bg;
		lv_obj_t *air_condition_swing_icon;
		lv_obj_t *air_condition_swing_lable;
		lv_obj_t *air_condition_display_area;
		lv_obj_t *air_condition_display_circle;
		lv_obj_t *air_condition_display_circle_bg;
		lv_obj_t *air_condition_display_icon;
		lv_obj_t *air_condition_display_lable;
	} Ui;

private:

};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_AIR_CONDITION_VIEW_H
