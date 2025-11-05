/*
 * Copyright (c) 2025 Realtek, LLC.
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

#ifndef AMEBA_AUDIO_BASE_CUTILS_INCLUDE_CUTILS_REFCOUNT_H
#define AMEBA_AUDIO_BASE_CUTILS_INCLUDE_CUTILS_REFCOUNT_H

#include <limits.h>
#include <stdint.h>
#include <stdatomic.h>

#include "cutils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define REFCOUNT_SATURATED  (INT_MIN / 2)

enum refcount_error_type {
    REFCOUNT_OVERFLOW_ON_ADD,
    REFCOUNT_USE_AFTER_FREE_ON_ADD,
    REFCOUNT_NOT_ZERO_OVERFLOW_ON_ADD,
    REFCOUNT_USE_AFTER_FREE_ON_SUB,
    REFCOUNT_LEAK_ON_DECREMENT,
};

typedef struct refcount {
    atomic_int count;
} refcount;

void refcount_saturation_alert(refcount *r, enum refcount_error_type err);

static inline
void refcount_set(refcount *r, int n) {
    atomic_init(&r->count, n);
}

static inline
int refcount_read(const refcount *r) {
    return atomic_load_explicit(&r->count, memory_order_relaxed);
}

static inline
void refcount_add(refcount *r, int n) {
    int old = atomic_fetch_add_explicit(&r->count, n, memory_order_relaxed);

    if (CC_UNLIKELY(!old))
        refcount_saturation_alert(r, REFCOUNT_USE_AFTER_FREE_ON_ADD);
    else if (CC_UNLIKELY(old < 0 || old + n < 0))
        refcount_saturation_alert(r, REFCOUNT_OVERFLOW_ON_ADD);
}

static inline
void refcount_inc(refcount *r) {
    refcount_add(r, 1);
}

static inline
bool refcount_sub_and_test(refcount *r, int n) {
    int old = atomic_fetch_sub_explicit(&r->count, n, memory_order_release);

    if (old == n) {
        atomic_thread_fence(memory_order_acquire);
        return true;
    }

    if (CC_UNLIKELY(old < 0 || old - n < 0))
        refcount_saturation_alert(r, REFCOUNT_USE_AFTER_FREE_ON_SUB);

    return false;
}

static inline
bool refcount_dec_and_test(refcount *r) {
    return refcount_sub_and_test(r, 1);
}

static inline
void refcount_dec(refcount *r) {
    int old = atomic_fetch_sub_explicit(&r->count, 1, memory_order_release);

    if (CC_UNLIKELY(old <= 1))
        refcount_saturation_alert(r, REFCOUNT_LEAK_ON_DECREMENT);
}

#ifdef __cplusplus
}
#endif

#endif // AMEBA_AUDIO_BASE_CUTILS_INCLUDE_CUTILS_REFCOUNT_H
