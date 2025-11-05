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

#ifndef AMEBA_APPS_PANGU_APP_UI_BOOT_ANIMATION_PRESENTER_H
#define AMEBA_APPS_PANGU_APP_UI_BOOT_ANIMATION_PRESENTER_H

#include "boot_animation_view.h"

class BootAnimation;


class BootAnimationCallback
{
public:
	virtual      ~BootAnimationCallback();
	virtual void OnBootAnimationStatusChange(int32_t ani_status) = 0;
};

class BootAnimation
{
public:
	typedef enum {
		ANIMATION_CREATE,
		ANIMATION_START,
		ANIMATION_FINISH,
	} Animation_status_t;

public:
	BootAnimation();
	~BootAnimation();
	void RegisterBootAnimationCallback(BootAnimationCallback *callback);
	void UnRegisterBootAnimationCallback(BootAnimationCallback *callback);
	void PlayBootAnimation();

private:
	static void OnTimer(lv_timer_t *timer);

private:
	BootAnimationView      view_;
	BootAnimationCallback *callback_;
};

#endif //AMEBA_APPS_PANGU_APP_UI_BOOT_ANIMATION_PRESENTER_H
