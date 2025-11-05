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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_COODINATOR_H
#define AMEBA_COMPONENT_AUDIO_POLICY_COODINATOR_H

#include <stdint.h>
#include <vector>
#include <string>

#include "audio/utils/base_type.h"

#include "hardware/audio/audio_hw_types.h"

namespace ameba::audio
{

class AudioPolicyCoodinator {
public:
    virtual ~AudioPolicyCoodinator() {}

    virtual AudioCardId         LoadCard(const char *name) = 0;
    virtual int32_t             CreateOutput(AudioCardId card,
                                             AudioIoId *output,
                                             int32_t rate,
                                             int32_t channels,
                                             int32_t format,
                                             enum AudioHwDevice devices,
                                             int32_t flags) = 0;
    virtual AudioIoId           CreateCopiedOutput(AudioIoId output1, AudioIoId output2) = 0;
    virtual int32_t             DestroyOutput(AudioIoId output) = 0;
    virtual void                InvalidateCategory(int32_t category) = 0;
};

}

#endif