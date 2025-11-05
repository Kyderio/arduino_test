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

#ifndef AMEBA_AUDIO_FOUNDATION_ALOOPER_MANAGER_H
#define AMEBA_AUDIO_FOUNDATION_ALOOPER_MANAGER_H

#include "foundation/afoundation_forward_decls.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ALooperManager {
    handler_id (*RegisterHandler)(ALooperManager *lm, ALooper *looper, AHandler *handler);
    void (*UnregisterHandler)(ALooperManager *lm, handler_id handler_id);
    void (*Destroy)(ALooperManager *lm);
};

void ALooperManager_Init(void);
void ALooperManager_DeInit(void);

ALooperManager *ALooperManager_GetInstance(void);

#ifdef __cplusplus
}
#endif

#endif // AMEBA_AUDIO_FOUNDATION_ALOOPER_MANAGER_H
