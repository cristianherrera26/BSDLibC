/*	$NetBSD: index.c,v 1.15 2005/12/20 19:31:50 christos Exp $	*/

#include <string.h>

char *
index(const char *p, int ch)
{
	return strchr(p, ch);
}
