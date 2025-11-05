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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_COMMON_MIX_PORT_H
#define AMEBA_COMPONENT_AUDIO_POLICY_COMMON_MIX_PORT_H

#include <stdint.h>
#include <string>

#include "osal_cxx/refptr.h"

#include "ameba_audio_policy_configs.h"

#include "common/audio_port.h"
#include "common/device_port.h"

namespace ameba::audio
{
class HwCard;
class DeviceVector;
class DevicePort;

class MixPort : public AudioPort
{
public:
    MixPort(std::string name, AudioPortRole role);
    virtual ~MixPort();

    bool CheckConfigs(enum AudioHwDevice device,
                                std::string address,
                                uint32_t rate,
                                uint32_t *refined_rate,
                                enum AudioHwFormat format,
                                enum AudioHwFormat *refined_format,
                                int32_t channels,
                                int32_t *refined_channel,
                                uint32_t flags);

    int32_t AddSupportedDevice(sptr<DevicePort> device);
    void    Dump();

    sptr<DeviceVector> supported_devices_;
};

}

#endif  // AMEBA_COMPONENT_AUDIO_POLICY_COMMON_MIX_PORT_H