#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H	1

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

#endif
