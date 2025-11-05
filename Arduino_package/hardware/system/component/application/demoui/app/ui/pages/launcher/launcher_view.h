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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_VIEW_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_VIEW_H

#include "app_common.h"
#include "pages/launcher/scrollviews/settings/settings.h"
#include "pages/launcher/scrollviews/music/music.h"
#include "pages/launcher/scrollviews/home/home.h"

namespace Page
{

class LauncherView
{

public:
	LauncherView();
	~LauncherView();
	void Create(PageBase *page, lv_obj_t *root);
	void Start(const char *name);
	void Del();
	void SaveLastChild();

private:
	const char *scroll_view_last_;
	void       *scroll_view_;
	Home       *home_;
	Settings   *settings_;
	Music      *music_;

};
}

#endif // AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_VIEW_H
