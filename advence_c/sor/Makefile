# this is my target
TARGET=sortG.out

# General compilation flags
CC=gcc
CFLAGS= -ansi -pedantic -Wall -Werror  -g 
LDFLAGS= -g

# Include directory
INC_DIR=../include

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

valgrind: $(TARGET)
	valgrind./$(TARGET)
	
	

