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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_RESET_VIEW_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_RESET_VIEW_H

#include "app_common.h"

namespace Page
{

class ResetView
{
public:
	void Create(lv_obj_t *root);

public:
	struct {
		lv_obj_t *panel_direction_left;
		lv_obj_t *image_direct_left;
		lv_obj_t *label_title;
		lv_obj_t *panel_reset;
		lv_obj_t *label_reset;
		lv_obj_t *btn_cancel;
		lv_obj_t *btn_ok;
	} Ui;
};

}

#endif // AMEBA_APPS_PANGU_APP_UI_PAGES_RESET_VIEW_H
