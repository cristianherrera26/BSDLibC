#include <syscall_arch.h>
#include <syscalls.h>

void
_exit(int exit_code)
{
	__syscall1(SYS_exit, (long)exit_code);
}
