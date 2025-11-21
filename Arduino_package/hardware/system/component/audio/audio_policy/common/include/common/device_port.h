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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_COMMON_DEVICE_PORT_H
#define AMEBA_COMPONENT_AUDIO_POLICY_COMMON_DEVICE_PORT_H

#include <stdint.h>
#include <vector>
#include <string>

#include "hardware/audio/audio_hw_types.h"

#include "common/audio_port.h"

namespace ameba::audio
{
class DevicePort : public AudioPort {
public:
    DevicePort(std::string name, enum AudioHwDevice type);
    virtual ~DevicePort() {}

    virtual void                    Attach(const sptr<HwCard>& module);
            AudioPortId             GetId();
            bool                    Equals(const sptr<DevicePort>& other);
            enum AudioHwDevice      Type() const { return device_type_; }
            void                    Dump();

private:
    enum AudioHwDevice  device_type_;
    AudioPortId         id_;
};

class DeviceVector : public RefPtr {
public:
    DeviceVector() : device_types_(AUDIO_HW_DEVICE_NONE) {}
    virtual ~DeviceVector() {}

            int32_t                 Add(sptr<DevicePort> device);
            int32_t                 Remove(sptr<DevicePort> device);
            int32_t                 IndexOf(const sptr<DevicePort>& device);
            sptr<DevicePort>        ValueAt(int32_t index);
            bool                    IsEmpty();
            int32_t                 Size();
            enum AudioHwDevice      Type() { return device_types_; }
            sptr<DevicePort>        GetDeviceFromName(const std::string name);
            sptr<DevicePort>        GetDeviceFromType(enum AudioHwDevice type);
            sptr<DeviceVector>      GetDevicesFromType(enum AudioHwDevice types);
            void                    RemoveDetachedDevice();
            void                    Dump();

private:
    void UpdateTypes();

    //todo, should we use std::set?
    std::vector<sptr<DevicePort>> device_vector_;
    enum AudioHwDevice device_types_;
};

}

#endif  // AMEBA_COMPONENT_AUDIO_POLICY_COMMON_DEVICE_PORT_H