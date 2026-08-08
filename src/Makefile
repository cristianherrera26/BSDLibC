LIB=c
USE_SHLIBDIR=yes

CFLAGS += -nostdinc -ffreestanding
CFLAGS += -I${.CURDIR}/include
LDADD += -nostdlib -ffreestanding

.PATH: ${.CURDIR}/ctype
.include "${.CURDIR}/ctype/Makefile.inc"
.PATH: ${.CURDIR}/gen
.include "${.CURDIR}/gen/Makefile.inc"
.PATH: ${.CURDIR}/string
.include "${.CURDIR}/string/Makefile.inc"

.include <bsd.lib.mk>
