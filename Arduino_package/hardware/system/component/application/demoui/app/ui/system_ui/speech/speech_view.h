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

#ifndef AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_VIEW_H
#define AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_VIEW_H

#include "app_common.h"

class SpeechView
{
public:
	void Create(lv_obj_t *parent);
	void Del();
	void Update(int32_t n);

public:
	struct {
		lv_obj_t *root;
		lv_obj_t *image;
	} Ui;
};

#endif // AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_VIEW_H
