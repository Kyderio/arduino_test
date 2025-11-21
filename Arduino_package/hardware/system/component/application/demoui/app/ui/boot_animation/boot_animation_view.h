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

#ifndef AMEBA_APPS_PANGU_APP_UI_BOOT_ANIMATION_VIEW
#define AMEBA_APPS_PANGU_APP_UI_BOOT_ANIMATION_VIEW

#include "lvgl.h"

class BootAnimationView
{
public:
	void Create();
	void Del();

public:
	struct {
		lv_obj_t *root;
		lv_obj_t *cont;
		lv_obj_t *labelLogo;

		lv_anim_timeline_t *anim_timeline;
	} Ui;
};

#endif // AMEBA_APPS_PANGU_APP_UI_BOOT_ANIMATION_VIEW
