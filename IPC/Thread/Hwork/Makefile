CC=gcc
CFLAGS=-g -ansi -pedantic -Werror -Wall -D_XOPEN_SOURCE=500 -pthread
LDFLAGS=-g

all: PingPong

PingRf.o: PingRf.c PingPongRf.h

PongRf.o: PongRf.c PingPongRf.h

clean:
	rm -f *.o PingRf PongRf
