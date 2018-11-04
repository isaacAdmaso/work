CC=gcc
CFLAGS=-g -ansi -pedantic -Werror -Wall -D_XOPEN_SOURCE=500
LDFLAGS=-g

all: Ping Pong

Ping.o: Ping.c PingPong.h

Pong.o: Pong.c PingPong.h

clean:
	rm -f *.o Ping Pong
