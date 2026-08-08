#ifndef _STRING_H
#define _STRING_H	1

#include <stddef.h>

size_t strlen(const char *str);
size_t strnlen(const char *s, size_t maxlen);

void bcopy(const void *src0, void *dst0, size_t length);
void *memcpy(void *dst0, const void *src0, size_t length);
void *memmove(void *dst0, const void *src0, size_t length);

#endif
