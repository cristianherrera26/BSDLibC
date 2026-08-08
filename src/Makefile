LIB=c
SHLIB_MAJOR=1

CFLAGS += -nostdinc -nostdlib
CFLAGS += -I${.CURDIR}/include

.PATH: ${.CURDIR}/gen
.include "${.CURDIR}/gen/Makefile.inc"
.PATH: ${.CURDIR}/string
.include "${.CURDIR}/string/Makefile.inc"

.include <bsd.lib.mk>
