#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_ALGORITHM_AUDIO_CONVERTER_CONVERTER_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_ALGORITHM_AUDIO_CONVERTER_CONVERTER_H


#ifdef __cplusplus
extern "C" {
#endif

struct RTAudioConverter {
	int32_t (*process)(struct RTAudioConverter *converter, int8_t *in_buf, uint32_t in_frames,
						   uint32_t *in_done, int8_t *out_buf, uint32_t out_frames, uint32_t *out_done);
	void (*release)(struct RTAudioConverter *converter);
};

#ifdef __cplusplus
}
#endif

#endif