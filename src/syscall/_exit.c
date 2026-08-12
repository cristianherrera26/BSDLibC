#include <sys/syscall.h>
#include <syscall_asm.h>

__strong_alias(_Exit, _exit)
void
_exit(int exit_code)
{
	__syscall1(SYS_exit, exit_code);
}
