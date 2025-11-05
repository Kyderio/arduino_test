/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef AMEBA_HARDWARE_AUDIO_PRIMARY_AUDIO_ADAPTER_H
#define AMEBA_HARDWARE_AUDIO_PRIMARY_AUDIO_ADAPTER_H

#include <stdio.h>

#include "hardware/audio/audio_hw_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

// PrimaryAudioHwAdapter
struct PrimaryAudioHwAdapter {
	struct AudioHwAdapter adapter;

	_mutex lock;
	struct PrimaryAudioHwRender *output;
	struct PrimaryAudioHwCapture *input;
};

#ifdef __cplusplus
}
#endif
#endif //AMEBA_HARDWARE_AUDIO_PRIMARY_AUDIO_ADAPTER_H