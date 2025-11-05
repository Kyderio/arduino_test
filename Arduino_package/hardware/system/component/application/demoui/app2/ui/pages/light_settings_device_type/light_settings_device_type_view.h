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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_DEVICE_VIEW_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_DEVICE_VIEW_H

#include "app2/ui/app_common.h"

namespace Page
{

class LightSettingsDeviceTypeView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t* light_settings_device_type_root;
		lv_obj_t* light_settings_device_type_title_lable;
		lv_obj_t* light_settings_device_type_back;
		lv_obj_t* light_settings_device_type_back_image;
		lv_obj_t* light_settings_device_type_area;
		lv_obj_t* light_settings_device_type_cont;
		lv_obj_t* light_settings_device_type_btn[12];
		lv_obj_t* light_settings_device_type_image_area[12];
		lv_obj_t* light_settings_device_type_image[12];
		lv_obj_t* light_settings_device_type_label[12];
		lv_obj_t* light_settings_device_type_ok_btn;
	} Ui;
};

}

#endif // AMEBA_APPS_IOT_APP_UI_PAGES_LIGHT_SETTINGS_DEVICE_VIEW_H
