UNAME_M != uname -m
MACHINE ?= UNAME_M

INCS+=	${MACHINE}/include/syscalls.h ${MACHINE}/include/
