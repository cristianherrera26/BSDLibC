MAN_PAGES_3 := $(wildcard *.3)

DESTDIR ?=
PREFIX ?= /usr
MANDIR ?= $(PREFIX)/share/man

INSTALL ?= install
LINK ?= ln -s

all:

install: install-man3 install-man3-symlinks

install-man3:
	$(INSTALL) -d $(DESTDIR)$(MANDIR)/man3
	$(INSTALL) -m 644 $(MAN_PAGES_3) $(DESTDIR)$(MANDIR)/man3

install-man3-symlinks: install-man3
	$(LINK) abs.3 $(DESTDIR)$(MANDIR)/man3/labs.3
	$(LINK) abs.3 $(DESTDIR)$(MANDIR)/man3/llabs.3
	$(LINK) strchr.3 $(DESTDIR)$(MANDIR)/man3/strchrnul.3
	$(LINK) strtok.3 $(DESTDIR)$(MANDIR)/man3/strtok_r.3
	$(LINK) strlen.3 $(DESTDIR)$(MANDIR)/man3/strnlen.3
	$(LINK) strcmp.3 $(DESTDIR)$(MANDIR)/man3/strncmp.3
	$(LINK) strlcpy.3 $(DESTDIR)$(MANDIR)/man3/strlcat.3
	$(LINK) strstr.3 $(DESTDIR)$(MANDIR)/man3/strnstr.3
	$(LINK) strcat.3 $(DESTDIR)$(MANDIR)/man3/strncat.3
	$(LINK) strcasecmp.3 $(DESTDIR)$(MANDIR)/man3/strncasecmp.3
	$(LINK) strstr.3 $(DESTDIR)$(MANDIR)/man3/strcasestr.3
	$(LINK) memchr.3 $(DESTDIR)$(MANDIR)/man3/memrchr.3
	$(LINK) memcpy.3 $(DESTDIR)$(MANDIR)/man3/mempcpy.3
	$(LINK) strcpy.3 $(DESTDIR)$(MANDIR)/man3/stpcpy.3
	$(LINK) strncpy.3 $(DESTDIR)$(MANDIR)/man3/stpncpy.3
clean:
