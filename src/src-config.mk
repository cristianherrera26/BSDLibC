STRING := $(wildcard string/*.c)
CTYPE := $(wildcard ctype/*.c)
SYSCALL := $(wildcard linux/*.c)
GEN := $(wildcard gen/*.c)
STDLIB := $(wildcard stdlib/*.c)
COMPAT_OPENBSD := $(wildcard compat/OpenBSD/*.c)
COMPAT := $(COMPAT_OPENBSD)

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

ALL_SRCS := $(STRING) $(CTYPE) $(SYSCALL) $(GEN) $(STDLIB) $(COMPAT)
ALL_OBJS := $(ALL_SRCS:%.c=%.o)
