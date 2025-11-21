/*
 * Copyright (c) 2021 Realtek, LLC.
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
#ifndef AMEBA_AUDIO_BASE_CUTILS_INCLUDE_CUTILS_PROPERTIES_H
#define AMEBA_AUDIO_BASE_CUTILS_INCLUDE_CUTILS_PROPERTIES_H

#ifdef __cplusplus
extern "C" {
#endif

#define PROP_NAME_MAX   32
#define PROP_VALUE_MAX  128

void property_load_boot_defaults(const char *file);

void property_init(void);
int property_get(const char *key, char *value, const char *default_value);
int property_set(const char *key, const char *value);
int property_list(void (*propfn)(const char *key, const char *value, void *cookie), void *cookie);

#ifdef __cplusplus
}
#endif

#endif // AMEBA_AUDIO_BASE_CUTILS_INCLUDE_CUTILS_PROPERTIES_H
