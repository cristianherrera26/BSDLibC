ifeq ($(MACHINE), )
MACHINE := $(shell uname -m)
ifeq ($(MACHINE), x86_64)
MACHINE := amd64
endif
endif

ifeq ($(MACHINE), amd64)
SRCS=$(MACHINE)/_start.S $(MACHINE)/crt0.c
OBJS=$(MACHINE)/_start.o $(MACHINE)/crt0.o
else
SRCS=generic/crt0.c
OBJS=generic/crt0.o
endif

-include ../../config.mk

CFLAGS+=-ffreestanding -nostdlib -nostdinc
CFLAGS+=-I../include -I../arch/$(MACHINE)

all: $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
clean:
	rm -rf $(OBJS)
