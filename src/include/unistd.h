#ifndef _UNISTD_H
#define _UNISTD_H	1

#include <sys/types.h>
#include <stddef.h>

pid_t fork(void);
ssize_t write(int fd, const char *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
void _exit(int exit_code);

#endif
