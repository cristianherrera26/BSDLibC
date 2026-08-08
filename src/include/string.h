#ifndef _STRING_H
#define _STRING_H	1

#include <stddef.h>

size_t strlen(const char *str);
size_t strnlen(const char *s, size_t maxlen);

void bcopy(const void *src0, void *dst0, size_t length);
void *memcpy(void *dst0, const void *src0, size_t length);
void *memmove(void *dst0, const void *src0, size_t length);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

char *strrchr(const char *p, int ch);
char *strchr(const char *p, int ch);
char *rindex(const char *p, int ch);
char *index(const char *p, int ch);

char *strchrnul(const char *p, int ch);

char *strcat(char *s, const char *append);
char *strcpy(char *to, const char *from);
char *stpcpy(char * __restrict to, const char * __restrict from);

size_t strlcpy(char *__restrict dst, const char *__restrict src, size_t siz);

#endif
