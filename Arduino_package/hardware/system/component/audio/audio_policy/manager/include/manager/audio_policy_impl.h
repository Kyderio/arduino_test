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

#ifndef AMEBA_COMPONENT_AUDIO_POLICY_MANAGER_AUDIO_POLICY_MANAGER_H
#define AMEBA_COMPONENT_AUDIO_POLICY_MANAGER_AUDIO_POLICY_MANAGER_H

#include <stdint.h>
#include <vector>
#include <set>
#include <string>

#include "osal_cxx/refptr.h"

#include "audio_policy/audio_policy_coodinator.h"
#include "audio_policy/audio_policy.h"

namespace ameba::audio
{
class HwCardCollection;
class DeviceVector;
class DevicePort;
class AudioStrategyImpl;

class AudioPolicyImpl : public AudioPolicy {
public:
    AudioPolicyImpl(AudioPolicyCoodinator *coodinator);
    ~AudioPolicyImpl();

    static  AudioPolicyImpl       *GetInstance(AudioPolicyCoodinator *coodinator);
            void                   Init();
            void                   Dump();

    virtual int32_t                SetDeviceState(int32_t device, AudioPolicyDeviceState state,
                                                  const char *device_name, RTAudioDeviceConfig *config);
    virtual AudioPolicyDeviceState GetDeviceState(int32_t device);
    virtual AudioIoId              GetOutput(int32_t category, uint32_t rate, int32_t format,
                                             int32_t channels, int32_t flags, AudioSessionId session,
                                             AudioPortId user_preferred_device_id);
    static AudioPolicyImpl        *s_policy_instance_;

private:
            void                   AddOutput(AudioIoId output, sptr<AudioOutputDescriptor> output_desc);
            void                   RemoveOutput(AudioIoId output);
            void                   DestroyOutput(AudioIoId output);
            void                   RefineAudioPortConfig(sptr<MixPort> mix_port, RTAudioDeviceConfig *config);
            void                   RefineStrategies();
            void                   RefineStrategyForType(StrategyType strategy);
            int32_t                ResolveDeviceOutputs(const sptr<DevicePort> device_desc,
                                                         AudioPolicyDeviceState state,
                                                         RTAudioDeviceConfig *config,
                                                         std::set<AudioIoId>& outputs);
            void                   StoreStrategy();
            enum AudioHwDevice     FindDeviceByStrategy(StrategyType strategy, bool from_cache);
            std::set<AudioIoId>    FindOutputsByDevice(enum AudioHwDevice device, sptr<AudioOutputDescCollection> output_descs);
            AudioIoId              PickOutput(std::set<AudioIoId> outputs, int32_t flags, int32_t format);
            int32_t                PrimaryOutputExist() const { return primary_output_ != 0; }

    static Mutex                    s_policy_mutex_;
    static bool                     s_policy_inited_;
    sptr<HwCardCollection>          hw_cards_;
    sptr<DeviceVector>              available_input_devices_;
    sptr<DeviceVector>              available_output_devices_;
    sptr<DevicePort>                default_output_device_;
    AudioPolicyCoodinator          *coodinator_;
    sptr<AudioOutputDescCollection> output_collection_;
    sptr<AudioOutputDescCollection> last_outputs_;
    sptr<UserRouteMap>              user_routes_;
    AudioStrategyImpl              *audio_strategy_;
    sptr<AudioOutputDescriptor>     primary_output_;
    bool                            a2dp_suspended_;
    enum AudioHwDevice              device_for_strategy_[NUM_STRATEGIES];
};



}

#endif