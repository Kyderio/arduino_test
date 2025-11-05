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
#ifndef VOX_MEM_H
#define VOX_MEM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void *VoxAlloc(int32_t size);
extern void VoxFree(void *ptr);
extern void VoxMemcpy(void *dest, const void *src, int32_t size);
extern void VoxMemset(void *dest, int16_t c, int32_t size);


#ifdef __cplusplus
}
#endif

#endif