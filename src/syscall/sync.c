#include <sys/syscall.h>
#include <sys/types.h>
#include <syscall_asm.h>

void
sync(void)
{
	return __syscall0(SYS_sync);
}
