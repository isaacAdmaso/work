 
# General compilation flags
CC=gcc
CFLAGS= -ansi -pedantic -Wall -Werror -g
LDFLAGS= -g -pthread
# Include directory
INC_DIR=../../../DS/queue
CFLAGS += -I$(INC_DIR)
# Build Heap
# this is my target
TARGET=PingPong
# all .c files in this directory are my sources
SOURCES=$(wildcard *.c)
SOURCES+=../../../DS/queue/queue.c
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.c=.o)
.PHONY: all clean run
$(TARGET): $(OBJECTS)
# built-in recipe for link
include depends
depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > depends
clean:
	rm $(TARGET) *.o depends
run: $(TARGET)
	./$(TARGET)