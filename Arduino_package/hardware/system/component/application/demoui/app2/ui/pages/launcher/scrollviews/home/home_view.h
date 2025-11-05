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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_HOME_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_HOME_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class HomeView
{
public:
	void Create(lv_obj_t *root);
	void UpdateTime(char *time);
	void UpdateDay(char *time);

public:
	struct {
		lv_obj_t *home_root;
		lv_obj_t *time_lable;
		lv_obj_t *location_lable;
		lv_obj_t *temperature_lable;
		lv_obj_t *temperature_unit_lable;
		lv_obj_t *weather_lable;
		lv_obj_t *date_lable;
		lv_obj_t *week_lable;
		lv_obj_t *light_all_turn_on;
		lv_obj_t *light_all_turn_on_lable;
		lv_obj_t *light_all_turn_off;
		lv_obj_t *light_all_turn_off_lable;
		lv_obj_t *light_main_area;
		lv_obj_t *light_main_circle;
		lv_obj_t *light_main_image;
		lv_obj_t *light_main_lable;
		lv_obj_t *light_main_lable_status;
		lv_obj_t *light_main_lable_button;
		lv_obj_t *light_strip_area;
		lv_obj_t *light_strip_circle;
		lv_obj_t *light_strip_image;
		lv_obj_t *light_strip_lable;
		lv_obj_t *light_strip_lable_status;
		lv_obj_t *light_strip_lable_button;
		lv_obj_t *light_spot_area;
		lv_obj_t *light_spot_circle;
		lv_obj_t *light_spot_image;
		lv_obj_t *light_spot_lable;
		lv_obj_t *light_spot_lable_status;
		lv_obj_t *light_spot_lable_button;

	} Ui;

private:

};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_HOME_VIEW_H
