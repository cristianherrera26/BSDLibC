STRING := $(wildcard string/*.c)
CTYPE := $(wildcard ctype/*.c)
SYSCALL := $(wildcard syscall/*.c)
GEN := $(wildcard gen/*.c)
STDLIB := $(wildcard stdlib/*.c)
STDIO := $(wildcard stdio/*.c)

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

ALL_SRCS := $(STRING) $(CTYPE) $(SYSCALL) $(GEN) $(STDLIB) $(STDIO)
ALL_OBJS := $(ALL_SRCS:%.c=%.o)
