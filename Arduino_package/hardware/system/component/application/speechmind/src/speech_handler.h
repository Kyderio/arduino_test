#ifndef _SPEECH_MIND_SPEECH_HANDLER_
#define _SPEECH_MIND_SPEECH_HANDLER_

enum SPEECH_MESSAGE_TYPE {
	SPEECH_PLAY_LIST = 0,
	SPEECH_TTS_INDEX = 1,
	SPEECH_URL = 2,
};

void SpeechHandler_Create(void);
void SpeechHandler_Destroy(void);

void SpeechMessage_Post(enum SPEECH_MESSAGE_TYPE type, void *data, unsigned int len, int param, char *url, int stop);

#endif
