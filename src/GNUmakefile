-include shlib_version

LIBNAME=c
SO_NAME=$(major).$(minor)
SO_SUFFIX=.so

LIB_DYNAMIC := lib$(LIBNAME)$(SO_SUFFIX).$(SO_NAME)
LIB_STATIC := lib$(LIBNAME).a
LIB_SYMLINKS=lib$(LIBNAME)$(SO_SUFFIX) lib$(LIBNAME)$(SO_SUFFIX).$(major)

MACHINE_HOST := $(shell uname -m)
MACHINE ?= $(MACHINE_HOST)

ifeq ($(MACHINE),x86_64)
MACHINE := amd64
endif

DESTDIR ?=
PREFIX ?= /usr
LIBDIR ?= $(PREFIX)/lib
INCDIR ?= $(PREFIX)/include

CFLAGS=-nostdlib -nostdinc -ffreestanding -fno-stack-protector -I$(CURDIR)/include -I$(CURDIR)/arch/$(MACHINE) -I$(CURDIR)/arch/$(MACHINE)/machine
CFLAGS+= -fPIC
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

all: $(ALL_OBJS) $(LIB_DYNAMIC) $(LIB_STATIC)

$(LIB_DYNAMIC): $(ALL_OBJS)
	$(CC) -shared -o $@ $(LDFLAGS) $(ALL_OBJS)
$(LIB_STATIC): $(ALL_OBJS)
	$(AR) rcs -o $@ $(ALL_OBJS)
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

install: $(LIB_DYNAMIC) $(LIB_STATIC) install-includes install-libs $(LIB_SYMLINKS)

install-libs:
	install -d $(DESTDIR)$(LIBDIR)
	install -m 755 $(LIB_DYNAMIC) $(DESTDIR)$(LIBDIR)
	install -m 644 $(LIB_STATIC) $(DESTDIR)$(LIBDIR)
$(LIB_SYMLINKS): install-libs
	ln -sf $(LIB_DYNAMIC) $(DESTDIR)$(LIBDIR)/$@

install-includes:
	install -d $(DESTDIR)$(INCDIR)
	install -m 644 $(GENERAL_INCLUDES) $(DESTDIR)$(INCDIR)

	install -d $(DESTDIR)$(INCDIR)/sys
	install -m 644 $(SYSTEM_INCLUDES) $(DESTDIR)$(INCDIR)/sys

	install -d $(DESTDIR)$(INCDIR)/$(MACHINE)
	install -m 644 $(MACHINE_INCLUDES) $(DESTDIR)$(INCDIR)/$(MACHINE)
	ln -sf $(MACHINE) $(DESTDIR)$(INCDIR)/machine
clean:
	rm -rf $(ALL_OBJS) $(LIB_DYNAMIC) $(LIB_STATIC) $(LIB_SYMLINKS)
.PHONY:
