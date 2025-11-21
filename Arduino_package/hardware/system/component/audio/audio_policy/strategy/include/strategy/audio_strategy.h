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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_STRATEGY_AUDIO_STRATEGY_H
#define AMEBA_COMPONENT_AUDIO_POLICY_STRATEGY_AUDIO_STRATEGY_H

#include <stdint.h>
#include <vector>
#include <string>

#include "osal_cxx/refptr.h"

#include "hardware/audio/audio_hw_types.h"

namespace ameba::audio
{
typedef enum StrategyType {
    STRATEGY_MEDIA,
    STRATEGY_PHONE,
    STRATEGY_PROMPT,
    NUM_STRATEGIES
} StrategyType;

class AudioStrategy {
public:
    virtual StrategyType FindStrategyByCategory(int32_t category) = 0;
    virtual enum AudioHwDevice FindDeviceByStrategy(StrategyType stategy) = 0;
};

}

#endif