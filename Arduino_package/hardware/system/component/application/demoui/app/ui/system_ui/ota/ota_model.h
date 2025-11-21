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

#ifndef AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_OTA_MODEL_H
#define AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_OTA_MODEL_H

#include <stdint.h>
#include <stddef.h>
#include <sys/cdefs.h>

#include "ota/ota_manager.h"

using ameba::ota::OtaManager;

//namespace Page {
class OtaStateListenerImpl;

class OtaVersionListener
{
public:
	virtual void OtaVersionAvailable(const char *path) = 0;
	virtual     ~OtaVersionListener() = default;
};

class OtaModel
{
public:
	OtaModel();
	~OtaModel();

	void OtaVersionAvailable(const char *path);
	void InstallPackage(const char *path);
	void RegisterOtaVersionListener(OtaVersionListener *listener);
	void UnRegisterOtaVersionListener(OtaVersionListener *listener);

private:
	OtaVersionListener   *ota_version_listener_;
	OtaStateListenerImpl    *ota_listener_impl_;
	OtaManager *ota_manager_;
};

//}

#endif
