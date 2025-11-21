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

#ifndef AMEBA_APPS_PANGU_UTILS_PAGE_BASE_PRIV_H
#define AMEBA_APPS_PANGU_UTILS_PAGE_BASE_PRIV_H

#include "ui/page/page_base.h"

typedef struct {
	uint8_t type;
	uint16_t time;
	lv_anim_path_cb_t path;
} AnimAttr;

struct PageBasePriv {
	bool req_enable_cache;
	bool is_cached;
	PageBase::Stash stash;
	int32_t State;
	uint8_t launch_mode;
	struct {
		bool is_enter;
		bool is_busy;
		AnimAttr attr;
	} Anim;
	lv_coord_t first_x;
	lv_coord_t first_y;
} ;

#endif /* AMEBA_APPS_PANGU_UTILS_PAGE_BASE_PRIV_H */
