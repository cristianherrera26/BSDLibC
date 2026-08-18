STRING := $(wildcard string/*.c)
CTYPE := $(wildcard ctype/*.c)
LINUX := $(wildcard linux/*.c)
GEN := $(wildcard gen/*.c)
STDLIB := $(wildcard stdlib/*.c)
MD := $(wildcard md/*.c)
COMPAT := $(wildcard compat/OpenBSD/*.c) $(wildcard compat/NetBSD/*.c)

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

ALL_SRCS := $(STRING) $(CTYPE) $(LINUX) $(GEN) $(STDLIB) $(MD) $(COMPAT)
ALL_OBJS := $(ALL_SRCS:%.c=%.o)
