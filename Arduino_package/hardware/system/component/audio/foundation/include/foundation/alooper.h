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

#ifndef AMEBA_AUDIO_FOUNDATION_ALOOPER_H
#define AMEBA_AUDIO_FOUNDATION_ALOOPER_H

#include "foundation/afoundation_forward_decls.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ALooper {
    void    (*SetName)(ALooper *looper, const char *name);

    int32_t (*RegisterHandler)(ALooper *looper, AHandler *handler);
    void    (*UnregisterHandler)(ALooper *looper, const handler_id id);

    int32_t (*Start)(ALooper *looper, bool run_local, int32_t priority);
    int32_t (*Stop)(ALooper *looper);

    int32_t (*Post)(ALooper *looper, AMessage *msg, int64_t delay_us);

    AReplyToken* (*CreateReplyToken)(ALooper *looper);
    int32_t (*AwaitResponse)(ALooper *looper, AReplyToken *reply_token, AMessage **response);
    int32_t (*PostReply)(ALooper *looper, AReplyToken *reply_token, AMessage *reply);

    void    (*Destroy)(ALooper *looper);
};

ALooper *ALooper_Create(const char *name);
void       ALooper_Destroy(ALooper *looper);

#ifdef __cplusplus
}
#endif

#endif // AMEBA_AUDIO_FOUNDATION_ALOOPER_H
