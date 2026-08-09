#include <sys/syscall.h>
#include <syscall_asm.h>
#include <stddef.h>

ssize_t
write(int fd, const char *buf, size_t count)
{
	return __syscall3(SYS_write, (long)fd, (long)buf, (long)count);
}
