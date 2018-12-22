CC=gcc
CFLAGS=-ansi -pedantic -Wall -Werror  -g -std=c99

all: client server

client: client.c CS.c
server: server.c CS.c

clean:
	rm -f *.o client server
