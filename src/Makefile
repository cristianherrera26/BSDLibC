LIB=c
SHLIB_MAJOR=1

CFLAGS += -nostdinc -ffreestanding
CFLAGS += -I${.CURDIR}/include
LDADD += -nostdlib -ffreestanding

.PATH: ${.CURDIR}/gen
.include "${.CURDIR}/gen/Makefile.inc"
.PATH: ${.CURDIR}/string
.include "${.CURDIR}/string/Makefile.inc"

.include <bsd.lib.mk>
