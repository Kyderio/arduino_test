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

/**
 * @addtogroup graphic
 * @{
 *
 * @brief Declares APIs for LVGL extra Library.
 *
 * @since 1.0
 * @version 1.0
 *
 */

/**
 * @file lv_anim_loading.h
 *
 * @brief Defines the interfaces for the lv widget loading animation.
 *
 * @since 1.0
 * @version 1.0
 *
 */

#ifndef AMEBA_APPS_PANGU_UTILS_LV_ANIM_LOADING_H
#define AMEBA_APPS_PANGU_UTILS_LV_ANIM_LOADING_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a lv timeline loading animation
 *
 * @param cont Indicates the pointer of parent of all the object.
 * @param logo Indicates the pointer of logo object.
 * @param start_time Indicates the start time of animation.
 * @param line Indicates the pointer of timeline object
 *
 * @since 1.0
 * @version 1.0
 */

void lv_anim_timeline_loading_create(lv_obj_t *cont, lv_obj_t *logo, uint32_t start_time,
									 lv_anim_timeline_t *line);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif //AMEBA_APPS_PANGU_UTILS_LV_ANIM_LOADING_H
/** @} */
