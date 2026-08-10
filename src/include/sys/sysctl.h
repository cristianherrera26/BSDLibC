#ifndef _SYS_SYSCTL_H
#define _SYS_SYSCTL_H	1

#include <sys/types.h>

int sysctl(const int *, unsigned int, void *, size_t *, const void *, size_t);

/* CTL_* (0-9) */
#define CTL_KERN	0
#define CTL_HW		1
#define CTL_USER	2

#endif
