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

#ifndef SYSTEM_UI_MENU_PRESENTER_H
#define SYSTEM_UI_MENU_PRESENTER_H

#include "app2/ui/app_common.h"

#include "menu_view.h"

class Menu
{
public:
	bool pop_status_;
	bool disappear_status_;
	PageManager *manager_;

public:
	Menu(lv_obj_t *parent, PageManager *manager);
	~Menu();
	void Init();
	void Popup();
	void Disappear();

private:
	static void OnTimer(lv_timer_t *timer);
	static void OnEvent(lv_event_t *event);
	static void OnDisppearFinish(lv_anim_t *a);
	static void OnPopUpFinish(lv_anim_t *a);
	static void LvAnimCallbackSetY(void *obj, int32_t v);
	void        AttachEvent(lv_obj_t *obj);
	void        Hide();

private:
	MenuView   view_;
	lv_obj_t  *root_;

};

#endif // SYSTEM_UI_MENU_PRESENTER_H
