MAKE=make

debug: CFLAGS = -g -Werror -O0 -Wno-format
debug: all

turbo: CFLAGS=-g -Wall -Werror -O3 -Wuninitialized -Wno-format
turbo: all

export CFLAGS

all: allobjs allbinaries

allbinaries:
	$(MAKE) -C source allbinaries

allobjs:
	$(MAKE) -C source allobjs

clean:
	$(MAKE) -C source clean

depend:
	$(MAKE) -C source depend


tests:
	$(MAKE) -C source tests
