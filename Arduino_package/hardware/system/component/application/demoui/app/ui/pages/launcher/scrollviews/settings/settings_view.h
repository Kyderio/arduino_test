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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_SETTINGS_VIEW_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_SETTINGS_VIEW_H

#include "app_common.h"

namespace Page
{

class SettingsView
{
public:
    void Create(lv_obj_t* root);

public:
    struct
    {
        lv_obj_t* label_title;
        lv_obj_t* panel_wifi;
        lv_obj_t* icon_wifi;
        lv_obj_t* label_wifi;
        lv_obj_t* panel_audio;
        lv_obj_t* icon_audio;
        lv_obj_t* label_audio;
        lv_obj_t* panel_ota;
        lv_obj_t* icon_ota;
        lv_obj_t* label_ota;
        lv_obj_t* panel_info;
        lv_obj_t* icon_info;
        lv_obj_t* label_info;
    } Ui;

private:

};
}

#endif //AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_SETTINGS_VIEW_H
