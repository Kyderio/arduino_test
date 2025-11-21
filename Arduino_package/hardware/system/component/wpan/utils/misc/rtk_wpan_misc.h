#ifndef RTK_WPAN_MISC_H_
#define RTK_WPAN_MISC_H_

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ameba_soc.h"
//#include "rtk_wpan_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#define COUNT_ARGS(...) (sizeof((int[]){__VA_ARGS__})/sizeof(int))
#define WPAN_MACRO_SELECT_3(a1, a2, a3, ...) a3
#define WPAN_MACRO_GET_SECOND_WITH_ONE_ARG(first)
#define WPAN_MACRO_GET_SECOND_WITH_TWO_ARGS(first, second) second
#define WPAN_MACRO_GET_SECOND_APPEND_NUM_ARGS(num, ...) WPAN_MACRO_GET_SECOND_WITH_##num(__VA_ARGS__)

#define WPAN_MACRO_HAS_ONE_ARG_OR_TWO_ARGS(...) WPAN_MACRO_SELECT_3(__VA_ARGS__, TWO_ARGS, ONE_ARG, JUNK)

#define WPAN_MACRO_GET_FIRST_ARG(first, ...) first
#define WPAN_MACRO_GET_SECOND_ARG(num, ...) WPAN_MACRO_GET_SECOND_APPEND_NUM_ARGS(num, __VA_ARGS__)

#define WPAN_MACRO_FIRST_ARG(...) WPAN_MACRO_GET_FIRST_ARG(__VA_ARGS__, JUNK)
#define WPAN_MACRO_SECOND_ARG(...) WPAN_MACRO_GET_SECOND_ARG(WPAN_MACRO_HAS_ONE_ARG_OR_TWO_ARGS(__VA_ARGS__), __VA_ARGS__)

#define WPAN_EXIT_LOG_RPINT  1
#if defined(WPAN_EXIT_LOG_RPINT) && WPAN_EXIT_LOG_RPINT
#define WPAN_FUNC_EXIT(execute_func)	 \
	do {\
		ret = execute_func;\
		if (ret != RTK_SUCCESS) {\
			WPAN_LOGSE("%s %d func fail, %d", __func__, __LINE__, ret);\
			goto exit;\
		}\
	} while (0)

#define WPAN_CHECK_EXCEPT_EXIT(ret_condition, ...)	 \
	do {\
		if (!(ret_condition)) {\
			__VA_ARGS__;\
			WPAN_LOGSE("%s %d check fail", __func__, __LINE__);\
			goto exit;\
		}\
	} while (0)
#else
#define WPAN_FUNC_EXIT(execute_func)	 \
	do {\
		ret = execute_func;\
		if (ret != RTK_SUCCESS) {\
			goto exit;\
		}\
	} while (0)

#define WPAN_CHECK_EXCEPT_EXIT(ret_condition, ...)	 \
	do {\
		if (!(ret_condition)) {\
			__VA_ARGS__;\
			goto exit;\
		}\
	} while (0)
#endif
#define WPAN_CHECK_DEBUG_EXIT(ret_condition, ...)	 \
	do {\
		if (!(ret_condition)) {\
			WPAN_MACRO_FIRST_ARG(__VA_ARGS__);\
			WPAN_MACRO_SECOND_ARG(__VA_ARGS__);\
			goto exit;\
		}\
	} while (0)

#define WPAN_MIN(a, b) ((b) < (a) ? (b) : (a))
#define WPAN_MAX(a, b) ((a) < (b) ? (b) : (a))

uint32_t rtk_wpan_hex_string_to_binary(const char *hex_string, uint8_t *buf, uint32_t max_buf_size);
int rtk_wpan_pinname_to_pin(char *pin_name, uint16_t *transfer_pin);

#ifdef __cplusplus
}
#endif

#endif
