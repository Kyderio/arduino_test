#ifndef AMEBA_AUDIO_BASE_XLIB_INCLUDE_XLIB_STRING_EXT_H
#define AMEBA_AUDIO_BASE_XLIB_INCLUDE_XLIB_STRING_EXT_H

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);
size_t strnlen(const char *str, size_t maxlen);

int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

char *strdup(const char *str);

#ifdef __cplusplus
}
#endif

#endif // AMEBA_AUDIO_BASE_XLIB_INCLUDE_XLIB_STRING_EXT_H
