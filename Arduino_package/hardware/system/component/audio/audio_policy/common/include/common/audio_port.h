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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_COMMON_AUDIO_PORT_H
#define AMEBA_COMPONENT_AUDIO_POLICY_COMMON_AUDIO_PORT_H

#include <stdint.h>
#include <vector>
#include <string>

#include "osal_cxx/refptr.h"

#include "audio/utils/base_type.h"

#include "hardware/audio/audio_hw_types.h"

namespace ameba::audio
{

class HwCard;

typedef enum AudioPortType {
    AUDIO_PORT_TYPE_NONE   = 0x1u,
    AUDIO_PORT_TYPE_DEVICE = 0x2u,
    AUDIO_PORT_TYPE_MIX    = 0x4u,
} AudioPortType;

typedef enum AudioPortRole {
    AUDIO_PORT_ROLE_SOURCE = 0x1u,
    AUDIO_PORT_ROLE_SINK   = 0x2u,
} AudioPortRole;

class AudioPort : public virtual RefPtr
{
public:
    AudioPort(std::string name, AudioPortType type, AudioPortRole role);
    virtual ~AudioPort() {}

    virtual void          Attach(const sptr<HwCard>& module);
            bool          IsAttached() { return hw_card_ != 0; }
    virtual void          Dump();
    static  AudioPortId   GetNextId();
            void          LoadRates(int32_t *rates, int32_t rates_num);
            void          LoadChannels(int32_t *channels, int32_t channels_num);
            void          LoadFormats(int32_t *formats, int32_t formats_num);
            void          LoadFlags(int32_t flags);
            int32_t       CheckRate(int32_t rate);
            int32_t       CheckFormat(enum AudioHwFormat format);
            int32_t       CheckChannels(int32_t channels);
            AudioCardId   GetCarId();

    std::string                      name_;
    AudioPortType                    type_;
    AudioPortRole                    role_;
    std::vector <int32_t>            rates_;
    std::vector <int32_t>            channels_;
    std::vector <int32_t>            formats_;
    int32_t                          flags_;
    sptr<HwCard>                     hw_card_;

private:
    static volatile uint32_t         next_id_;
};

}

#endif  // AMEBA_COMPONENT_AUDIO_POLICY_COMMON_AUDIO_PORT_H