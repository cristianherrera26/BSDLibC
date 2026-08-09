#include <sys/syscall.h>
#include <syscall_asm.h>
#include <stddef.h>

ssize_t
read(int fd, void *buf, size_t count)
{
	return __syscall3(SYS_read, (long)fd, (long)buf, (long)count);
}
