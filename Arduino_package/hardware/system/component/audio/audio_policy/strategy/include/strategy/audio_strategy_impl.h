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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_STRATEGY_AUDIO_STRATEGY_IMPL_H
#define AMEBA_COMPONENT_AUDIO_POLICY_STRATEGY_AUDIO_STRATEGY_IMPL_H

#include <stdint.h>
#include <vector>
#include <string>

#include "osal_cxx/refptr.h"

#include "hardware/audio/audio_hw_types.h"

#include "strategy/audio_strategy.h"

namespace ameba::audio
{
class DeviceVector;

class AudioStrategyImpl : public AudioStrategy {
public:
    AudioStrategyImpl(sptr<DeviceVector> out, sptr<DeviceVector> in)
      : available_output_devices_(out),
        available_input_devices_(in) {}
    virtual ~AudioStrategyImpl() {}

    virtual StrategyType       FindStrategyByCategory(int32_t category);
    virtual enum AudioHwDevice FindDeviceByStrategy(StrategyType stategy);
            void               UpdateAvailableDevices(sptr<DeviceVector> out, sptr<DeviceVector> in);

private:
    sptr<DeviceVector> available_output_devices_;
    sptr<DeviceVector> available_input_devices_;
};

}

#endif