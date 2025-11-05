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
 * @file resource_manager.h
 *
 * @brief Defines the structures and interfaces for the resource manager.
 *
 * @since 1.0
 * @version 1.0
 *
 */

#ifndef AMEBA_APPS_PANGU_UTILS_RESOURCE_MANAGER_H
#define AMEBA_APPS_PANGU_UTILS_RESOURCE_MANAGER_H

/**
 *  @brief Indicates the class to manager resource.
 */
class ResourceManager
{
public:
	/**
	 * @brief Create the resource manager.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	static ResourceManager *CreateResourceManager();

	/**
	 * @brief Destruct the resource manager.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual                 ~ResourceManager();

	/**
	 * @brief Add the resource into the resource manager.
	 *
	 * @param name Indicates the resource name add into the resource manger.
	 * @param ptr Indicates the pointer of resource.
	 * @return Returns the operation is success or not.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual bool              AddResource(const char *name, void *ptr) =  0;

	/**
	 * @brief Get the resource with a special name.
	 *
	 * @param name Indicates the resource name
	 * @return Returns the pointer of the resource content.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void             *GetResource(const char *name) = 0;

	/**
	 * @brief Remove the resource out of the resource manager.
	 *
	 * @param name Indicates the resource name.
	 * @return Returns the operation is success or not.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual bool              RemoveResource(const char *name) = 0;

	/**
	 * @brief Load the compress image resource.
	 *
	 * @param file_name Indicates the file name of the compress image resource.
	 * @param resource_name Indicates the resource name add into the resource manger.
	 * @return Returns the operation is success or not.
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual bool              LoadImage(const char *file_name, const char *resource_name) = 0;

	/**
	 * @brief Add the default font resource.
	 *
	 * @param ptr Indicates the pointer of the  font resource.
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void              SetDefaultFont(void *ptr) = 0;

	/**
	 * @brief Get the default font resource.
	 *
	 * @return Returns the pointer of default font resource
	 *
	 * @since 1.0
	 * @version 1.0
	 */
	virtual void             *GetDefaultFont() = 0;
};

#endif //AMEBA_APPS_PANGU_UTILS_RESOURCE_MANAGER_H
/** @} */
