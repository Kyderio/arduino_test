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

#ifndef AMEBA_AUAMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_OUTPUT_TRACK_H
#define AMEBA_AUAMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_OUTPUT_TRACK_H

#include "osal_cxx/errors.h"
#include "track_base.h"
#include "string.h"
#include "audio/audio_time.h"
#include "hardware/audio/audio_hw_types.h"
#include "track_shared.h"

namespace ameba::audio
{
class OutputServerThreadBase;

class OutTrack : public ServerThreadBase::ServerTrackBase
{
public:
    OutTrack(OutputServerThreadBase *thread,
             uint32_t type,
             uint32_t sample_rate,
             uint32_t format,
             uint32_t channel_count,
             size_t frame_count);
    virtual              ~OutTrack();

    virtual int32_t       TrackBufferCheck() const;
    virtual int32_t       Start();
    virtual void          Stop();
    virtual int32_t       GetTimestamp(RTAudioTimestamp *timestamp);
    virtual uint32_t      GetSampleRate()  const;
            void          Pause();
            void          Flush();
            void          Destroy();
            int32_t       SetParameters(const char *params);
            void          Invalidate();

            int           GetTrackMask() const {
                              return track_mask_;
                          }
            uint32_t      CategoryType() const
                          {
                              if (category_type_ == AUDIO_CATEGORY_INTERNAL) {
                                  return RTAUDIO_CATEGORY_MAX_NUM;
                              } else {
                                    return category_type_;
                              }
                          }
protected:

    friend class OutputServerThreadBase;
    friend class MixerSingleThread;

    OutTrack(const OutTrack &);
    OutTrack &operator = (const OutTrack &);

    virtual int32_t       GetNextAvailBuffer(TrackServerBufferAgent::Buffer *buffer, int64_t pts = kInvalidPTS);
    virtual size_t        ReadyFramesSize() const;
    virtual size_t        ReleasedFramesSize() const;
            void          Reset();
            void          InvalidWhenThreadExit();
            bool          IsPlayDone(size_t frames_written, size_t audio_hal_frames);

            void          SetWorkBuffer(int16_t *buffer)
                          {
                              work_buffer_ = buffer;
                          }
            int16_t      *GetWorkBuffer() const
                          {
                              return work_buffer_;
                          }

            bool          IsPausing() const
                          {
                              return track_state_ == PAUSING;
                          }
            bool          IsPaused() const
                          {
                              return track_state_ == PAUSED;
                          }
            bool          IsReady() const;
            void          SetPause()
                          {
                              track_state_ = PAUSED;
                          }

protected:

    enum {FS_INVALID, FS_FILLING, FS_FILLED, FS_ACTIVE};
    mutable uint8_t     filling_up_status_;
    int8_t              retry_count_;

    int                 track_mask_;
    bool                reset_done_;
    uint32_t            category_type_;
    int16_t            *work_buffer_;
    size_t              complete_frames_;
private:
    TrackServerAgent   *audio_track_server_proxy_;
    bool                resume_to_stopping_;

};

//used by CopiedThread
class InternalTrack : public OutTrack {
public:

    class Buffer : public TrackServerBufferAgent::Buffer {
    public:
        void *buffer_;
    };

                                  InternalTrack(OutputServerThreadBase *thread,
                                      CopiedThread *source_thread,
                                      uint32_t sampleRate,
                                      int32_t format,
                                      int32_t channels,
                                      size_t frame_count);
    virtual                       ~InternalTrack();

    virtual int32_t                Start();
    virtual void                   Stop();
            bool                   Write(void* data, uint32_t frames);
            bool                   bufferQueueEmpty() const { return buffer_queue_.size() == 0; }
            bool                   IsActive() const { return is_active_; }
    const wptr<ServerThreadBase>&  Thread() const { return track_in_thread_; }

private:

    int32_t                        GetAvailableBuffer(TrackServerBufferAgent::Buffer* buffer,
                                     uint32_t waitTimeMs);
    void                           ClearBufferQueue();

    static const uint8_t           k_max_internal_buffers_num_ = 10;
    std::vector < Buffer* >        buffer_queue_;
    TrackServerBufferAgent::Buffer out_buffer_;
    bool                           is_active_;
    CopiedThread* const            source_thread_;
    TrackClientAgent*              client_proxy_;
};  // end of InternalTrack

}
#endif // AMEBA_AUAMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_OUTPUT_TRACK_H