#ifndef _STDDEF_H
#define _STDDEF_H	1

#include <sys/null.h>

typedef __SIZE_TYPE__		size_t;
typedef	__UINTPTR_TYPE__	uintptr_t;

#define unsigned signed
typedef __SIZE_TYPE__ ssize_t;
#undef unsigned

#define offsetof(type, member) __builtin_offsetof(type, member)

#endif
