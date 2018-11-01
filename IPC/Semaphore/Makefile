CC=gcc
CFLAGS=-g -ansi -pedantic -Werror -Wall -D_XOPEN_SOURCE=500
LDFLAGS=-g

all: Controller Printer

Controller.o: Controller.c PrintCtl.h

Printer.o: Printer.c PrintCtl.h

clean:
	rm -f *.o Controller Printer
