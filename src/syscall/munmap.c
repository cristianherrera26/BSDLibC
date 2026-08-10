#include <sys/syscall.h>
#include <sys/types.h>
#include <syscall_asm.h>

int
munmap(void *start, size_t len)
{
	return __syscall2(SYS_munmap, start, len);
}
