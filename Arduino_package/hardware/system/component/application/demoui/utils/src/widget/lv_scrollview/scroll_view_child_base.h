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

#ifndef AMEBA_APPS_PANGU_UTILS_WIDGET_SCROLL_VIEW_CHILD_BASE_H
#define AMEBA_APPS_PANGU_UTILS_WIDGET_SCROLL_VIEW_CHILD_BASE_H

#include "lvgl.h"

class ScrollView;

class ScrollViewChildBase
{
public:
	lv_obj_t   *root_;
	ScrollView *scroll_view_;
	const char *name_;
	lv_dir_t    scroll_dir_;
	int32_t     pos_x_;
	int32_t     pos_y_;
	lv_obj_t   *parent_root_;

	/* private data, Only page manager access */
	struct {
		lv_coord_t first_x;
		lv_coord_t first_y;
		int32_t    move_pos;
		int32_t    is_enter;
	} Priv;
};

#endif // AMEBA_APPS_PANGU_UTILS_WIDGET_SCROLL_VIEW_CHILD_BASE_H
