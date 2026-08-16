#ifndef _UNISTD_H
#define _UNISTD_H	1

#include <sys/types.h>
#include <stddef.h>

pid_t fork(void);
pid_t getpid(void);
ssize_t write(int fd, const void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
void _exit(int exit_code);
int
__sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen);
int getdomainname(char *name, size_t namelen);
int gethostname(char *name, size_t namelen);

int close(int fd);
void sync(void);
int getpagesize(void);

#endif
