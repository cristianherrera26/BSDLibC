#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H	1

#include <sys/mmap.h>

#define	PROT_NONE	0x00	/* no permissions */
#define	PROT_READ	0x01	/* pages can be read */
#define	PROT_WRITE	0x02	/* pages can be written */
#define	PROT_EXEC	0x04	/* pages can be executed */

#define	MAP_SHARED	0x0001	/* share changes */
#define	MAP_PRIVATE	0x0002	/* changes are private */
	/* old MAP_COPY	0x0004	   "copy" region at mmap time */

/*
 * Other flags
 */
#define	MAP_REMAPDUP	 0x0004	/* mremap only: duplicate the mapping */
#define	MAP_FIXED	 0x0010	/* map addr must be exactly as requested */
#define	MAP_RENAME	 0x0020	/* Sun: rename private pages to file */
#define	MAP_NORESERVE	 0x0040	/* Sun: don't reserve needed swap area */
#define	MAP_INHERIT	 0x0080	/* region is retained after exec */
#define	MAP_HASSEMAPHORE 0x0200	/* region may contain semaphores */
#define	MAP_TRYFIXED     0x0400 /* attempt hint address, even within break */
#define	MAP_WIRED	 0x0800	/* mlock() mapping when it is established */

/*
 * Mapping type
 */
#define	MAP_FILE	0x0000	/* map from file (default) */
#define	MAP_ANONYMOUS	0x1000	/* allocated from memory, swap space */
#define	MAP_ANON	MAP_ANONYMOUS
#define	MAP_STACK	0x2000	/* allocated from memory, swap space (stack) */

/*
 * Error indicator returned by mmap(2)
 */
#define	MAP_FAILED	((void *) -1)	/* mmap() failed */

#define	MADV_NORMAL		POSIX_MADV_NORMAL
#define	MADV_RANDOM		POSIX_MADV_RANDOM
#define	MADV_SEQUENTIAL		POSIX_MADV_SEQUENTIAL
#define	MADV_WILLNEED		POSIX_MADV_WILLNEED
#define	MADV_DONTNEED		POSIX_MADV_DONTNEED
#define	MADV_SPACEAVAIL		5	/* Insure that resources are reserved */
#define	MADV_FREE		6	/* Pages are empty, free them */

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int madvise(void *addr, size_t len, int advice);

#endif
