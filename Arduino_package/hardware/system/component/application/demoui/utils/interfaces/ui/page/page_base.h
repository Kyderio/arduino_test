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
 * @file page_base.h
 *
 * @brief Defines the structures and interfaces for the page base.
 *
 * @since 1.0
 * @version 1.0
 *
 */

#ifndef AMEBA_APPS_PANGU_UTILS_PAGE_BASE_H
#define AMEBA_APPS_PANGU_UTILS_PAGE_BASE_H

#include "lvgl.h"

/**
 * @brief Generate stash area data
 */
#define AMEBA_APPS_PANGU_APP_UI_PAGES_STASH_MAKE(data) {&(data), sizeof(data)}

/**
 * @brief Get the data in the stash area
 */
#define AMEBA_APPS_PANGU_APP_UI_PAGES_STASH_POP(data)  this->GetStash(&(data), sizeof(data))

class PageManager;
typedef struct PageBasePriv PageBasePriv;

/**
 *  @brief Indicates the class of the page base.
 */
class PageBase
{
public:
	/**
	 *  @brief Indicates data stash in the page.
	*/
	typedef struct {
		void *ptr;
		uint32_t size;
	} Stash;

public:
	lv_obj_t      *root_;
	PageManager   *manager_;
	const char    *name_;
	PageBasePriv  *priv_;

public:
	/**
	 * @brief Destruct the page.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual      ~PageBase() {}

	/**
	 * @brief The Callback of the lifeCycle when the page added into page manger.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnCustomAttrConfig() {}

	/**
	 * @brief The Callback of the lifeCycle when the page is loaded in the first time.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnLoadView() {}

	/**
	 * @brief The Callback of the lifeCycle when the page will appear.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnViewWillAppear() {}

	/**
	 * @brief The Callback of the lifeCycle when the page appeared.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnViewDidAppear() {}

	/**
	 * @brief The Callback of the lifeCycle when the page will disappear.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnViewWillDisappear() {}

	/**
	 * @brief The Callback of the lifeCycle when the page disappeared.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnViewDidDisappear() {}

	/**
	 * @brief The Callback of the lifeCycle when the page finished which is not cache.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void OnUnloadView() {}

	/**
	 * @brief Set the cache status of the page.
	 *
	 * @param en Indicates the cache status.
	 * @return Returns the operation is success or not
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	void         SetCustomCacheEnable(bool en);

	/**
	 * @brief Set the loading animation type of the page.
	 *
	 * @param anim_type Indicates the loading animation type.
	 * @param time Indicates the last time of the animation.
	 * @param path Indicates the path of the animation.
	 * @return Returns the operation is success or not
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	void         SetCustomLoadAnimType(uint8_t anim_type, uint16_t time = 500,
									   lv_anim_path_cb_t path = lv_anim_path_ease_out);

	/**
	 * @brief Set the stash data of the page.
	 *
	 * @param ptr Indicates the pointer of the stash data.
	 * @param size Indicates the size of the stash data.
	 * @return Returns the operation is success or not
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	bool         GetStash(void *ptr, uint32_t size);
};

#endif // AMEBA_APPS_PANGU_UTILS_PAGE_BASE_H
/** @} */
