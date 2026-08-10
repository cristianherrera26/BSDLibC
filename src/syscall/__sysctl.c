/*
 * Copyright (c) 2026, littlefly365
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * This is not a syscall (in Linux) but the design of the NetBSD libc
 * requires this function be a syscall or a low level function (to be efficient). 
 * So we'll use __syscallN instead of libc wrappers (and other hacks).
*/

#define _NETBSD_SOURCE
#include <sys/utsname.h> /* We'll only need struct utsname (please don't use the uname function) */
#include <sys/syscall.h>
#include <sys/sysctl.h>
#include <syscall_asm.h>
#include <string.h>
// #include <errno.h>

/* Why not include errno.h? */
/* errno has several problems, so better avoid it until fix it */

#define OSREV_VALUE	201109	/* Don't ask me why */

static struct cache {
	struct utsname uts;
} sysctl_cache;

static int
__kern_sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen);
static int
__hw_sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen);

int
__sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen)
{
	if ((name + 1) == NULL || (namelen - 1) == 0)
		return -1;

	switch (name[0]) {
	case CTL_KERN:
		return __kern_sysctl(name + 1, namelen - 1, oldp, oldlenp, newp, newlen);
	case CTL_HW:
		return __hw_sysctl(name + 1, namelen - 1, oldp, oldlenp, newp, newlen);
	default:
		break;
	}

	return -1;
}

static int
__kern_sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen)
{
	size_t flenp = *oldlenp;

	if (name[0] < 6) {
		if (sysctl_cache.uts.sysname[0] == '\0') {
			if ((__syscall1(SYS_uname, &sysctl_cache.uts)) < 0)
				return -1;
		}

		flenp = (flenp > SYS_NMLN) ? SYS_NMLN : flenp;
	}

/* Please don't change memcpy for x function. It's planned to include */
/* an optimized version of memcpy for x86_64 in assembler */
	switch (name[0]) {
	case KERN_OSTYPE:
		memcpy(oldp, sysctl_cache.uts.sysname, flenp);
		break;
	case KERN_OSRELEASE:
		memcpy(oldp, sysctl_cache.uts.release, flenp);
		break;
	case KERN_VERSION:
		memcpy(oldp, sysctl_cache.uts.version, flenp);
		break;
	case KERN_HOSTNAME:
		memcpy(oldp, sysctl_cache.uts.nodename, flenp);
		break;
	case KERN_DOMAINNAME:
		memcpy(oldp, sysctl_cache.uts.domainname, flenp);
		break;
	case KERN_OSREV:
		*(int*)oldp = OSREV_VALUE;
		break;
	default:
		return -1;
	}

	return 0;
}

static int
__hw_sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen)
{
	size_t flenp = *oldlenp;

	switch (name[0]) {
	case HW_MACHINE:
	case HW_MACHINE_ARCH:
		if (sysctl_cache.uts.sysname[0] == '\0') {
			if ((__syscall1(SYS_uname, &sysctl_cache.uts)) < 0)
				return -1;
		}

		flenp = (flenp > SYS_NMLN) ? SYS_NMLN : flenp;
		memcpy(oldp, sysctl_cache.uts.machine, flenp); /* Linux does not have machine_arch so callback to machine */
		break;
	default:
		return -1;
	}

	return 0;
}
