UNAME_M != uname -m
MACHINE ?= UNAME_M

.PATH: ${MACHINE}
INCS+=	machine/cdefs.h machine/int_const.h machine/int_limits.h machine/int_mwgwtypes.h machine/int_types.h \
	machine/syscalls.h machine/wchar_limits.h
