#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>

extern int
__sysctl(const int *name, unsigned int namelen, void *oldp,
        size_t *oldlenp, const void *newp, size_t newlen);

static int user_sysctl(const int *, unsigned int, void *,
			size_t *, const void *, size_t);
int
sysctl(const int *name, unsigned int namelen, void *oldp,
	size_t *oldlenp, const void *newp, size_t newlen)
{
	size_t oldlen;

	oldlen = (oldlenp == NULL) ? 0 : *oldlenp;

	if (name[0] != CTL_USER)
		return __sysctl(name, namelen, oldp, &oldlen, newp, newlen);

	return user_sysctl(name + 1, namelen - 1, oldp, &oldlen, newp, newlen);
}

static int
user_sysctl(const int *name, unsigned int namelen, void *oldp,
	size_t *oldlenp, const void *newp, size_t newlen)
{
	return -1;
}
