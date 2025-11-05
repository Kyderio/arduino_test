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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_HOME_PRESENTER_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_HOME_PRESENTER_H

#include "home_view.h"
#include "home_model.h"

namespace Page
{

class Home
{
public:
	lv_obj_t *view_root_;

public:
	Home(PageManager *manager);
	~Home();

	void CreateView(lv_obj_t *root);
	void Start();
	void Stop();

private:
	void        UpdateTime();
	void        UpdateDay();
	void        AttachEvent(lv_obj_t *obj);
	static void OnTimerUpdate(lv_timer_t *timer);
	static void OnDayUpdate(lv_timer_t *timer);
	static void OnEvent(lv_event_t *event);

private:
	HomeView     view_;
	HomeModel    model_;
	lv_timer_t  *timer_;
	lv_timer_t  *day_timer_;
	PageManager *manager_;
};

}

#endif //AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_HOME_PRESENTER_H
