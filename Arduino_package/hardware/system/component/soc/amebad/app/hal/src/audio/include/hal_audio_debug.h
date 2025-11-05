/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef AMEBA_COMPONENT_AUDIO_HAL_SRC_INCLUDE_HAL_AUDIO_DEBUG_H
#define AMEBA_COMPONENT_AUDIO_HAL_SRC_INCLUDE_HAL_AUDIO_DEBUG_H

#include "basic_types.h"
#include "osdep_service.h"


/* Debug options */
#define HAL_AUDIO_COMMON_DEBUG 0
#define HAL_AUDIO_VERBOSE_DEBUG 0
#define HAL_AUDIO_PLAYBACK_VERY_VERBOSE_DEBUG 0
#define HAL_AUDIO_CAPTURE_VERY_VERBOSE_DEBUG 0

#define HAL_AUDIO_ERROR(fmt, args...)    printf("\n\r[HAL_AUDIO][E]%s: " fmt, __FUNCTION__, ## args)
#define HAL_AUDIO_TIME(fmt, args...)    printf("\n\r[HAL_AUDIO][T]%s: " fmt, __FUNCTION__, ## args)

#if HAL_AUDIO_COMMON_DEBUG
#define HAL_AUDIO_DEBUG(fmt, args...)    printf("\n\r[HAL_AUDIO][D]%s: " fmt, __func__, ## args)
#define HAL_AUDIO_INFO(fmt, args...)     printf("\n\r[HAL_AUDIO][I]%s: " fmt, __FUNCTION__, ## args)
#define HAL_AUDIO_WARN(fmt, args...)     printf("\n\r[HAL_AUDIO][W]%s: " fmt, __FUNCTION__, ## args)
#define HAL_AUDIO_ENTER                  printf("\n\r[HAL_AUDIO]%s: =>", __FUNCTION__)
#define HAL_AUDIO_EXIT                   printf("\n\r[HAL_AUDIO]%s: <=", __FUNCTION__)
#define HAL_AUDIO_EXIT_ERR               printf("\n\r[HAL_AUDIO]%s: ERR <=", __FUNCTION__)
#define HAL_AUDIO_TRACE                  printf("\n\r[HAL_AUDIO]%s:%d<=", __FUNCTION__, __LINE__)
#else
#define HAL_AUDIO_DEBUG(fmt, args...)    do { } while(0)
#define HAL_AUDIO_INFO(fmt, args...)     do { } while(0)
#define HAL_AUDIO_WARN(fmt, args...)     do { } while(0)
#define HAL_AUDIO_ENTER                  do { } while(0)
#define HAL_AUDIO_EXIT                   do { } while(0)
#define HAL_AUDIO_EXIT_ERR               do { } while(0)
#define HAL_AUDIO_TRACE                  do { } while(0)
#endif

#if HAL_AUDIO_COMMON_DEBUG && HAL_AUDIO_VERBOSE_DEBUG
#define HAL_AUDIO_VERBOSE(fmt, args...)  printf("\n\r[HAL_AUDIO][V]%s: " fmt, __func__, ##args)
#else
#define HAL_AUDIO_VERBOSE(fmt, args...)  do { } while(0)
#endif

#if HAL_AUDIO_COMMON_DEBUG && HAL_AUDIO_VERBOSE_DEBUG && HAL_AUDIO_PLAYBACK_VERY_VERBOSE_DEBUG
#define HAL_AUDIO_PVERBOSE(fmt, args...) printf("\n\r[HAL_AUDIO][PV]%s: " fmt, __FUNCTION__, ## args)
#else
#define HAL_AUDIO_PVERBOSE(fmt, args...) do { } while(0)
#endif

#if HAL_AUDIO_COMMON_DEBUG && HAL_AUDIO_VERBOSE_DEBUG && HAL_AUDIO_CAPTURE_VERY_VERBOSE_DEBUG
#define HAL_AUDIO_CVERBOSE(fmt, args...) printf("\n\r[HAL_AUDIO][CV]%s: " fmt, __FUNCTION__, ## args)
#else
#define HAL_AUDIO_CVERBOSE(fmt, args...) do { } while(0)
#endif

#endif
