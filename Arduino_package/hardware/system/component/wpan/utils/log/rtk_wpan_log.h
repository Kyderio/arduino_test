#ifndef RTK_WPAN_LOG_H_
#define RTK_WPAN_LOG_H_

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <diag.h>
#include <log.h>
#include "rtk_wpan_osif.h"
#include "rtk_wpan_misc.h"
#include "rtk_wpan_log_save.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WPAN_LOG_LOCK_EN 0
#define WPAN_LOG_LEVEL_DYNAMIC 1
#if (defined(CONFIG_ARM_CORE_CA32) && CONFIG_ARM_CORE_CA32) || (defined(WPAN_LOG_SAVE_VFS) && WPAN_LOG_SAVE_VFS)
#undef WPAN_LOG_LOCK_EN
#define WPAN_LOG_LOCK_EN 1
#endif

#if defined(WPAN_LOG_LOCK_EN) && WPAN_LOG_LOCK_EN
extern wpan_osif_lock wpan_log_osif_lock;
#define wpan_log_lock() rtk_wpan_osif_lock(&wpan_log_osif_lock)
#define wpan_log_unlock(isr_status) rtk_wpan_osif_unlock(&wpan_log_osif_lock, isr_status)
#else
#define wpan_log_lock() 0
#define wpan_log_unlock(isr_status)
#endif

#ifndef WPAN_LOG_TAG
#define WPAN_LOG_TAG "WPAN"
#endif

#define WPAN_LOG_LEVEL_NONE   0
#define WPAN_LOG_LEVEL_ALWAYS 1
#define WPAN_LOG_LEVEL_ERROR  2
#define WPAN_LOG_LEVEL_WARN   3
#define WPAN_LOG_LEVEL_INFO   4
#define WPAN_LOG_LEVEL_DEBUG  5

#if defined(WPAN_LOG_LEVEL_DYNAMIC) && WPAN_LOG_LEVEL_DYNAMIC
#define WPAN_LOG_DEFAULT_LEVEL  WPAN_LOG_LEVEL_ERROR
extern uint8_t wpan_log_level;
#define WPAN_LOG_LEVEL  wpan_log_level
int rtk_wpan_log_level_set(uint8_t level);
uint8_t rtk_wpan_log_level_get(void);
#else
#define WPAN_LOG_DEFAULT_LEVEL  WPAN_LOG_LEVEL_ERROR
#define WPAN_LOG_LEVEL  WPAN_LOG_LEVEL_INFO
#endif

#define WPAN_LOG_LETTER_NONE   '#'
#define WPAN_LOG_LETTER_ALWAYS 'A'
#define WPAN_LOG_LETTER_ERROR  'E'
#define WPAN_LOG_LETTER_WARN   'W'
#define WPAN_LOG_LETTER_INFO   'I'
#define WPAN_LOG_LETTER_DEBUG  'D'

int rtk_wpan_log_init(void);
int rtk_wpan_log_deinit(void);
void rtk_wpan_log_vprintf(const char *tag, const char letter, const char *fmt, va_list args);
void rtk_wpan_log_vprintf_nano(const char *tag, const char letter, const char *fmt, va_list args);
void rtk_wpan_log_printf(const char *tag, const char letter, const char *fmt, ...);
void rtk_wpan_log_printf_nano(const char *tag, const char letter, const char *fmt, ...);
void rtk_wpan_log_dump(const char *tag, const char letter, const char *text, void *buf, uint16_t len);

#define WPAN_LOG_PRINTS(_log_level, _log_tag, _log_letter, _log_fmt, ...)	 \
	do {\
		if (_log_level <= WPAN_LOG_LEVEL) {\
			rtk_wpan_log_printf_nano(_log_tag, _log_letter, _log_fmt, ##__VA_ARGS__); \
		}\
	} while(0)

#define WPAN_LOG_PRINT(_log_level, _log_tag, _log_letter, _log_fmt, ...)	 \
	do {\
		if (_log_level <= WPAN_LOG_LEVEL) {\
			rtk_wpan_log_printf(_log_tag, _log_letter, _log_fmt, ##__VA_ARGS__); \
		}\
	} while(0)

#define WPAN_LOGV_PRINTS(_log_level, _log_tag, _log_letter, _log_fmt, _log_args)	 \
	do {\
		if (_log_level <= WPAN_LOG_LEVEL) {\
			rtk_wpan_log_vprintf_nano(_log_tag, _log_letter, _log_fmt, _log_args); \
		}\
	} while(0)

#define WPAN_LOGV_PRINT(_log_level, _log_tag, _log_letter, _log_fmt, _log_args)	 \
	do {\
		if (_log_level <= WPAN_LOG_LEVEL) {\
			rtk_wpan_log_vprintf(_log_tag, _log_letter, _log_fmt, _log_args); \
		}\
	} while(0)

#define WPAN_BUF_DUMP(_log_level, _log_tag, _log_letter, _dump_text, _dump_buf, _dump_len)	 \
	do {\
		if (_log_level <= WPAN_LOG_LEVEL) {\
			rtk_wpan_log_dump(_log_tag, _log_letter, _dump_text, _dump_buf, _dump_len);\
		}\
	} while(0)

#if (WPAN_LOG_LEVEL_DYNAMIC || (WPAN_LOG_LEVEL >= WPAN_LOG_LEVEL_ALWAYS))
#define WPAN_LOGSA(_log_fmt, ...)			 WPAN_LOG_PRINTS(WPAN_LOG_LEVEL_ALWAYS, WPAN_LOG_TAG, WPAN_LOG_LETTER_ALWAYS, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGA(_log_fmt, ...)			  WPAN_LOG_PRINT(WPAN_LOG_LEVEL_ALWAYS, WPAN_LOG_TAG, WPAN_LOG_LETTER_ALWAYS, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGVSA(_log_fmt, _log_args)	  WPAN_LOGV_PRINTS(WPAN_LOG_LEVEL_ALWAYS, WPAN_LOG_TAG, WPAN_LOG_LETTER_ALWAYS, _log_fmt, _log_args)
#define WPAN_LOGVA(_log_fmt, _log_args)	   WPAN_LOGV_PRINT(WPAN_LOG_LEVEL_ALWAYS, WPAN_LOG_TAG, WPAN_LOG_LETTER_ALWAYS, _log_fmt, _log_args)
#define WPAN_DUMPA(_dump_text, _dump_buf, _dump_len)	WPAN_BUF_DUMP(WPAN_LOG_LEVEL_ALWAYS, WPAN_LOG_TAG, WPAN_LOG_LETTER_ALWAYS, _dump_text, ((void *)_dump_buf), ((uint16_t)_dump_len))
#define WPAN_DUMP16A(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DUMP32A(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DEBUGSA(_log_fmt, _log_args)	 WPAN_LOGSA("%s %d"_log_fmt"\r\n", __func__, __LINE__, _log_args)
#else
#define WPAN_LOGSA(_log_fmt, ...)
#define WPAN_LOGA(_log_fmt, ...)
#define WPAN_LOGVSA(_log_fmt, _log_args)
#define WPAN_LOGVA(_log_fmt, _log_args)
#define WPAN_DUMPA(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP16A(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP32A(_dump_text, _dump_buf, _dump_len)
#define WPAN_DEBUGSA(_log_fmt, _log_args)
#endif
#if (WPAN_LOG_LEVEL_DYNAMIC || (WPAN_LOG_LEVEL >= WPAN_LOG_LEVEL_ERROR))
#define WPAN_LOGSE(_log_fmt, ...)			 WPAN_LOG_PRINTS(WPAN_LOG_LEVEL_ERROR, WPAN_LOG_TAG, WPAN_LOG_LETTER_ERROR, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGE(_log_fmt, ...)			  WPAN_LOG_PRINT(WPAN_LOG_LEVEL_ERROR, WPAN_LOG_TAG, WPAN_LOG_LETTER_ERROR, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGVSE(_log_fmt, _log_args)	  WPAN_LOGV_PRINTS(WPAN_LOG_LEVEL_ERROR, WPAN_LOG_TAG, WPAN_LOG_LETTER_ERROR, _log_fmt, _log_args)
#define WPAN_LOGVE(_log_fmt, _log_args)	   WPAN_LOGV_PRINT(WPAN_LOG_LEVEL_ERROR, WPAN_LOG_TAG, WPAN_LOG_LETTER_ERROR, _log_fmt, _log_args)
#define WPAN_DUMPE(_dump_text, _dump_buf, _dump_len)   WPAN_BUF_DUMP(WPAN_LOG_LEVEL_ERROR, WPAN_LOG_TAG, WPAN_LOG_LETTER_ERROR, _dump_text, ((void *)_dump_buf), ((uint16_t)_dump_len))
#define WPAN_DUMP16E(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DUMP32E(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DEBUGSE(_log_fmt, _log_args)	 WPAN_LOGSE("%s %d"_log_fmt"\r\n", __func__, __LINE__, _log_args)
#else
#define WPAN_LOGSE(_log_fmt, ...)
#define WPAN_LOGE(_log_fmt, ...)
#define WPAN_LOGVSE(_log_fmt, _log_args)
#define WPAN_LOGVE(_log_fmt, _log_args)
#define WPAN_DUMPE(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP16E(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP32E(_dump_text, _dump_buf, _dump_len)
#define WPAN_DEBUGSE(_log_fmt, _log_args)
#endif
#if (WPAN_LOG_LEVEL_DYNAMIC || (WPAN_LOG_LEVEL >= WPAN_LOG_LEVEL_WARN))
#define WPAN_LOGSW(_log_fmt, ...)			 WPAN_LOG_PRINTS(WPAN_LOG_LEVEL_WARN, WPAN_LOG_TAG, WPAN_LOG_LETTER_WARN, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGW(_log_fmt, ...)			  WPAN_LOG_PRINT(WPAN_LOG_LEVEL_WARN, WPAN_LOG_TAG, WPAN_LOG_LETTER_WARN, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGVSW(_log_fmt, _log_args)	  WPAN_LOGV_PRINTS(WPAN_LOG_LEVEL_WARN, WPAN_LOG_TAG, WPAN_LOG_LETTER_WARN, _log_fmt, _log_args)
#define WPAN_LOGVW(_log_fmt, _log_args)	   WPAN_LOGV_PRINT(WPAN_LOG_LEVEL_WARN, WPAN_LOG_TAG, WPAN_LOG_LETTER_WARN, _log_fmt, _log_args)
#define WPAN_DUMPW(_dump_text, _dump_buf, _dump_len)   WPAN_BUF_DUMP(WPAN_LOG_LEVEL_WARN, WPAN_LOG_TAG, WPAN_LOG_LETTER_WARN, _dump_text, ((void *)_dump_buf), ((uint16_t)_dump_len))
#define WPAN_DUMP16W(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DUMP32W(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DEBUGSW(_log_fmt, _log_args)	 WPAN_LOGSW("%s %d"_log_fmt"\r\n", __func__, __LINE__, _log_args)
#else
#define WPAN_LOGSW(_log_fmt, ...)
#define WPAN_LOGW(_log_fmt, ...)
#define WPAN_LOGVSW(_log_fmt, _log_args)
#define WPAN_LOGVW(_log_fmt, _log_args)
#define WPAN_DUMPW(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP16W(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP32W(_dump_text, _dump_buf, _dump_len)
#define WPAN_DEBUGSW(_log_fmt, _log_args)
#endif
#if (WPAN_LOG_LEVEL_DYNAMIC || (WPAN_LOG_LEVEL >= WPAN_LOG_LEVEL_INFO))
#define WPAN_LOGSI(_log_fmt, ...)			 WPAN_LOG_PRINTS(WPAN_LOG_LEVEL_INFO, WPAN_LOG_TAG, WPAN_LOG_LETTER_INFO, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGI(_log_fmt, ...)			  WPAN_LOG_PRINT(WPAN_LOG_LEVEL_INFO, WPAN_LOG_TAG, WPAN_LOG_LETTER_INFO, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGVSI(_log_fmt, _log_args)	  WPAN_LOGV_PRINTS(WPAN_LOG_LEVEL_INFO, WPAN_LOG_TAG, WPAN_LOG_LETTER_INFO, _log_fmt, _log_args)
#define WPAN_LOGVI(_log_fmt, _log_args)	   WPAN_LOGV_PRINT(WPAN_LOG_LEVEL_INFO, WPAN_LOG_TAG, WPAN_LOG_LETTER_INFO, _log_fmt, _log_args)
#define WPAN_DUMPI(_dump_text, _dump_buf, _dump_len)   WPAN_BUF_DUMP(WPAN_LOG_LEVEL_INFO, WPAN_LOG_TAG, WPAN_LOG_LETTER_INFO, _dump_text, ((void *)_dump_buf), ((uint16_t)_dump_len))
#define WPAN_DUMP16I(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DUMP32I(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DEBUGSI(_log_fmt, _log_args)	 WPAN_LOGSI("%s %d"_log_fmt"\r\n", __func__, __LINE__, _log_args)
#else
#define WPAN_LOGSI(_log_fmt, ...)
#define WPAN_LOGI(_log_fmt, ...)
#define WPAN_LOGVSI(_log_fmt, _log_args)
#define WPAN_LOGVI(_log_fmt, _log_args)
#define WPAN_DUMPI(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP16I(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP32I(_dump_text, _dump_buf, _dump_len)
#define WPAN_DEBUGSI(_log_fmt, _log_args)
#endif
#if (WPAN_LOG_LEVEL_DYNAMIC || (WPAN_LOG_LEVEL >= WPAN_LOG_LEVEL_DEBUG))
#define WPAN_LOGSD(_log_fmt, ...)			 WPAN_LOG_PRINTS(WPAN_LOG_LEVEL_DEBUG, WPAN_LOG_TAG, WPAN_LOG_LETTER_DEBUG, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGD(_log_fmt, ...)			  WPAN_LOG_PRINT(WPAN_LOG_LEVEL_DEBUG, WPAN_LOG_TAG, WPAN_LOG_LETTER_DEBUG, _log_fmt"\r\n", ##__VA_ARGS__)
#define WPAN_LOGVSD(_log_fmt, _log_args)	  WPAN_LOGV_PRINTS(WPAN_LOG_LEVEL_DEBUG, WPAN_LOG_TAG, WPAN_LOG_LETTER_DEBUG, _log_fmt, _log_args)
#define WPAN_LOGVD(_log_fmt, _log_args)	   WPAN_LOGV_PRINT(WPAN_LOG_LEVEL_DEBUG, WPAN_LOG_TAG, WPAN_LOG_LETTER_DEBUG, _log_fmt, _log_args)
#define WPAN_DUMPD(_dump_text, _dump_buf, _dump_len)   WPAN_BUF_DUMP(WPAN_LOG_LEVEL_DEBUG, WPAN_LOG_TAG, WPAN_LOG_LETTER_DEBUG, _dump_text, ((void *)_dump_buf), ((uint16_t)_dump_len))
#define WPAN_DUMP16D(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DUMP32D(_dump_text, _dump_buf, _dump_len) // RESERVE
#define WPAN_DEBUGSD(_log_fmt, _log_args)	 WPAN_LOGSD("%s %d"_log_fmt"\r\n", __func__, __LINE__, _log_args)
#else
#define WPAN_LOGSD(_log_fmt, ...)
#define WPAN_LOGD(_log_fmt, ...)
#define WPAN_LOGVSD(_log_fmt, _log_args)
#define WPAN_LOGVD(_log_fmt, _log_args)
#define WPAN_DUMPD(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP16D(_dump_text, _dump_buf, _dump_len)
#define WPAN_DUMP32D(_dump_text, _dump_buf, _dump_len)
#define WPAN_DEBUGSD(_log_fmt, _log_args)
#endif

#ifdef __cplusplus
}
#endif

#endif
