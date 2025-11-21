/*
 * Copyright (c) 2024 Realtek, LLC.
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

#ifndef AMEBA_AUDIO_FOUNDATION_AMESSAGE_H
#define AMEBA_AUDIO_FOUNDATION_AMESSAGE_H

#include <stdint.h>
#include <sys/types.h>

#include "cutils/refbase.h"

#include "foundation/afoundation_forward_decls.h"

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// AReplyToken
struct AReplyToken {
    ALooper* (*GetLooper)(AReplyToken *token);
    int32_t (*SetReply)(AReplyToken *token, AMessage *message);
    bool (*RetrieveReply)(AReplyToken *token, AMessage **reply);

    struct refbase* (*GetRefPtr)(AReplyToken *token);
    AReplyToken* (*IncRef)(AReplyToken *token);
    void (*DecRef)(AReplyToken *token);

    void (*Destroy)(AReplyToken *token);
};

AReplyToken *AReplyToken_Create(ALooper *looper);

// ----------------------------------------------------------------------
// AMessage
struct AMessage {
    void (*Clear)(AMessage *message);
    void (*SetTarget)(AMessage *message, AHandler *handler);
    void (*SetWhat)(AMessage *message, uint32_t what);
    uint32_t (*What)(AMessage *message);

    void    (*Deliver)(AMessage *message);
    int32_t (*Post)(AMessage *message, int64_t delay_us);
    int32_t (*PostAndAwaitResponse)(AMessage *message, AMessage **response);
    bool    (*SenderAwaitsResponse)(AMessage *message, AReplyToken **reply_token);
    int32_t (*PostReply)(AMessage *message, AReplyToken *reply_token);
    AMessage* (*Dup)(AMessage *message);

    void (*SetInt32)(AMessage *message, const char *name, int32_t value);
    bool (*FindInt32)(AMessage *message, const char *name, int32_t *value);
    void (*SetInt64)(AMessage *message, const char *name, int64_t value);
    bool (*FindInt64)(AMessage *message, const char *name, int64_t *value);
    void (*SetSize)(AMessage *message, const char *name, size_t value);
    bool (*FindSize)(AMessage *message, const char *name, size_t *value);
    void (*SetFloat)(AMessage *message, const char *name, float value);
    bool (*FindFloat)(AMessage *message, const char *name, float *value);
    void (*SetDouble)(AMessage *message, const char *name, double value);
    bool (*FindDouble)(AMessage *message, const char *name, double *value);
    void (*SetPointer)(AMessage *message, const char *name, void *value);
    bool (*FindPointer)(AMessage *message, const char *name, void **value);

    struct refbase* (*GetRefPtr)(AMessage *message);
    AMessage* (*IncRef)(AMessage *message);
    void (*DecRef)(AMessage *message);

    void (*Destroy)(AMessage *message);
};

AMessage* AMessage_Create(uint32_t what, AHandler *handler);

#ifdef __cplusplus
}
#endif

#endif // AMEBA_WIFI_AUDIO_FOUNDATION_A_MESSAGE_H
