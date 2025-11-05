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

#ifndef AUDIO_TEST_AUDIO_FFT_ANALYSIS_H
#define AUDIO_TEST_AUDIO_FFT_ANALYSIS_H

#include "basic_types.h"

void calculate_power_per_band(float *freq_data, float *power_per_band,int *lower_indices, int *upper_indices, int band_count);
void initialize_frequency_indices(float *freqs, float *freq_points,int band_count, int *lower_indices, int *upper_indices);

#endif