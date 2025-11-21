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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_LIGHT_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_LIGHT_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class LightView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t *light_root;
		lv_obj_t *light_title_lable;
		lv_obj_t *light_all_turn_on;
		lv_obj_t *light_all_turn_on_lable;
		lv_obj_t *light_all_turn_off;
		lv_obj_t *light_all_turn_off_lable;
		lv_obj_t *light1_area;
		lv_obj_t *light1_circle;
		lv_obj_t *light1_image;
		lv_obj_t *light1_lable;
		lv_obj_t *light1_status_lable;
		lv_obj_t *light2_area;
		lv_obj_t *light2_circle;
		lv_obj_t *light2_image;
		lv_obj_t *light2_lable;
		lv_obj_t *light2_status_lable;
		lv_obj_t *light3_area;
		lv_obj_t *light3_circle;
		lv_obj_t *light3_image;
		lv_obj_t *light3_lable;
		lv_obj_t *light3_status_lable;
	} Ui;

private:

};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_LIGHT_VIEW_H
