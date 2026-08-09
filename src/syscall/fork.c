#include <sys/syscall.h>
#include <sys/types.h>
#include <syscall_asm.h>

pid_t
fork(void)
{
	return __syscall0(SYS_fork);
}
