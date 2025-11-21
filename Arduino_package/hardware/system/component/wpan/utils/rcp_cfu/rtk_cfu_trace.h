#ifndef RTK_CFU_TRACE_H_
#define RTK_CFU_TRACE_H_

#include "rtk_wpan_osif.h"
#include "ameba_soc.h"
#include "platform_autoconf.h"

#include "rtk_wpan_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#define log_level_debug  0x08
#define log_level_info   0x04
#define log_level_warn   0x02
#define log_level_err    0x01

#define log_module_trace_init(mask)

#define log_module_trace_set(mask)

#define log_module_trace_get()

#define log_disable()

#ifndef SHOW_PROMPT_TO_STDOUT
#define SHOW_PROMPT_TO_STDOUT 0
#endif

#if SHOW_PROMPT_TO_STDOUT
#define log_prompt(fmt, ...)    WPAN_LOGA(fmt, ##__VA_ARGS__)
#define log_err(fmt, ...)       WPAN_LOGE(fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...)      WPAN_LOGW(fmt, ##__VA_ARGS__)
#define log_info(fmt, ...)      WPAN_LOGI(fmt, ##__VA_ARGS__)
#define log_debug(fmt, ...)     WPAN_LOGD(fmt, ##__VA_ARGS__)
#else
#define log_prompt(fmt, ...)
#define log_err(fmt, ...)
#define log_warn(fmt, ...)
#define log_info(fmt, ...)
#define log_debug(fmt, ...)
#endif

#ifdef __cplusplus
}
#endif

#endif