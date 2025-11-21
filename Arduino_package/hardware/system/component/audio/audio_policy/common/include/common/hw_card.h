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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_COMMON_HW_PORT_H
#define AMEBA_COMPONENT_AUDIO_POLICY_COMMON_HW_PORT_H

#include <stdint.h>
#include <string>
#include <vector>

#include "osal_cxx/refptr.h"

#include "ameba_audio_policy_configs.h"

#include "hardware/audio/audio_hw_card.h"

#include "common/device_port.h"

namespace ameba::audio
{
class MixPort;

class HwCard : public RefPtr
{
public:
    HwCard(std::string name);
    ~HwCard();

    AudioCardId  GetCardId() { return handle_; }
    int32_t      LoadMixPort(AudioConfigMixPort mix_port);
    int32_t      LoadDevice(AudioConfigDevicePort device_port);
    int32_t      LoadRoute(AudioConfigRoute route);
    void         Dump();

    std::string                    name_;
    AudioCardId                    handle_;
    std::vector< sptr<MixPort> >   output_mix_ports_;
    std::vector< sptr<MixPort> >   input_mix_ports_;
    sptr<DeviceVector>             declared_devices_;

private:
    sptr<MixPort> GetOutMixPortFromName(const std::string name);
    sptr<MixPort> GetInMixPortFromName(const std::string name);
};

class HwCardCollection : public RefPtr
{
public:
    HwCardCollection() {}
    ~HwCardCollection() {}

    sptr<HwCard>            GetHwCardFromName(const char *name);
    sptr<HwCard>            GetHwCardForDevice(enum AudioHwDevice device);
    sptr<DevicePort>        GetDevicePort(const enum AudioHwDevice device,
                                              const char *device_name);
    sptr<DeviceVector>      GetDevicePorts(const enum AudioHwDevice devices);
    void                    Add(sptr<HwCard> module);
    sptr<HwCard>            ValueAt(int32_t index) { return hw_cards_[index]; }
    int32_t                 Size() { return hw_cards_.size(); }
    void                    Dump();

private:
    std::vector<sptr<HwCard>> hw_cards_;

};

}

#endif  // AMEBA_COMPONENT_AUDIO_POLICY_COMMON_HW_PORT_H