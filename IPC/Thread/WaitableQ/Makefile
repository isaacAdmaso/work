TARGET=PingPong
 
.PHONY: all clean run
# General compilation flags
CC=gcc
CFLAGS= -ansi -pedantic -Wall -Werror -g
LDFLAGS= -g -pthread

SOURCES=$(wildcard *.c)
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.c=.o)
$(TARGET): $(OBJECTS)
# built-in recipe for link

include depends

depends:
	$(CC) -MM  $(SOURCES) > depends

clean:
	rm $(TARGET) *.o depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET) 
