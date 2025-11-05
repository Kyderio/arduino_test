/*
 * Copyright (c) 2022 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless reqUired by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_UI_MENU_VIEW_H
#define SYSTEM_UI_MENU_VIEW_H

#include "lvgl.h"

class MenuView
{
public:
	void Create(lv_obj_t *parent);
	void Del();

public:
	struct {
		lv_obj_t *menu_root;
		lv_obj_t *panel_home;
		lv_obj_t *icon_home;
		lv_obj_t *lable_home;
		lv_obj_t *panel_light;
		lv_obj_t *icon_light;
		lv_obj_t *lable_light;
		lv_obj_t *panel_air_condition;
		lv_obj_t *icon_air_condition;
		lv_obj_t *lable_air_condition;
		lv_obj_t *panel_clock;
		lv_obj_t *icon_clock;
		lv_obj_t *lable_clock;
		lv_obj_t *panel_settings;
		lv_obj_t *icon_settings;
		lv_obj_t *lable_settings;
	} Ui;
};

#endif // SYSTEM_UI_OTA_VIEW_H
