CC=gcc
CFLAGS=-g -ansi -pedantic -Werror -Wall -D_XOPEN_SOURCE=500
LDFLAGS=-g

all: ping pong

ping: ping2.c pingpong.h

pong: pong2.c pingpong.h

clean:
	rm -f *.o ping pong
