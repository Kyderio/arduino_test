#ifndef AMEBA_AUAMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_STREAMING_THREADS_H
#define AMEBA_AUAMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_STREAMING_THREADS_H

#include <map>
#include <vector>

#include "osal_cxx/mutex.h"
#include "osal_cxx/condition.h"
#include "osal_cxx/threads.h"
#include "osal_cxx/time.h"

#include "audio/audio_time.h"
#include "audio/audio_type.h"
#include "audio/utils/base_type.h"

#include "audio_stream_render.h"

#include "raw_mixer.h"

#ifdef CONFIG_AUDIO_MIXER_RECORD
#include "audio_stream_capture.h"
#endif

namespace ameba::audio
{

class OutTrack;
class InternalTrack;
class RecordTrack;
class EffectHandler;
class ServerThreadBase : public Thread
{
public:
    class ServerTrackBase;

public:
    enum ThreadType {
        MIXER,
        RECORD,
        DUPLICATED,
    };


    enum {
        CFG_EVENT_IO,
        CFG_EVENT_PRIO,
        CFG_EVENT_SET_PARAMETER,
        CFG_EVENT_CREATE_AUDIO_PATCH,
        CFG_EVENT_RELEASE_AUDIO_PATCH,
    };

    class ConfigEventData: public RefPtr
    {
    public:
        virtual ~ConfigEventData() {}

    protected:
        ConfigEventData() {}
    };

    class ConfigEvent: public RefPtr
    {
    public:
        virtual ~ConfigEvent() {}

        const int type_;
        Mutex lock_;
        Condition cond_;
        int32_t status_;
        bool wait_status_;
        bool requires_system_ready;
        sptr<ConfigEventData> data_;

    protected:
        ConfigEvent(int type, bool requiresSystemReady = false) :
            type_(type), status_(NO_ERROR), wait_status_(false),
            requires_system_ready(requiresSystemReady), data_(NULL) {}
    };

    ServerThreadBase(AudioIoId id, ThreadType type);
    virtual ~ServerThreadBase();

    virtual     int32_t    InitCheck() const = 0;
    virtual     size_t      FrameCount() const = 0;
                void        HandleConfigEventsLocked();

                void        Exit();
                size_t      FrameSize() const {
                                return frame_size_;
                            }
                uint32_t    ChannelCount() {
                                return channel_count_;
                            }
                uint32_t    Format() {
                                return audio_format_;
                            }
                uint32_t    SampleRate() {
                                return sample_rate_;
                            }
                AudioIoId   Id() {
                                return id_;
                            }
                bool        IsStandby() {
                                return standby_status_;
                            }

    friend class OutTrack;
    friend class RecordTrack;

protected:
    virtual     void        PreExit() { }
    bool                    standby_status_;
    ThreadType              type_;
    AudioIoId               id_;
    mutable     Mutex       lock_;
    Condition               wait_for_track_active_condition_;


    uint32_t                sample_rate_;
    size_t                  frame_count_;
    uint32_t                channel_count_;
    size_t                  frame_size_;
    uint32_t                audio_format_;
    size_t                  hal_buffer_size_;

    std::vector<sptr<ConfigEvent>> config_events_;
    std::vector<sptr<ConfigEvent>> wait_system_ready_events_;

    static const int        thread_name_length_ = 16;
    char                    thread_name_[thread_name_length_];
};

enum mixer_state {
    MIXER_IDLE,
    MIXER_TRACKS_ENABLED,
    MIXER_TRACKS_READY,
    MIXER_DRAIN_TRACK,
    MIXER_DRAIN_ALL,
};

struct  stream_type_t {
    stream_type_t()
        :   volume(1.0f),
            mute(false)
    {
    }
    float       volume;
    bool        mute;
};

class OutputServerThreadBase : public ServerThreadBase
{
public:

    OutputServerThreadBase(AudioIoId id, AudioStreamRender *render, ThreadType type);
    virtual ~OutputServerThreadBase();

    virtual int               GetTrackMaskLocked(uint32_t channelMask, uint32_t format) = 0;
    virtual uint32_t          IdleSleepDurationUs() const = 0;
    virtual void              RemoveTrackMaskLocked(int track_mask) = 0;
    virtual void              OnAddNewTrackLocked();
    virtual void              SaveInternalTracks() { }
    virtual void              ClearInternalTracks() { }

    virtual int32_t           InitCheck() const {
                                  return (audio_output_ == NULL) ? NO_INIT : NO_ERROR;
                              }
    virtual size_t            FrameCount() const {
                                  return normal_frame_count_;
                              }

            bool              ThreadLoop();

            AudioStreamRender *GetStreamRender();
            AudioStreamRender *ClearStreamRender();
            AudioStreamRender *ClearOutput();
            int32_t            AddTrackLocked(const sptr<OutTrack> &track);
            void               InvalidateTracks(int32_t category);
            void               WakeConditionLocked();
            uint32_t           GetHwLatency() const;
            uint32_t           GetHwLatencyLocked() const;
            int32_t            SetAmplifierEnPin(uint32_t amp_pin);
            int32_t            SetHardwareVolume(float left_volume, float right_volume);
            int32_t            GetHardwareVolume(float *left_volume, float *right_volume);
            int32_t            SetHardwareMute(bool left_mute, bool right_mute);
            int32_t            IsHardwareMuted(bool *left_muted, bool *right_muted);
            int32_t            SetCategoryVolume(uint32_t audio_type, float value);
            float              GetCategoryVolume(uint32_t audio_type);
            int32_t            SetCategoryMute(uint32_t audio_type, bool mute);
            bool               IsCategoryMuted(uint32_t audio_type);
            int32_t            GetTimestampLocked(RTAudioTimestamp *timestamp);
            EffectHandler     *CreateEffectLocked(uint32_t type);
            void               DestroyEffectLocked(EffectHandler *module);
            sptr<OutTrack>     CreateTrackLocked(uint32_t streatype_, uint32_t sample_rate, uint32_t format,
                                      uint32_t channel_count, size_t *frame_count, pid_t tid, int32_t *status);
            size_t             GetMinBufferFrames(uint32_t sample_rate);
            void               ClearLatchedTime(std::vector< sptr<OutTrack> > *tracks_to_remove);
            int16_t           *GetMixerBuffer() const {
                                   return reinterpret_cast<int16_t *>(buffer_to_hal_);
                               };

protected:
    virtual     void           PreExit();
    virtual     void           ThreadMixAPeriodData() = 0;
    virtual     void           ThreadSleepDurationProcess() = 0;
    virtual     int32_t        ThreadWriteAPeriodData();
    virtual     void           ThreadDrainData();
    virtual     void           ThreadStandby();
    virtual     void           ThreadLoopExit();
    virtual     void           ThreadRemoveTracks(const std::vector< sptr<OutTrack> > &tracks_to_remove);
    virtual     mixer_state    SetTracksInfoToMixerLocked(std::vector< sptr<OutTrack> > *tracks_to_remove) = 0;
                void           RemoveTrackLocked(const sptr<OutTrack> &track);
                void           RemoveTracksLocked(const std::vector< sptr<OutTrack> > &tracks_to_remove);
                bool           DestroyTrackLocked(const sptr<OutTrack> &track);
                bool           IsTrackActive(const sptr<OutTrack> &track);

private:
                void           ReadOutputParamsLocked();

protected:
    friend class OutTrack;
    friend class InternalTrack;
    static const CONSTEXPR float    DEFAULT_MASTER_VOLUME = 0.73;

    std::vector< sptr<OutTrack> >   active_tracks_;
    int                             active_tracks_generation_;
    //wptr<OutTrack>                  lastest_active_track_; // jakcie remove this, need to add
    nsecs_t                         standby_time_duration_ns_;
    size_t                          to_hal_buf_size_;
    uint32_t                        active_sleep_time_us_;
    uint32_t                        idle_sleep_time_duration_us_;

    nsecs_t                         last_write_time_;
    uint32_t                        sleep_time_duration_us_;
    uint32_t                        sleep_time_shift_;
    uint32_t                        active_sleep_time_duration_us_;
    nsecs_t                         max_period_;
    nsecs_t                         standy_delay_ns_;
    mixer_state                     mixer_status_;
    mixer_state                     mixer_status_ignore_fast_track_;

    size_t                          bytes_written_to_hal_;
    size_t                          bytes_remaining_to_write_;
    size_t                          current_write_length_;
    int                             num_delayed_writes_;
    size_t                          normal_frame_count_;

    bool                            thread_throttle_status_;
    uint32_t                        thread_throttled_time_ms_;
    uint32_t                        thread_throttled_end_ms_;
    uint32_t                        hal_buffer_ms_;

    void                           *buffer_to_hal_;

    bool                            mixer_buffer_enabled_;

    void                           *mixer_buffer_;

    size_t                          mixer_buffer_size_;

    uint32_t                        mixer_buffer_format_;

    bool                            is_mixer_buffer_valid_;
    bool                            is_effect_buffer_valid_;

    float                           master_volume_;
    bool                            master_mute_;
    float                           hardware_left_volume_;
    float                           hardware_right_volume_;
    float                           hardware_left_mute_;
    float                           hardware_right_mute_;
    bool                            in_write_;
    int                             num_writes_;
    stream_type_t                   stream_types_[RTAUDIO_CATEGORY_MAX_NUM + 1]; //add one internal category for duplicatingthread.
    void                           *effect_buffer_;
    uint32_t                        effect_buffer_format_;
    EffectHandler                  *effect_module_;
    std::vector< sptr<OutTrack> >   server_tracks_;

public:
    AudioStreamRender              *audio_output_;
    bool                            signal_pending_;

private:
    using FramesHandledMap = std::map<OutTrack *, uint64_t>;
    using FramesHandledPair = std::pair<OutTrack *, uint64_t>;
    using FramesHandledIterator = std::map<OutTrack *, uint64_t>::iterator;

    struct {
        RTAudioTimestamp            tstamp;
        uint32_t                    unpresented_frames;
        FramesHandledMap            frames_released;
    } latchd_, latchq_;
    bool latchd_valid_;
    bool latchq_valid_;
};


class MixerSingleThread : public OutputServerThreadBase
{
public:
    MixerSingleThread(AudioIoId id, AudioStreamRender *render, ThreadType type = MIXER);
    virtual ~MixerSingleThread();

    virtual     mixer_state SetTracksInfoToMixerLocked(std::vector< sptr<OutTrack> > *tracks_to_remove);
    virtual     int32_t     ThreadWriteAPeriodData();
    virtual     void        ThreadMixAPeriodData();
    virtual     void        ThreadSleepDurationProcess();
    virtual     void        ThreadRemoveTracks(const std::vector< sptr<OutTrack> > &tracks_to_remove);
    virtual     uint32_t    IdleSleepDurationUs() const;
    virtual     void        RemoveTrackMaskLocked(int track_mask);

                int         GetTrackMaskLocked(uint32_t channel_count, uint32_t format);

public:
    RawMixer               *audio_mixer_;
};

class CopiedThread : public MixerSingleThread {
public:
    CopiedThread(MixerSingleThread* main_thread, AudioIoId id);
    virtual                 ~CopiedThread();

                void        AddInternalTrack(MixerSingleThread* thread);
                void        RemoveInternalTrack(MixerSingleThread* thread);
                uint32_t    WaitTimeMs() const { return wait_time_ms_; }
protected:
    virtual     uint32_t    ActiveSleepTimeUs() const;

private:
                bool        OutputsReady(const std::vector< sptr<InternalTrack> > &tmp_output_tracks);
protected:
    // threadLoop snippets
    virtual     void        ThreadMixAPeriodData();
    virtual     void        ThreadSleepDurationProcess();
    virtual     int32_t     ThreadWriteAPeriodData();
    virtual     void        ThreadStandby();

private:
    // called from threadLoop, addInternalTrack, removeInternalTrack
    virtual     void        RefineWaitTimeLocked();

protected:
    virtual     void        SaveInternalTracks();
    virtual     void        ClearInternalTracks();

private:
                uint32_t    wait_time_ms_;
                uint32_t    write_frames_;
    std::vector <sptr<InternalTrack>>  tmp_output_tracks_;
    std::vector <sptr<InternalTrack>>  output_tracks_;
};

#ifdef CONFIG_AUDIO_MIXER_RECORD
class RecordThread : public ServerThreadBase
{
public:
    RecordThread(AudioStreamCapture *input, AudioIoId id);
    ~RecordThread();

    AudioStreamCapture *GetAudioStreamCapture()
    {
        return record_capture_;
    }
    void        DestroyTrackLocked(const sptr<RecordTrack> &track);
    void        RemoveTrackLocked(const sptr<RecordTrack> &track);
    void        RemoveTrackFromActiveTracks(const sptr<RecordTrack> &track);
    void        AddTrackToActiveTracks(const sptr<RecordTrack> &track);
    bool        IsTrackInActiveTracks(const sptr<RecordTrack> &track);
    bool        ThreadLoop();
    virtual int32_t       InitCheck() const
    {
        return (record_capture_ == NULL) ? NO_INIT : NO_ERROR;
    }

    sptr<RecordTrack>  CreateRecordTrackLocked(
        uint32_t device_type, uint32_t sample_rate, uint32_t format, uint32_t channel_count,
        size_t *pFrameCount, pid_t tid, int32_t *status);

    int32_t       StartTrack(RecordTrack *recordTrack);
    bool        StopTrack(RecordTrack *recordTrack);
    AudioStreamCapture *ClearInput();

    virtual char       *GetParameters(const char *keys);
    void        ReadInputParametersLocked();
    virtual size_t      FrameCount() const
    {
        return frame_count_;
    }
    int32_t       SetParameters(const char *strs);
    int32_t     GetInputBufferFrames();

protected:
    void        StandbyIfNotAlreadyInStandby();
    void        InputStandBy();

    AudioStreamCapture                 *record_capture_;
    std::vector < sptr<RecordTrack> >   record_tracks_;
    std::vector < sptr<RecordTrack> >   record_active_tracks_;
    Condition                           record_start_stop_cond_;
    void                               *rsmp_in_buffer_;
    size_t                              rsmp_in_frames_;
    size_t                              rsmp_in_frames_p2_;
    int32_t                             rsmp_in_rear_;

    friend class ResamplerBufferAgent;
    friend class RecordBufferConverter;
};

class ResamplerBufferAgent : public TrackServerBufferAgent
{
public:
    ResamplerBufferAgent(RecordTrack *recordTrack) :
        record_track_(recordTrack),
        rsmp_in_urel_(0), rsmp_in_front_(0) { }
    virtual ~ResamplerBufferAgent() { }

    virtual void        Reset();
    virtual void        Sync(size_t *framesAvailable = NULL, bool *hasOverrun = NULL);
    virtual int32_t       GetNextAvailBuffer(TrackServerBufferAgent::Buffer *buffer, int64_t pts);
    virtual void        ReleaseHandledBuffer(TrackServerBufferAgent::Buffer *buffer);
private:
    RecordTrack *const record_track_;
    size_t              rsmp_in_urel_;
    int32_t             rsmp_in_front_;
};

class RecordBufferConverter
{
public:
    RecordBufferConverter(
        uint32_t src_channel_count, uint32_t srcFormat, uint32_t srcSampleRate,
        uint32_t dst_channel_count, uint32_t dstFormat, uint32_t dstSampleRate);

    ~RecordBufferConverter();

    size_t convert(void *dst, TrackServerBufferAgent *provider, size_t frames);
    int32_t  initCheck() const
    {
        return src_channel_count_ <= 8 ? NO_ERROR : NO_INIT;
    }

    int32_t  updateParameters(
        uint32_t src_channel_count, uint32_t srcFormat, uint32_t srcSampleRate,
        uint32_t dst_channel_count, uint32_t dstFormat, uint32_t dstSampleRate);

    void   Reset()
    {
        if (record_resampler_ != NULL) {
            record_resampler_->Reset();
        }
    }

private:
    void   convertNoResampler(void *dst, const void *src, size_t frames);
    void   convertResampler(void *dst, void *src, size_t frames);
    uint32_t             src_channel_count_;
    uint32_t             record_src_format_;
    uint32_t             record_src_rate_;
    uint32_t             dst_channel_count_;
    uint32_t             record_dst_format_;
    uint32_t             record_dst_rate_;
    size_t               record_dst_frame_size_;
    void                *record_buf_;
    size_t               record_buf_frames_;
    size_t               record_buf_frame_size_;
    RawResampler        *record_resampler_;
    bool                 is_legacy_down_mix_;
    bool                 is_legacy_up_mix_;
    bool                 requires_i32_;
    PassthruBufferAgent *input_converter_agent_;
    int8_t               idx_ary_[sizeof(uint32_t) * 8];
};
#endif
} // namespace ameba::audio

#endif
