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
void *memset(void *dst0, int c0, size_t length);
void *memmem(const void *h0, size_t k, const void *n0, size_t l);
void *memccpy(void *t, const void *f, int c, size_t n);
void *mempcpy(void *__restrict dst, const void *__restrict src, size_t len);

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strstr(const char *s, const char *find);
char *strnstr(const char *s, const char *find, size_t slen);
char *strcasestr(const char *s, const char *find);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

char *strrchr(const char *p, int ch);
char *strchr(const char *p, int ch);
char *rindex(const char *p, int ch);
char *index(const char *p, int ch);
char *strsep(char **stringp, const char *delim);
char *strpbrk(const char *s, const char *charset);

char *strchrnul(const char *p, int ch);

char *strcat(char *s, const char *append);
char *strcpy(char *to, const char *from);
char *stpcpy(char * __restrict to, const char * __restrict from);
char *stpncpy(char * __restrict dst, const char * __restrict src, size_t n);

size_t strlcpy(char *__restrict dst, const char *__restrict src, size_t siz);
size_t strlcat(char *__restrict dst, const char *__restrict src, size_t siz);
char *strncpy(char *dst, const char *src, size_t n);
char *strncat(char *dst, const char *src, size_t n);
void bzero(void *dst0, size_t length);
int consttime_memequal(const void *b1, const void *b2, size_t len);

#endif
