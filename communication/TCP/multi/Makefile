TARGET1=client.out
TARGET2=server.out

CFLAGS=-ansi -pedantic -Wall -Werror  -g -std=c99
CC=gcc

INC_DIR=../../
CFLAGS+=-I$(INC_DIR)

SOURCES1=client.c CS.c ../../errorHandle.c
SOURCES2=server.c CS.c ../../errorHandle.c

OBJECTS1=$(SOURCES1:.c=.o)
OBJECTS2=$(SOURCES2:.c=.o)

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJECTS1)
	$(CC) $(OBJECTS1) -o $(TARGET1)
$(TARGET2): $(OBJECTS2)
	$(CC) $(OBJECTS2) -o $(TARGET2)

#include depends
#
#depends:
#	$(CC) -MM -I$(INC_DIR) $(SOURCES1) $(SOURCES2) > depends
#
clean:
	-rm -f $(TARGET1) $(TARGET2) *.o #depends
	-rm *.out
	

##INC_DIR=./
##
##
##CFLAGS+=-I$(INC_DIR2);

#all: client.out server.out
#
#client.out: client.c CS.c ../../errorHandle.c ../../errorHandle.h
#server.out: server.c CS.c ../../errorHandle.c ../../errorHandle.h
#
#clean:
#	rm -f *.o client.out server.out
