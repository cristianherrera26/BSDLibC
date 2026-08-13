SUBDIR=	src man

all: $(SUBDIR)

$(SUBDIR):
	$(MAKE) -C $@ all
install:
	$(MAKE) -C src install
	$(MAKE) -C man install
clean:
	$(MAKE) -C src clean
	$(MAKE) -C man clean
.PHONY: all $(SUBDIR)
