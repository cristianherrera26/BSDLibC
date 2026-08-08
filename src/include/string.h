#ifndef _STRING_H
#define _STRING_H	1

#include <stddef.h>

size_t strlen(const char *str);
size_t strnlen(const char *s, size_t maxlen);

void bcopy(const void *src0, void *dst0, size_t length);
void *memcpy(void *dst0, const void *src0, size_t length);
void *memmove(void *dst0, const void *src0, size_t length);

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

char *strrchr(const char *p, int ch);
char *strchr(const char *p, int ch);
char *rindex(const char *p, int ch);
char *index(const char *p, int ch);

char *strchrnul(const char *p, int ch);

#endif
