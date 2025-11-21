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

#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_CORE_EQUALIZER_CLIENT_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_CORE_EQUALIZER_CLIENT_H

#include "osal_cxx/errors.h"
#include "osal_cxx/mutex.h"

#include "effect_base.h"

struct RTAudioEffect;

class EqualizerClient : public EffectBase
{
public:
	EqualizerClient(int32_t priority, int32_t session);
	virtual ~EqualizerClient();

	res_t    SetNumberOfBands(uint32_t bands);
	int16_t  GetNumberOfBands();
	int16_t *GetBandLevelRange();
	res_t    SetBandLevel(uint32_t band, uint32_t level);
	int16_t  GetBandLevel(uint32_t band);
	res_t    SetCenterFreq(uint32_t band, uint32_t freq);
	int32_t  GetCenterFreq(uint32_t band);
	int32_t *GetBandFreqRange(uint32_t band);
	int16_t  GetBand(uint32_t frequency);
	res_t    SetQfactor(uint32_t band, uint32_t qfactor);
	int16_t  GetQfactor(uint32_t band);
	void     Release();

private:
	uint32_t             num_bands_;
	int32_t              priority_;
	int32_t              session_;
	Mutex                lock_;

};

#endif // AMEBA_COMPONENT_AUDIO_AUDIO_STREAM_CORE_EQUALIZER_CLIENT_H
