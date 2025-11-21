/*
** Copyright (c) 2002-2021, Erik de Castro Lopo <erikd@mega-nerd.com>
** All rights reserved.
**
** This code is released under 2-clause BSD license. Please see the
** file at : https://github.com/libsndfile/libsamplerate/blob/master/COPYING
*/

#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdint.h>
#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#endif

#if defined(__x86_64__) || defined(_M_X64)
#   define HAVE_SSE2_INTRINSICS
#elif defined(ENABLE_SSE2_LRINT) && (defined(_M_IX86) || defined(__i386__))
#   if defined(_MSC_VER)
#       define HAVE_SSE2_INTRINSICS
#   elif defined(__clang__)
#       ifdef __SSE2__
#           define HAVE_SSE2_INTRINSICS
#       elif (__has_attribute(target))
#           define HAVE_SSE2_INTRINSICS
#           define USE_TARGET_ATTRIBUTE
#       endif
#   elif defined(__GNUC__)
#       ifdef __SSE2__
#           define HAVE_SSE2_INTRINSICS
#       elif (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 9))
#           define HAVE_SSE2_INTRINSICS
#           define USE_TARGET_ATTRIBUTE
#       endif
#   endif
#endif

#ifdef HAVE_SSE2_INTRINSICS
#ifdef HAVE_IMMINTRIN_H
#include <immintrin.h>
#else
#include <emmintrin.h>
#endif
#endif /* HAVE_SSE2_INTRINSICS */

#include <math.h>

#ifdef HAVE_VISIBILITY
  #define LIBSAMPLERATE_DLL_PRIVATE __attribute__ ((visibility ("hidden")))
#elif defined (__APPLE__)
  #define LIBSAMPLERATE_DLL_PRIVATE __private_extern__
#else
  #define LIBSAMPLERATE_DLL_PRIVATE
#endif

#define SRC_MAX_RATIO           256
#define SRC_MAX_RATIO_STR       "256"

#define SRC_MIN_RATIO_DIFF      (1e-20)

#ifndef MAX
#define MAX(a,b)    (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)    (((a) < (b)) ? (a) : (b))
#endif

#define ARRAY_LEN(x)            ((int) (sizeof (x) / sizeof ((x) [0])))
#define OFFSETOF(type,member)   ((int) (&((type*) 0)->member))

#define MAKE_MAGIC(a,b,c,d,e,f) ((a) + ((b) << 4) + ((c) << 8) + ((d) << 12) + ((e) << 16) + ((f) << 20))

/*
** Inspiration : http://sourcefrog.net/weblog/software/languages/C/unused.html
*/
#ifdef UNUSED
#elif defined (__GNUC__)
#   define UNUSED(x) UNUSED_ ## x __attribute__ ((unused))
#elif defined (__LCLINT__)
#   define UNUSED(x) /*@unused@*/ x
#else
#   define UNUSED(x) x
#endif

#ifdef __GNUC__
#   define WARN_UNUSED  __attribute__ ((warn_unused_result))
#else
#   define WARN_UNUSED
#endif

/*----------------------------------------------------------
** SIMD optimized math functions.
*/

#ifdef HAVE_SSE2_INTRINSICS
static inline int
#ifdef USE_TARGET_ATTRIBUTE
__attribute__((target("sse2")))
#endif
psf_lrintf (float x)
{
    return _mm_cvtss_si32 (_mm_load_ss (&x)) ;
}
static inline int
#ifdef USE_TARGET_ATTRIBUTE
__attribute__((target("sse2")))
#endif
psf_lrint (double x)
{
    return _mm_cvtsd_si32 (_mm_load_sd (&x)) ;
}

#else

static inline int psf_lrintf (float x)
{
    return lrintf (x) ;
} /* psf_lrintf */

static inline int psf_lrint (double x)
{
    return lrint (x) ;
} /* psf_lrint */
#endif

/*----------------------------------------------------------
**  Common static inline functions.
*/

static inline double
fmod_one (double x)
{   double res ;

    res = x - psf_lrint (x) ;
    if (res < 0.0)
        return res + 1.0 ;

    return res ;
} /* fmod_one */

static inline int
is_bad_src_ratio (double ratio)
{   return (ratio < (1.0 / SRC_MAX_RATIO) || ratio > (1.0 * SRC_MAX_RATIO)) ;
} /* is_bad_src_ratio */


#endif  /* COMMON_H_INCLUDED */

