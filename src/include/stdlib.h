#ifndef _STDLIB_H
#define _STDLIB_H	1

#include <sys/types.h>
#include <sys/null.h>

#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

int abs(int j);
long labs(long j);
long long int llabs(long long int j);
void _Exit(int exit_code);
const char *getprogname(void);
void setprogname(const char *progname);

void abort(void);

void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void *malloc(size_t size);
int posix_memalign(void **, size_t, size_t);

void qsort_r(void *a, size_t n, size_t es, int (*cmp)(const void *, const void *, void *), void *cookie);
void qsort(void *a, size_t n, size_t es, int (*cmp)(const void *, const void *));

int reallocarr(void *ptr, size_t number, size_t size);
void *reallocarray(void *optr, size_t nmemb, size_t size);

int heapsort_r(void *vbase, size_t nmemb, size_t size, int (*compar)(const void *, const void *, void *), void *cookie);
int heapsort(void *a, size_t n, size_t es, int (*cmp)(const void *, const void *));

#endif
