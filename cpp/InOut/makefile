# this is my target
TARGET=main.out

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi

# Include directory
INC_DIR=../../include

CPPFLAGS += -I$(INC_DIR)

# all .c files in this directory are my sources
SOURCES=$(wildcard *.cpp)
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > depends

clean:
	-rm -f $(TARGET) *.o depends file1 file2
	-rm *.out
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
	

