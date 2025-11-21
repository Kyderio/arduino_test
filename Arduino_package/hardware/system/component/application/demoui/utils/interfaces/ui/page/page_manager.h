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
 * @file page_manager.h
 *
 * @brief Defines the structures and interfaces for the page manager.
 *
 * @since 1.0
 * @version 1.0
 *
 */

#ifndef AMEBA_APPS_PANGU_UTILS_PAGE_MANAGER_H
#define AMEBA_APPS_PANGU_UTILS_PAGE_MANAGER_H

#include "ui/page/page_base.h"
#include <vector>
#include <stack>

/**
 *  @brief Indicates the class to manager page.
 */
class PageManager
{
public:
	/**
	 *  @brief Indicates load animation type.
	*/
	typedef enum {
		LOAD_ANIM_GLOBAL = 0,
		LOAD_ANIM_OVER_LEFT,
		LOAD_ANIM_OVER_RIGHT,
		LOAD_ANIM_OVER_TOP,
		LOAD_ANIM_OVER_BOTTOM,
		LOAD_ANIM_MOVE_LEFT,
		LOAD_ANIM_MOVE_RIGHT,
		LOAD_ANIM_MOVE_TOP,
		LOAD_ANIM_MOVE_BOTTOM,
		LOAD_ANIM_FADE_ON,
		LOAD_ANIM_NONE,
		_LOAD_ANIM_LAST = LOAD_ANIM_NONE
	} LoadAnim;

public:

	/**
	  * @brief Create the page manager.
	  * @return Returns A pointer to the page manager.
	  *
	  * @since 1.0
	  * @version 1.0
	  */
	static  PageManager *CreatePageManager();

	/**
	  * @brief Page manager destructor.
	  *
	  * @since 1.0
	  * @version 1.0
	  */
	virtual              ~PageManager();

	/**
	  * @brief Register the page to page manager.
	  *
	  * @param page_base Indicates the pointer to the base class of the page.
	  * @param page_name Indicates the page name, no duplicates allowed.
	  * @return Returns a pointer to the base class of the page, or nullptr if wrong.
	  *
	  * @since 1.0
	  * @version 1.0
	  */
	virtual PageBase    *RegisterPage(PageBase *page_base, const char *page_name) = 0;

	/**
	 * @brief Unregister page from page manager.
	 *
	 * @param page_name Indicates the page name, no duplicates allowed.
	 * @return Returns true if the operation is successful.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual bool         UnRegisterPage(const char *page_name) = 0;

	/**
	 * @brief Make a new page appear.
	 *
	 * @param page_name Indicates the name of the page to enter.
	 * @param stash Indicates parameters passed to the new page.
	 * @return Returns the Pointer to the page pushed onto the stack.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual PageBase    *Start(const char *page_name, const PageBase::Stash *stash = nullptr) = 0;

	/**
	 * @brief Make the current page disappear.
	 *
	 * @return Returns the pointer to the next page.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual PageBase    *Finish() = 0;

	/**
	 * @brief Set global animation properties.
	 *
	 * @param anim Indicates the animation type.
	 * @param time Indicates the animation duration.
	 * @param path Indicates the animation curve.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void         SetGlobalLoadAnimType(int32_t anim, uint16_t time, lv_anim_path_cb_t path) = 0;
};

#endif // AMEBA_APPS_PANGU_UTILS_PAGE_MANAGER_H
/** @} */
