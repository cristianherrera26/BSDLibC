/*	$NetBSD: errno.c,v 1.6 2024/01/20 14:52:47 christos Exp $	*/

#include <sys/cdefs.h>
#if defined(LIBC_SCCS) && !defined(lint)
__RCSID("$NetBSD: errno.c,v 1.6 2024/01/20 14:52:47 christos Exp $");
#endif /* LIBC_SCCS and not lint */

#include <errno.h>

int errno;
