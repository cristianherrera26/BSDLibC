#include <sys/syscall.h>
#include <syscall_asm.h>

void
_exit(int exit_code)
{
	__syscall1(SYS_exit, (long)exit_code);
}
