#ifndef __EXAMPLE_VOICE_VOICE_MANAGER_H__
#define __EXAMPLE_VOICE_VOICE_MANAGER_H__


#include "ringbuffer.h"

#define VOICE_DEBUG 0
#if VOICE_DEBUG
#define LOGV(fmt, ...)  printf("VOICE : " fmt "\n", ##__VA_ARGS__)
#else
#define LOGV(fmt, ...)  do { } while(0)
#endif
#define LOGD(fmt, ...)  printf("MCU_VOICE : " fmt "\n", ##__VA_ARGS__)
#define LOGI(fmt, ...)  printf("MCU_VOICE : " fmt "\n", ##__VA_ARGS__)
#define LOGE(fmt, ...)  printf("MCU_VOICE : error - " fmt "\n", ##__VA_ARGS__)

#define RES_DATA_ADDR								0x08E04020
#define RECORD_SIZE									960
#define DEFAULT_STACK_SIZE							4096
#define RING_BUFFER_SIZE							4096
#define VOICE_DATA_CHANNEL0							0
#define VOICE_DATA_CHANNEL1							1

#define VOIDCE_KEY_WORD_ID_1						1
#define VOIDCE_KEY_WORD_ID_2						2

#define VOIDCE_KEY_WORD_VOLUME_UP1					40
#define VOIDCE_KEY_WORD_VOLUME_UP2					87

#define VOIDCE_KEY_WORD_VOLUME_DOWN1				41
#define VOIDCE_KEY_WORD_VOLUME_DOWN2				89

#ifdef CONFIG_ARM_CORE_CM4
#define VOICE_RPC_MODE (BLOCK_MODE | (RPC_NP_DSP << 1) | (RPC_DSP_NP << 4))
#elif defined(CONFIG_RSICV_CORE_KR4)
#define VOICE_RPC_MODE (BLOCK_MODE | (RPC_AP_DSP << 1) | (RPC_DSP_AP << 4))
#endif
int32_t PreInit(void);
int32_t Init(void);
int32_t Start(void);
int32_t Pause(void);
int32_t Stop(void);
int32_t Release(void);

#endif //__EXAMPLE_VOICE_VOICE_MANAGER_H__