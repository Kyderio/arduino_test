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

#ifndef AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_OTA_PRESENTER_H
#define AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_OTA_PRESENTER_H

#include "ota_view.h"
#include "ota_model.h"

class OtaVersionListenerImpl;

class Ota
{
public:
	Ota(lv_obj_t *parent);
	~Ota();
	void Init();
	void Popup();
	void Disappear();

private:
	static void OnTimer(lv_timer_t *timer);
	static void OnEvent(lv_event_t *event);
	void        AttachEvent(lv_obj_t *obj);

private:
	friend class OtaVersionListenerImpl;

	OtaView   view_;
	lv_obj_t *root_;
	OtaModel  model_;
	OtaVersionListenerImpl *impl_;
	char imagepath_[128];

};

#endif // AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_OTA_PRESENTER_H
