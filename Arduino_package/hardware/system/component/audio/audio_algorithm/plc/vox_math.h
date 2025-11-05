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
#ifndef VOX_MATH_H
#define VOX_MATH_H

#include <stdio.h>
#include <math.h>


#ifdef __cplusplus
extern "C" {
#endif

#define VoxAbs(x)                   ((x) < 0 ? (-(x)) : (x))      /**  Absolute 16-bit value.  */
#define VoxMin(a,b)                 ((a) < (b) ? (a) : (b))       /**  Maximum 16-bit value.   */
#define VoxMax(a,b)                 ((a) > (b) ? (a) : (b))       /**  Maximum 16-bit value.   */
#define VoxFloat2Int16(x)           ((x) < -32767.5f ? -32768 : ((x) > 32766.5f ? 32767 : floor(.5+(x))))

#define VoxPow                      pow
#define VoxLog10                    log10f
#define VoxFloor                    floorf
#define VoxSqrt                     sqrt
#define VoxAcos                     acos
#define VoxExp                      exp
#define VoxCosNorm(x)               (cos((.5f*VOX_M_PI)*(x)))
#define VoxAtan                     atan

#define VOX_FLOAT_ZERO              (0.f)
#define VOX_FLOAT_ONE               (1.f)
#define VOX_FLOAT_TWO               (2.0f)
#define VOX_FLOAT_TEN               (10.0f)
#define VOX_FLOAT_HALF              (0.5f)
#define VOX_M_PI                    (3.14159265358979323846)
#define VOX_PI_2                    (1.5707963268)

void VoxMemcpyFloatFromP24(float *dst, const uint8_t *src, size_t count);
void VoxMemcpyP24FromFloat(uint8_t *dst, const float *src, size_t count);
void VoxMemcpyI32FromFloat(int32_t *dst, const float *src, size_t count);
void VoxMemcpyI16FromFloat(int16_t *dst, const float *src, size_t count);

#ifdef __cplusplus
}
#endif


#endif