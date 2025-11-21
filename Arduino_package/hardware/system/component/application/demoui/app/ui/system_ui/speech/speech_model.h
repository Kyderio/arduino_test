/*
 * Copyright (c) 2022 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless reqUired by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_MODEL_H
#define AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_MODEL_H

#ifdef USE_SPEECH_SERVICE
#include "speech/speech.h"

using ameba::speech::Speech;
using ameba::speech::SpeechObserver;
#endif

class SpeechListener
{
public:
	virtual     ~SpeechListener() = default;
	virtual void OnSpeechStart() = 0;
};


class SpeechModel
{
public:
	SpeechModel();
	~SpeechModel();

	void Create();
	bool EnableSpeech(bool enable);
	void RegisterSpeechListener(SpeechListener *listener);
	void UnRegisterSpeechListener(SpeechListener *listener);
	void SpeechStart();

private:
#ifdef USE_SPEECH_SERVICE
	std::shared_ptr<Speech> speech_;
	SpeechListener         *speech_listener_;
	bool                    speech_status_;
#endif
};
#endif // AMEBA_APPS_PANGU_APP_UI_SYSTEM_UI_SPEECH_MODEL_H

