TARGET=BitSet.out

CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -I../common

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

clean:
	-rm -f $(TARGET) *.o depends 
	-rm *.out

gdb:$(TARGET)
	gdb ./$(TARGET) -q

	
run: $(TARGET)
	./$(TARGET)
