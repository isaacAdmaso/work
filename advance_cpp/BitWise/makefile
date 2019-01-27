TARGET=BitSet.out

CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

clean:
	-rm -f $(TARGET) *.o depends 
	-rm *.out

	
run: $(TARGET)
	./$(TARGET)
