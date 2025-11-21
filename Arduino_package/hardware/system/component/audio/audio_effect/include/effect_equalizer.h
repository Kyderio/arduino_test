#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_INCLUDE_EFFECT_EQUALIZER_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_INCLUDE_EFFECT_EQUALIZER_H

#include "audio_effect.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	EQ_PARAM_NUM_BANDS,             // Gets/Sets the number of frequency bands that the equalizer supports.
	EQ_PARAM_LEVEL_RANGE,           // Returns the minimum and maximum band levels supported.
	EQ_PARAM_BAND_LEVEL,            // Gets/Sets the gain set for the given equalizer band.
	EQ_PARAM_CENTER_FREQ,           // Gets/Sets the center frequency of the given band.
	EQ_PARAM_BAND_FREQ_RANGE,       // Gets the frequency range of the given frequency band.
	EQ_PARAM_GET_BAND,              // Gets the band that has the most effect on the given frequency.
	EQ_PARAM_QFACTOR,
	EQ_PARAM_CUR_PRESET,            // Gets/Sets the current preset.
	EQ_PARAM_GET_NUM_OF_PRESETS,    // Gets the total number of presets the equalizer supports.
	EQ_PARAM_GET_PRESET_NAME,       // Gets the preset name based on the index.
	EQ_PARAM_PROPERTIES,            // Gets/Sets all parameters at a time.
} t_equalizer_params;

typedef struct s_equalizer_settings {
	uint16_t curPreset;
	uint16_t numBands;
	uint16_t bandLevels[];
} t_equalizer_settings;

#ifdef __cplusplus
}  // extern "C"
#endif


#endif
