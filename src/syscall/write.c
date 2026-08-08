#include <syscall_arch.h>
#include <syscalls.h>
#include <stddef.h>

ssize_t
write(int fd, const char *buf, size_t count)
{
	return __syscall3(SYS_write, (long)fd, (long)buf, (long)count);
}
