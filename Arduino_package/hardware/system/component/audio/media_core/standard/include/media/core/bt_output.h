/*
 * Copyright (c) 2021 Realtek, LLC.
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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_BT_OUTPUT_H
#define AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_BT_OUTPUT_H

#include "cutils/ring_buffer.h"

#include "device_output.h"

namespace ameba::media
{

class BTOutput : public DeviceOutput
{
public:
    BTOutput();
    virtual ~BTOutput();

    virtual int64_t GetPlayedOutDurationNs(int64_t now_ns) const;
    virtual int64_t GetBufferingDurationNs() const;

    virtual res_t Open(
        uint32_t sample_rate, int channel_count, uint32_t channel_mask,
        uint32_t format, int buffer_count);

    virtual res_t SetAudioParams(uint32_t sample_rate, uint32_t channel_count, uint32_t bits, uint32_t size);

    virtual res_t Start();
    virtual ssize_t Write(const void *buffer, size_t size, bool blocking = true);
    virtual void Stop();
    virtual void Flush();
    virtual void Pause();
    virtual void Close();

    virtual uint32_t GetSinkFlags()
    {
        return kBTSink;
    }

private:
    class SendThread;

    ring_buffer *rb_;
    sptr<SendThread> send_thread_;

    void *resample_pending_data_;
    size_t resample_pending_size_;
};

}; // namespace ameba::media

#endif // AMEBA_FWK_MEDIA_PLAYBACK_CORE_MEDIA_CORE_BT_OUTPUT_H
