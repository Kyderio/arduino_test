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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_COMMON_CONFIG_LOADER_H
#define AMEBA_COMPONENT_AUDIO_POLICY_COMMON_CONFIG_LOADER_H

#include <stdint.h>

#include "osal_cxx/refptr.h"

namespace ameba::audio
{

class HwCard;
class DeviceVector;
class DevicePort;
class HwCardCollection;

class ConfigLoader : public RefPtr {
public:
    ConfigLoader() {}
    ~ConfigLoader() {}

    virtual int32_t LoadHwCards(sptr<HwCardCollection> &hw_cards,
                        sptr<DeviceVector> &available_input_devices,
                        sptr<DeviceVector> &available_output_devices,
                        sptr<DevicePort> &default_output_device) = 0;
};

}

#endif  // AMEBA_COMPONENT_AUDIO_POLICY_COMMON_CONFIG_LOADER_H