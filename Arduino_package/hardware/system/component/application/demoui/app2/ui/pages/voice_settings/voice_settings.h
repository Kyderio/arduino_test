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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_VOICE_SETTINGS_PRESENTER_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_VOICE_SETTINGS_PRESENTER_H

#include "voice_settings_view.h"

namespace Page
{

class VoiceSettings : public PageBase
{
public:
	VoiceSettings();
	virtual      ~VoiceSettings();
	virtual void OnCustomAttrConfig();
	virtual void OnLoadView();
	virtual void OnViewWillAppear();
	virtual void OnViewDidAppear();
	virtual void OnViewWillDisappear();
	virtual void OnViewDidDisappear();
	virtual void OnUnloadView();

private:
	static void OnTimer(lv_timer_t *timer);
	static void OnEvent(lv_event_t *event);
	void        AttachEvent(lv_obj_t *obj);

private:
	VoiceSettingsView view_;
};

}

#endif //AMEBA_APPS_IOT_APP_UI_PAGES_VOICE_SETTINGS_PRESENTER_H
