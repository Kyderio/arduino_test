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

#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_STREAM_SERVICES_AUDIO_CARD_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_STREAM_SERVICES_AUDIO_CARD_H

#include <stdint.h>
#include <vector>
#include <string>

#include "osal_cxx/refptr.h"

#include "audio/utils/base_type.h"

#include "hardware/audio/audio_hw_card.h"
#include "hardware/audio/audio_hw_types.h"

namespace ameba::audio
{

class AudioStreamRender;

class AudioCard {
public:
    AudioCard(AudioCardId card_id, std::string name,
                  AudioHwCard *card, struct AudioHwCardDescriptor *desc)
        : name_(name),
          card_id_(card_id),
          card_(card),
          card_desc_(desc) {}
    virtual ~AudioCard() {}

    std::string                    Name() { return name_; }
    AudioCardId                    GetCardId() { return card_id_; }
    AudioHwCard                   *GetCard() { return card_; }
    AudioStreamRender             *GetStreamRender() { return stream_render_; }
    struct AudioHwCardDescriptor  *GetCardDescriptor() { return card_desc_; }
    int32_t                        CreateStreamRender(AudioStreamRender **stream_renderer,
                                                      AudioIoId handle,
                                                      AudioHwPathDescriptor *desc,
                                                      AudioHwConfig *attr);
private:
    std::string                    name_;
    AudioCardId                    card_id_;
    AudioHwCard                   *card_;
    struct AudioHwCardDescriptor  *card_desc_;
    AudioStreamRender             *stream_render_;
};

}

#endif