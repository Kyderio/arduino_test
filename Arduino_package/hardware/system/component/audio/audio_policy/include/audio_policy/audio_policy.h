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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_H
#define AMEBA_COMPONENT_AUDIO_POLICY_H

#include <stdint.h>
#include <vector>
#include <string>

#include "osal_cxx/refptr.h"

#include "audio/audio_service.h"

#include "hardware/audio/audio_hw_types.h"

#include "audio_policy/audio_policy_coodinator.h"

namespace ameba::audio
{

typedef enum AudioPolicyDeviceState {
    DEVICE_STATE_UNAVAILABLE,
    DEVICE_STATE_AVAILABLE,
} AudioPolicyDeviceState;

class AudioPolicy {
public:
    virtual ~AudioPolicy() {}

    virtual int32_t                SetDeviceState(int32_t device, AudioPolicyDeviceState state,
                                                  const char *device_name, RTAudioDeviceConfig *config) = 0;
    virtual AudioPolicyDeviceState GetDeviceState(int32_t device) = 0;
    virtual AudioIoId              GetOutput(int32_t category, uint32_t rate, int32_t format,
                                             int32_t channels, int32_t flags, AudioSessionId session,
                                             AudioPortId user_preferred_device_id) = 0;
};

extern "C" AudioPolicy* CreateAudioPolicy(AudioPolicyCoodinator *coodinator);
extern "C" AudioPolicy* GetAudioPolicy();
}

#endif