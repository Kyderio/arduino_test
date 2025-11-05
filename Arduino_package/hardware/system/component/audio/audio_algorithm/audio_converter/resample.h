#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_ALGORITHM_AUDIO_CONVERTER_RESAMPLE_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_ALGORITHM_AUDIO_CONVERTER_RESAMPLE_H

#include "converter.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ReSampleConverter {
	struct RTAudioConverter common;
	uint32_t in_rate;
	uint32_t out_rate;
	uint32_t in_format;
	uint32_t out_format;
	uint32_t channels;
};

struct RTAudioConverter *ResampleConverter_Create(uint32_t in_rate, uint32_t out_rate, uint32_t in_format, uint32_t out_format,
		uint32_t channels, uint32_t quality, uint32_t resample_type);

#ifdef __cplusplus
}
#endif

#endif