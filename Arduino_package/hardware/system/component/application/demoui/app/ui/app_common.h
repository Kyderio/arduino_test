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

#ifndef AMEBA_APPS_PANGU_APP_UI_APP_COMMON_H
#define AMEBA_APPS_PANGU_APP_UI_APP_COMMON_H

#include "ui/page/page_manager.h"
#include "ui/widget/lv_scrollview.h"
#include "resource/resource_pool.h"

#include "lvgl.h"

#define ARRAY_SIZE(arr)         (sizeof(arr)/sizeof(arr[0]))

#define HOME                    "ScrollViewChild/Home"
#define SETTINGS                "ScrollViewChild/Settings"
#define MUSIC                   "ScrollViewChild/Music"

#define COLOR_GRAY              lv_color_hex(0x333849)
#define COLOR_LIGHT_GRAY        lv_color_hex(0x5F6370)
#define COLOR_ORANGE            lv_color_hex(0xff931e)
#define COLOR_BLUE              lv_color_hex(0x436EEE)

#endif // AMEBA_APPS_PANGU_APP_UI_APP_COMMON_H
