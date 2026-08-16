#ifndef _SYS_SYSCTL_H
#define _SYS_SYSCTL_H	1

#include <sys/types.h>

int sysctl(const int *, unsigned int, void *, size_t *, const void *, size_t);

/* CTL_* (1-9) */
#define CTL_KERN	1
#define CTL_HW		2
#define CTL_USER	3

#define KERN_OSTYPE	1
#define KERN_OSRELEASE	2
#define KERN_VERSION	3
#define KERN_HOSTNAME	4
#define KERN_DOMAINNAME	5
#define KERN_OSREV	6

#define HW_MACHINE	1
#define HW_MACHINE_ARCH	2
#define HW_PAGESIZE	3

#endif
