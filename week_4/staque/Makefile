SHELL=/bin/bash
CC=gcc
CFLAGS=-O2 -g -I.
AR=ar
RCS=rcs
LIBNAME=libstaque.a
OBJFILES=stack.o queue.o
LIBDIR = /usr/local/lib
INCLUDEDIR = /usr/include
INCLUDESUBDIR = $(INCLUDEDIR)/staque
RM = rm -f

# all:
# 	cd static; make
# 	cd shared; make
# install:
# 	cd static; make install
# 	cd shared; make install
# clean:
# 	cd static; make clean
# 	cd shared; make clean

clean:
	-$(RM) $(OBJFILES)

distclean:
	-$(RM) $(OBJFILES) $(LIBNAME)

install: library
	cp $(LIBNAME) $(LIBDIR)
	-mkdir $(INCLUDESUBDIR)
	cp defs.h stack.h queue.h $(INCLUDESUBDIR)

library: $(OBJFILES)
	$(AR) rcs $(LIBNAME) $(OBJFILES)

stack.o: stack.c stack.h defs.h
	$(CC) $(CFLAGS) -c -o $@ stack.c

queue.o: queue.c queue.h defs.h
	$(CC) $(CFLAGS) -c -o $@ queue.c
