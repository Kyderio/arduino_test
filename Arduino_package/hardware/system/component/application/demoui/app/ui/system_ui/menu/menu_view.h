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
		lv_obj_t *root;
		lv_obj_t *panel_home;
		lv_obj_t *icon_home;
		lv_obj_t *lable_home;
		lv_obj_t *panel_music;
		lv_obj_t *icon_music;
		lv_obj_t *lable_music;
		lv_obj_t *panel_settings;
		lv_obj_t *icon_settings;
		lv_obj_t *lable_settings;
	} Ui;
};

#endif // SYSTEM_UI_OTA_VIEW_H
