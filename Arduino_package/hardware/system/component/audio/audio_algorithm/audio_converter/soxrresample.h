#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_ALGORITHM_AUDIO_CONVERTER_SOXRESAMPLE_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_ALGORITHM_AUDIO_CONVERTER_SOXRESAMPLE_H

#include "resample.h"
#include "soxr.h"

#ifdef __cplusplus
extern "C" {
#endif

struct SoxrReSampleConverter {
	struct ReSampleConverter resample_common;
	//sox cpu loading: 15%
	soxr_t soxr;
};

struct RTAudioConverter *SoxrResampleConverter_Create(uint32_t in_rate, uint32_t out_rate, uint32_t in_format, uint32_t out_format,
		uint32_t channels, uint32_t quality);

#ifdef __cplusplus
}
#endif

#endif