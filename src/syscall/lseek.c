#include <sys/types.h>
#include <sys/syscall.h>
#include <syscall_asm.h>

off_t
lseek(int fd, off_t offset, int whence)
{
	return __syscall3(SYS_lseek, fd, offset, whence);
}
