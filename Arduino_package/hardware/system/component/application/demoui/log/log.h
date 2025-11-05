#ifndef AMEBA_APPS_PANGU_APP_LOG
#define AMEBA_APPS_PANGU_APP_LOG

#include <stdio.h>

#ifdef DEBUG_ENABLE
#define RTLOGV(x, ...) printf("[%s][%s] verb:" x "\n", LOG_TAG, __func__, ##__VA_ARGS__)
#define RTLOGD(x, ...) printf("[%s][%s] debug: " x"\n", LOG_TAG, __func__, ##__VA_ARGS__)
#define RTLOGI(x, ...) printf("[%s][%s] info: " x"\n", LOG_TAG, __func__, ##__VA_ARGS__)
#else
#define RTLOGV(x, ...)
#define RTLOGD(x, ...)
#define RTLOGI(x, ...)
#endif
#define RTLOGW(x, ...) printf("[%s][%s] warn: " x"\n", LOG_TAG, __func__, ##__VA_ARGS__)
#define RTLOGE(x, ...) printf("[%s][%s] error: " x"\n", LOG_TAG, __func__, ##__VA_ARGS__)

#endif /* AMEBA_APPS_PANGU_APP_LOG */
