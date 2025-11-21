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

#ifndef AMEBA_APPS_PANGU_UTILS_RESOURCE_MANAGER_CLIENT_H
#define AMEBA_APPS_PANGU_UTILS_RESOURCE_MANAGER_CLIENT_H

#include <vector>

#include "ui/resource/resource_manager.h"

class ResourceManagerClient : public ResourceManager
{
public:
	ResourceManagerClient();
	~ResourceManagerClient();

	bool        AddResource(const char *name, void *ptr);
	void       *GetResource(const char *name);
	bool        RemoveResource(const char *name);
	bool        LoadImage(const char *file_name, const char *resource_name);
	void        SetDefaultFont(void *ptr);
	void       *GetDefaultFont();

private:
	typedef struct ResourceNode {
		const char *name;
		void *ptr;

		bool operator==(const struct ResourceNode n) const
		{
			return (this->name == n.name && this->ptr == n.ptr);
		}
	} ResourceNode_t;

private:
	std::vector<ResourceNode_t> NodePool;
	void *DefaultPtr;
	bool SearchNode(const char *name, ResourceNode_t *node);
};

#endif //AMEBA_APPS_PANGU_UTILS_RESOURCE_MANAGER_CLIENT_H
