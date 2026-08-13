-include shlib_version

LIBNAME=c
SO_NAME=$(major).$(minor)
SO_SUFFIX=.so

LIB := lib$(LIBNAME)$(SO_SUFFIX).$(SO_NAME)
LIB_SYMLINKS=lib$(LIBNAME)$(SO_SUFFIX) lib$(LIBNAME)$(SO_SUFFIX).$(major)

MACHINE_HOST := $(shell uname -m)
MACHINE ?= $(MACHINE_HOST)

ifeq ($(MACHINE), x86_64)
MACHINE=amd64
endif

CFLAGS=-nostdlib -nostdinc -ffreestanding -fno-stack-protector -I$(CURDIR)/include -I$(CURDIR)/arch/$(MACHINE) -I$(CURDIR)/arch/$(MACHINE)/machine
LDFLAGS=-nostdlib -ffreestanding -fno-stack-protector -Wl,-soname,lib$(LIBNAME)$(SO_SUFFIX).$(major)

STRING_SRCS := $(wildcard string/*.c)
CTYPE_SRCS := $(wildcard ctype/*.c)
SYSCALL_SRCS := $(wildcard syscall/*.c)
GEN_SRCS := $(wildcard gen/*.c)
STDLIB_SRCS := $(wildcard stdlib/*.c)

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

ALL_SRCS := $(STRING_SRCS) $(CTYPE_SRCS) $(SYSCALL_SRCS) $(GEN_SRCS) $(STDLIB_SRCS)
ALL_OBJS := $(ALL_SRCS:%.c=%.o)

all: $(ALL_OBJS) $(LIB) $(LIB_SYMLINKS)

$(LIB): $(ALL_OBJS)
	$(CC) -shared -o $@ $(LDFLAGS) $(ALL_OBJS)
$(LIB_SYMLINKS): $(LIB)
	ln -sv $< $@
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
clean:
	rm -rf $(ALL_OBJS) $(LIB) $(LIB_SYMLINKS)
