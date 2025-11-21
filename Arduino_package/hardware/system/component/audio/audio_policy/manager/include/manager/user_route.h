/*
 * Copyright (c) 2025 Realtek, LLC.
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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_MANAGER_SESSION_ROUTE_H
#define AMEBA_COMPONENT_AUDIO_POLICY_MANAGER_SESSION_ROUTE_H

#include <stdint.h>
#include <map>
#include <string>

#include "audio/utils/base_type.h"

#include "osal_cxx/refptr.h"

namespace ameba::audio
{

class DevicePort;

class UserRoute : public RefPtr {
public:
    //todo input
    UserRoute(AudioSessionId session,
                 int32_t        category,
                 sptr<DevicePort> device_desc)
        : session_(session),
          device_desc_(device_desc),
          changed_(false),
          category_(category) {}

    bool IsActive() {
        return (device_desc_ != 0);
    }

    AudioSessionId              session_;
    sptr<DevicePort>            device_desc_;
    bool                        changed_;
    int32_t                     category_;
};

class UserRouteMap : public RefPtr {
public:
    UserRouteMap() {}
    ~UserRouteMap() {}

    bool HasRoute(AudioSessionId session);
    void RemoveRoute(AudioSessionId session);
    void AddRoute(AudioSessionId session,
                  int32_t category,
                  sptr<DevicePort> device_desc);

private:
    std::map<AudioSessionId, sptr<UserRoute>> route_map_;
};

}

#endif