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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_PRESENTER_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_PRESENTER_H

#include "launcher_view.h"
#include "scrollviews/home/home.h"
#include "scrollviews/music/music.h"
#include "scrollviews/settings/settings.h"

namespace Page
{

class Launcher : public PageBase
{
public:

public:
	Launcher();
	virtual      ~Launcher();

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

private:
	LauncherView view_;
};

}

#endif //AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_PRESENTER_H