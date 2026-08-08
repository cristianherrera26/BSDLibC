LIB=c
USE_SHLIBDIR=yes

MACHINE != uname -m

CFLAGS += -nostdinc -ffreestanding
CFLAGS += -I${.CURDIR}/include -I${.CURDIR}/arch/${MACHINE}/include
LDADD += -nostdlib -ffreestanding

.PATH: ${.CURDIR}/ctype
.include "${.CURDIR}/ctype/Makefile.inc"
.PATH: ${.CURDIR}/gen
.include "${.CURDIR}/gen/Makefile.inc"
.PATH: ${.CURDIR}/stdlib
.include "${.CURDIR}/stdlib/Makefile.inc"
.PATH: ${.CURDIR}/string
.include "${.CURDIR}/string/Makefile.inc"
.PATH: ${.CURDIR}/syscall
.include "${.CURDIR}/syscall/Makefile.inc"

.include <bsd.lib.mk>
