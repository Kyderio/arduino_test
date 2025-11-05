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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_MANAGER_AUDIO_OUTPUT_DESCRIPTOR_H
#define AMEBA_COMPONENT_AUDIO_POLICY_MANAGER_AUDIO_OUTPUT_DESCRIPTOR_H

#include <stdint.h>
#include <vector>
#include <map>
#include <set>
#include <string>

#include "osal_cxx/refptr.h"

#include "audio/utils/base_type.h"

#include "hardware/audio/audio_hw_types.h"

namespace ameba::audio
{
class MixPort;
class AudioPolicyCoodinator;

class AudioOutputDescriptor : public RefPtr {
public:
    AudioOutputDescriptor(sptr<MixPort> profile, AudioPolicyCoodinator *coodinator);
    ~AudioOutputDescriptor() {}

    enum AudioHwDevice          Device() { return device_; }
    bool                        IsDuplicated() { return (output1_ != NULL && output2_ != NULL); }
    AudioPortId                 GetId() { return id_; }
    void                        SetIoHandle(AudioIoId io_handle);

    sptr<MixPort>               mix_port_;
    AudioIoId                   io_handle_;
    int32_t                     flags_;
    sptr<AudioOutputDescriptor> output1_;
    sptr<AudioOutputDescriptor> output2_;

    enum AudioHwDevice          device_;
    AudioPolicyCoodinator      *coodinator_;

    int32_t                     rate_;
    int32_t                     channels_;
    int32_t                     format_;

protected:
    AudioPortId                 id_;
};

class AudioOutputDescCollection : public RefPtr {
public:
    AudioOutputDescCollection() { }
    ~AudioOutputDescCollection() { }

    void                          Add(AudioIoId id, sptr<AudioOutputDescriptor> output_desc);
    void                          Remove(AudioIoId id);
    sptr<AudioOutputDescriptor>   ValueAt(AudioIoId id);
    AudioIoId                     GetA2dpOutput();
    sptr<AudioOutputDescriptor>   GetPrimaryOutput();
    sptr<AudioOutputDescriptor>   GetOutputFromId(AudioPortId id);
    enum AudioHwDevice            GetSupportedDevices(AudioIoId handle);
    std::set<AudioIoId>           FindOutputsByDevice(enum AudioHwDevice device);
    void                          FindOutputsRoutesToDevice(enum AudioHwDevice device, std::set<AudioIoId>& outputs);
    void                          FindOutputsNotRoutesToDevice(enum AudioHwDevice device, std::set<AudioIoId>& outputs);
    AudioIoId                     FindRelatedDuplicateOutput(AudioIoId output);
    int32_t                       Size() { return output_collection_.size(); }

private:
    std::map<AudioIoId, sptr<AudioOutputDescriptor>> output_collection_;
    sptr<AudioOutputDescriptor> primary_output_;
};

}

#endif