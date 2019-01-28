TARGET=BitSet.out

CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 
INC_DIR= ../common

CPPFLAGS+=-I$(INC_DIR)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

include depends
depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > depends
clean:
	-rm -f $(TARGET) *.o depends 
	-rm *.out

gdb:$(TARGET)
	gdb ./$(TARGET) -q

	
run: $(TARGET)
	./$(TARGET)
