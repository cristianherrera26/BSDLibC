/*	$NetBSD: rindex.c,v 1.15 2005/12/20 19:31:50 christos Exp $	*/

#include <string.h>

char *
rindex(const char *p, int ch)
{
	return strrchr(p, ch);
}
