/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from PanKore
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_GENERAL_AUDIO_H
#define AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_GENERAL_AUDIO_H

#include <map>

#include "osal_cxx/refptr.h"
#include "osal_cxx/errors.h"
#include "osal_cxx/mutex.h"
#include "osal_cxx/threads.h"

#include "audio/utils/base_type.h"

#include "hardware/audio/audio_hw_types.h"
#include "hardware/audio/audio_hw_card.h"

namespace ameba::audio
{

class OutputServerThreadBase;
class OutTrack;
class EffectHandler;
class AudioCard;

typedef int32_t AudioHwCardId;

class GeneralAudio
{

public:
    static GeneralAudio    *GetInstance();
    AudioCardId             NextUniqueCardId();
    AudioCardId             LoadCard(const char *name);
    int32_t                 CreateOutput(AudioCardId card, AudioIoId *output, int32_t rate, int32_t channels,
                                             int32_t format, enum AudioHwDevice devices, int32_t flags);
    AudioIoId               CreateCopiedOutput(AudioIoId output1, AudioIoId output2);
    int32_t                 DestroyOutput(AudioIoId output);
    void                    InvalidateCategory(int32_t category);
    sptr<OutTrack>          CreateTrackInThread(uint32_t category_type, uint32_t sample_rate,
                                                uint32_t format, uint32_t channel_count,
                                                size_t *frame_count, AudioIoId output, int32_t *status);
    size_t                  GetMinBufferFrames(uint32_t category_type, uint32_t sample_rate);
    int32_t                 SetHardwareVolume(float left_volume, float right_volume);
    int32_t                 GetHardwareVolume(float *left_volume, float *right_volume);
    int32_t                 SetHardwareMute(bool left_mute, bool right_mute);
    int32_t                 IsHardwareMuted(bool *left_muted, bool *right_muted);
    int32_t                 SetCategoryVolume(uint32_t audio_type, float value);
    float                   GetCategoryVolume(uint32_t audio_type);
    int32_t                 SetCategoryMute(uint32_t audio_type, bool mute);
    bool                    IsCategoryMuted(uint32_t audio_type);
    int32_t                 SetAmplifierEnPin(uint32_t amp_pin);
    int32_t                 GetLatency(uint32_t audio_type, uint32_t *latency);
    EffectHandler          *CreateEffect(uint32_t type);
    void                    DestroyEffect(EffectHandler *module);

#ifdef CONFIG_AUDIO_MIXER_RECORD
    size_t                  GetInputBufferFrame(uint32_t sample_rate, uint32_t format, uint32_t channel_count);
    //record interfaces
    sptr<RecordTrack>       CreateRecordTrackInThread(uint32_t category_type, uint32_t sample_rate,
            uint32_t format, uint32_t channel_count,
            size_t *frame_count, pid_t tid, int32_t *status);
    int32_t                 CloseInput(AudioIoId audio_io_id);
#endif

private:
    GeneralAudio();
    ~GeneralAudio();

    int32_t                 CreateOutput_l(AudioCard *card,
                                           AudioHwPathDescriptor *desc,
                                           AudioHwConfig *attr,
                                           AudioIoId *audio_io_id);
    AudioHwDevice           GetPortPinByCategoryType(uint32_t category_type);
    AudioIoId               GetOutputByPin(AudioHwDevice pin);
    sptr<OutputServerThreadBase>  GetOutputServerThreadBaseByOutput(AudioIoId output);
    uint32_t                AllocAudioIoId();

#ifdef CONFIG_AUDIO_MIXER_RECORD
    sptr<RecordThread>      GetRecordThreadByInput(AudioIoId input);
    //record interfaces
    uint32_t                AllocAudioRecordIoId();
    AudioIoId               OpenInput(AudioHwDevice pin);
    int32_t                 OpenInputLock(AudioHwCardId card_id,
                                          AudioHwPathDescriptor *desc,
                                          AudioHwConfig *attr,
                                          AudioIoId *audio_io_id);



    AudioHwDevice          GetRecordPortPin(uint32_t category_type);
    AudioIoId              GetInputByPin(AudioHwDevice pin);
    int32_t                RemoveInputFromThreads(AudioIoId input);
#endif

private:
    using OutputServerThreadBaseMap = std::map<AudioIoId, sptr<OutputServerThreadBase>>;
    using OutputServerThreadBasePair = std::pair<AudioIoId, sptr<OutputServerThreadBase>>;
    using OutputServerThreadBaseIterator = std::map<AudioIoId, sptr<OutputServerThreadBase>>::iterator;
    using OutputDescMap = std::map<AudioHwDevice, AudioIoId>;
    using OutputDescPair = std::pair<AudioHwDevice, AudioIoId>;
    using OutputDescIterator = std::map<AudioHwDevice, AudioIoId>::iterator;
    using AudioCardMap = std::map<AudioCardId, AudioCard *>;

    OutputServerThreadBaseMap        playback_threads_;
    OutputDescMap                    output_desc_;
    AudioCardMap                     audio_card_map_;
    int32_t                          audio_card_num_;
    volatile uint32_t                next_unique_card_id_;
    volatile uint32_t                audio_io_id_;
    mutable  Mutex                   lock_;
    float                            hardware_left_volume_;
    float                            hardware_right_volume_;
    bool                             hardware_left_mute_;
    bool                             hardware_right_mute_;
    static GeneralAudio             *s_instance_;
    static Mutex                     s_mutex_;
    static bool                      s_service_inited;

#ifdef CONFIG_AUDIO_MIXER_RECORD
    //for record values
    using RecordThreadMap = std::map<AudioIoId, sptr<RecordThread>>;
    using RecordThreadPair = std::pair<AudioIoId, sptr<RecordThread>>;
    using RecordThreadIterator = std::map<AudioIoId, sptr<RecordThread>>::iterator;
    RecordThreadMap                  record_threads_;

    using InputDescMap = std::map<AudioHwDevice, AudioIoId>;
    using InputDescPair = std::pair<AudioHwDevice, AudioIoId>;
    using InputDescIterator = std::map<AudioHwDevice, AudioIoId>::iterator;

    InputDescMap                     input_desc_;
    volatile int32_t                 audio_record_io_id_;
    mutable  Mutex                   record_lock_;
#endif

};

} // namespace ameba::audio

#endif // AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_GENERAL_AUDIO_H
