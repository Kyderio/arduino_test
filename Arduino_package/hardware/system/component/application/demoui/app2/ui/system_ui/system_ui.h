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

#ifndef AMEBA_APPS_IOT_APP_UI_SYSTEM_UI
#define AMEBA_APPS_IOT_APP_UI_SYSTEM_UI

#include "app2/ui/system_ui/menu/menu.h"

#include "app2/ui/app_common.h"

class SystemUi
{
public:
	PageManager     *manager_;
	static SystemUi *GetInstance();
	void Init(PageManager *manager_);
	void PopupMenu();
    void DisappearMenu();

private:
	SystemUi();
	virtual ~SystemUi();

	void AttachEvent(lv_obj_t* obj);
    static void OnEvent(lv_event_t* event);

private:
	Menu*                  menu_;

};

#endif // AMEBA_APPS_IOT_APP_UI_SYSTEM_UI
