/*
 * Copyright (c) 2022 Realtek, LLC.
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

#ifndef AUDIO_TEST_AUDIO_BUFFER_H
#define AUDIO_TEST_AUDIO_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _AudioBuffer {
	int32_t read_ptr;
	int32_t write_ptr;
	int32_t size_remain;
	int32_t capacity;
	char *raw_data;
} AudioBuffer;

AudioBuffer *buffer_create(void);
void   buffer_release(AudioBuffer *buffer);
void   buffer_alloc(AudioBuffer *buffer, int32_t capacity);
int32_t buffer_get_remain_size(AudioBuffer *buffer);
int32_t buffer_get_available_size(AudioBuffer *buffer);
int32_t buffer_get_buffer_capacity(AudioBuffer *buffer);
int32_t buffer_write(AudioBuffer *buffer, const void *data, int32_t bytes);
int32_t buffer_read(AudioBuffer *buffer, void *data, int32_t bytes);
int32_t buffer_get_tx_readptr(AudioBuffer *buffer);
int32_t buffer_get_rx_writeptr(AudioBuffer *buffer);
void   buffer_update_rx_writeptr(AudioBuffer *buffer, int32_t bytes);
void   buffer_update_tx_readptr(AudioBuffer *buffer, int32_t bytes);
void   buffer_flush(AudioBuffer *buffer);

#ifdef __cplusplus
}
#endif

#endif


