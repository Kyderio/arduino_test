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

#ifndef AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_PRESENTER_H
#define AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_PRESENTER_H

#include "speech_view.h"
#include "speech_model.h"

class SpeechListenerImpl;

class SpeechPresenter
{
public:
	SpeechPresenter(lv_obj_t *parent);
	~SpeechPresenter();
	void Init();
	void Play();
	void Stop();

private:
	static void OnUpdate(lv_timer_t *timer);
	static void OnEvent(lv_event_t *event);
	void AttachEvent(lv_obj_t *obj);
	void Release();

private:
	SpeechView         view_;
	SpeechModel        model_;
	lv_obj_t          *root_;
	int32_t            count_;
	lv_timer_t        *play_timer_;
	SpeechListenerImpl *impl_;

};

#endif // AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_VR_PRESENTER_H
