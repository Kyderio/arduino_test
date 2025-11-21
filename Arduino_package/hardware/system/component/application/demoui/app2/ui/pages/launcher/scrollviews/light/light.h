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

#ifndef AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_LIGHT_PRESENTER_H
#define AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_LIGHT_PRESENTER_H

#include "light_view.h"

namespace Page
{

class Light
{
public:
	lv_obj_t *view_root_;

public:
	Light(PageManager *manager);
	~Light();

	void CreateView(lv_obj_t *root);
	void Start();
	void Stop();

private:
	void AttachEvent(lv_obj_t *obj);
	static void OnEvent(lv_event_t *event);

private:
	LightView view_;
	PageManager *manager_;
};

}

#endif //AMEBA_APPS_IOT_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_LIGHT_PRESENTER_H
