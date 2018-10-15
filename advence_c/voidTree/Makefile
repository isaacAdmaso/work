# this is my target
TARGET=tree.out
LIBS = ADS

.PHONY: run clean gdb libs
# General compilation flags
CC=gcc
CFLAGS= -ansi -pedantic -Wall -Werror  -g -c -fPIC
LDFLAGS= -g

# Include directory
INC_DIR=../../include
LIB_PATH= ../../lib
CFLAGS += -I$(INC_DIR)


# all .c files in this directory are my sources
SOURCES=$(wildcard *.c)

# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > depends

clean:
	-rm -f $(TARGET) *.o depends
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
	

