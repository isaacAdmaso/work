TARGET=PingPong
 
.PHONY: all clean run
# General compilation flags
CC=gcc
CFLAGS= -ansi -pedantic -Wall -Werror -g
LDFLAGS= -g -pthread
# Include directory
INC_DIR=../../../DS/queue
CFLAGS += -I$(INC_DIR)
# all .c files in this directory are my sources
SOURCES=$(wildcard *.c)
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.c=.o)
$(TARGET): $(OBJECTS)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > depends

clean:
	rm $(TARGET) *.o depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET) -s 5 -n 99 -v -c3 -p1 -q 5
