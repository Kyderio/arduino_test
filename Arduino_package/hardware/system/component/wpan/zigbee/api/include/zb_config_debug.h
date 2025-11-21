
#ifndef ZB_CONFIG_DEBUG_H__
#define ZB_CONFIG_DEBUG_H__

#include "stdio.h"
#include "stdlib.h"
#include <ameba_soc.h>
#include "rtk_wpan_osif.h"

#define WPAN_LOG_TAG "ZB"
#include "rtk_wpan_log.h"

#define ZB_LOG_DISABLE  0
#define ZB_LOG_ALWAYS   1
#define ZB_LOG_ERROR    2
#define ZB_LOG_WARNING  3
#define ZB_LOG_INFO     4
#define ZB_LOG_DEBUG    5

#ifndef ZB_LOG_LEVEL_DEFAULT
#define ZB_LOG_LEVEL_DEFAULT    ZB_LOG_ERROR
#endif

#define ZB_LOG(level, fmt, ...)\
do{\
    if(level <= ZB_LOG_LEVEL_DEFAULT && level > ZB_LOG_DISABLE) {\
        WPAN_LOGSA(fmt, ##__VA_ARGS__);\
    }\
}while(0);



#endif /* ZB_CONFIG_DEBUG_H__ */
