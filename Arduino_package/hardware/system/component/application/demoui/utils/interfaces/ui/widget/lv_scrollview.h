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
 * @file lv_scrollview.h
 *
 * @brief Defines the interfaces for the lv widget scrollview.
 *
 * @since 1.0
 * @version 1.0
 *
 */

#ifndef AMEBA_APPS_PANGU_UTILS_WIDGET_LV_SCROLL_VIEW_H
#define AMEBA_APPS_PANGU_UTILS_WIDGET_LV_SCROLL_VIEW_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief The status of lv scrollview child.
 */
typedef enum {
	NONE,
	INACTIVE,
	ACTIVE,
} lv_scrollview_status_t;

/**
 * @brief Create a lv scrollview.
 *
 * @param parent Indicates the pointer of parent of all the object.
 * @param size_x_ Indicates the child size of the x order.
 * @param size_y_ Indicates the child size of the y order.
 * @return Returns the pointer of the scrollview object.
 *
 * @since 1.0
 * @version 1.0
 */
void   *lv_scrollview_create(lv_obj_t *parent, int32_t size_x_, int32_t size_y_);

/**
 * @brief Add a scrollview child into the scrollview.
 *
 * @param root Indicates the pointer of the scrollview.
 * @param name Indicates the name of the scrollview child.
 * @param x Indicates the position of the y order.
 * @param y Indicates the position of the y order.
 * @param scroll_dir Indicates the scroll direction permission.
 * @return Returns the pointer of the scrollview child object.
 *
 * @since 1.0
 * @version 1.0
 */
lv_obj_t   *lv_scrollview_add_child(void *scroll_view_handler, lv_obj_t *root, const char *name, int32_t x, int32_t y, lv_dir_t scroll_dir);

/**
 * @brief Set a special scrollview child activity.
 *
 * @param name Indicates the name of the scrollview child.
 *
 * @since 1.0
 * @version 1.0
 */
void        lv_scrollview_set_act(void *scroll_view_handler, const char *name);

/**
 * @brief Get the activity scrollview child.
 *
 * @return Returns the name of the scrollview child.
 *
 * @since 1.0
 * @version 1.0
 */
const char *lv_scrollview_get_child_act(void *scroll_view_handler);

/**
 * @brief Delete the scrollview.
 *
 * @since 1.0
 * @version 1.0
 */
void        lv_scrollview_del(void *scroll_view_handler);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // AMEBA_APPS_PANGU_UTILS_WIDGET_LV_SCROLL_VIEW_H
/** @} */
