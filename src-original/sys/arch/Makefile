#	$NetBSD: Makefile,v 1.48 2024/01/03 03:56:36 thorpej Exp $

# For now, we install the machine and arch includes, and symlink 'machine'
# to the location of the machine includes (usually).
#
# Eventually, we should install everything.

.include <bsd.own.mk>

.if exists(${MACHINE})
SUBDIR+= ${MACHINE}
.else
.error "Your arch is ${MACHINE}, but the ${MACHINE} directory is missing"
.endif

INCSYMLINKS= ${MACHINE} /usr/include/machine
INCSYMLINKS+= machine/float.h /usr/include/float.h

.include <bsd.kinc.mk>
