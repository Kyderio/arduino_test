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

#ifndef AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_EFFECTS_H
#define AMEBA_FWK_MEDIA_AUDIO_AUDIO_LITE_AUDIO_STREAM_SERVICES_EFFECTS_H

#include <stdint.h>
#include <sys/types.h>

#include "osal_cxx/refptr.h"
#include "osal_cxx/refptr.h"
#include "osal_cxx/errors.h"
#include "streaming_threads.h"

using namespace ameba;

namespace ameba::audio
{

class EffectHandler
{
public:
	EffectHandler(ServerThreadBase *thread, int sessionId);
	virtual ~EffectHandler();

	int32_t       SetConfig();
	int32_t       Start();
	int32_t       Stop();
	void          SetInBuffer(int16_t *buf);
	void          SetOutBuffer(int16_t *buf);
	void          process();
	int32_t       command(uint32_t cmdCode, uint32_t cmdSize, void *pCmdData, uint32_t *replySize, void *pReplyData);
private:
	uint32_t                session_id_;
	wptr<ServerThreadBase>  thread_;
	effect_config_t         config_;    // input and output audio configuration
	effect_handle_t         effect_interface_; // Effect module C API
	mutable Mutex           lock_;
};

}

#endif