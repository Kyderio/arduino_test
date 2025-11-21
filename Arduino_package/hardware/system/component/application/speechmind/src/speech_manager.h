#ifndef _SPEECH_MIND_SPEECH_MANAGER_
#define _SPEECH_MIND_SPEECH_MANAGER_

#include "ringbuffer.h"
#include "speech_config.h"

#define AFE_FRAME_MS 16
#define AFE_IN_CHANNEL 3
#define AFE_SAMPLE_RATE 16000
#define AFE_BITS 16
#define AFE_FRAME_BYTES (AFE_IN_CHANNEL*AFE_FRAME_MS*AFE_SAMPLE_RATE*(AFE_BITS/8)/1000LL)
#define VAD_FRAME_BYTES (1*AFE_FRAME_MS*AFE_SAMPLE_RATE*(AFE_BITS/8)/1000LL)
#define VAD_TIMEOUT_MS 10000

typedef struct SpeechManager SpeechManager;

SpeechManager *SpeechManager_Create(RingBuffer *mic_buffer, RingBuffer *afe_buffer, SpeechConfig *config);
void SpeechManager_Start(SpeechManager *manager);
void SpeechManager_Destroy(SpeechManager *manager);

#endif //_SPEECH_MIND_SPEECH_MANAGER_
