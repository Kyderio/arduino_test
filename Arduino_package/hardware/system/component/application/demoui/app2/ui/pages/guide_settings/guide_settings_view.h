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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_GUIDE_SETTINGS_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_GUIDE_SETTINGS_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class GuideSettingsView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t *guide_settings_root;
		lv_obj_t *guide_settings_title_label;
		lv_obj_t *guide_settings_back;
		lv_obj_t *guide_settings_back_image;
		lv_obj_t *guide_settings_wake_up_training_area;
		lv_obj_t *guide_settings_wake_up_training_title;
		lv_obj_t *guide_settings_wake_up_training_line;
		lv_obj_t *guide_settings_wake_up_training_label;
		lv_obj_t *guide_settings_wake_up_clear_area;
		lv_obj_t *guide_settings_wake_up_clear_title;
		lv_obj_t *guide_settings_wake_up_clear_line;
		lv_obj_t *guide_settings_wake_up_clear_label;
		lv_obj_t *guide_settings_wake_up_start_area;
		lv_obj_t *guide_settings_wake_up_start_title;
		lv_obj_t *guide_settings_wake_up_start_line;
		lv_obj_t *guide_settings_wake_up_start_label;
	} Ui;
};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_GUIDE_SETTINGS_VIEW_H
