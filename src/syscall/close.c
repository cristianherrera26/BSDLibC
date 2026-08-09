#include <sys/syscall.h>
#include <syscall_asm.h>

int
close(int fd)
{
	return __syscall1(SYS_fork, (long)fd);
}
