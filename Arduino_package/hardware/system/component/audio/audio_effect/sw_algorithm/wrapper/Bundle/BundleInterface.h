
#ifndef AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_SW_ALGORITHM_WRAPPER_BUNDLE_H
#define AMEBA_COMPONENT_AUDIO_AUDIO_EFFECT_SW_ALGORITHM_WRAPPER_BUNDLE_H

#include "effect_equalizer.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t EffectCreate(int32_t sessionId, int32_t ioId __unused, effect_handle_t  *pHandle);

int32_t EffectRelease(effect_handle_t handle);

#ifdef __cplusplus
}  // extern "C"
#endif


#endif