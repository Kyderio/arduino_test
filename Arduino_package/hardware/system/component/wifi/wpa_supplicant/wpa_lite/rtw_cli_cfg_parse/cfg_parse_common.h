/*
 * wpa_supplicant/hostapd / common helper functions, etc.
 * Copyright (c) 2002-2007, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef CFG_PARSE_COMMON_H
#define CFG_PARSE_COMMON_H

#include "whc_dev.h"
#include "os_wrapper.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

#ifndef os_strcmp
#define os_strcmp(s1, s2) strcmp((s1), (s2))
#endif

#ifndef os_malloc
#define os_malloc(s) malloc((s))
#endif

#ifndef os_free
#define os_free(p) free((p))
#endif

#ifndef os_strlen
#define os_strlen(s) strlen(s)
#endif

#ifndef os_strcmp
#define os_strcmp(s1, s2) strcmp((s1), (s2))
#endif
#ifndef os_strrchr
#define os_strrchr(s, c) strrchr((s), (c))
#endif

#ifndef os_memcpy
#define os_memcpy(d, s, n) memcpy((d), (s), (n))
#endif
#ifndef os_memmove
#define os_memmove(d, s, n) memmove((d), (s), (n))
#endif
#ifndef os_memset
#define os_memset(s, c, n) memset(s, c, n)
#endif
#ifndef os_memcmp
#define os_memcmp(s1, s2, n) memcmp((s1), (s2), (n))
#endif

#ifndef os_strdup
#define os_strdup(s) strdup(s)
#endif

#ifndef SSID_MAX_LEN
#define SSID_MAX_LEN 32
#endif

#ifndef PMk_LEN
#define PMK_LEN 32
#endif

enum {
	MSG_EXCESSIVE, MSG_MSGDUMP, MSG_DEBUG, MSG_INFO, MSG_WARNING, MSG_ERROR
};

__weak void wpa_printf(int level, const char *fmt, ...)
{
	(void) level;
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	printf("\n");
	va_end(ap);
}


int hexstr2bin(const char *hex, u8 *buf, size_t len);
void wpa_printf(int level, const char *fmt, ...);
size_t printf_decode(u8 *buf, size_t maxlen, const char *str);
int has_ctrl_char(const u8 *data, size_t len);
void str_clear_free(char *str);
void forced_memzero(void *ptr, size_t len);


#endif /* CFG_PARSE_COMMON_H */
