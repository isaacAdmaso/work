# this is my target
TARGET=muTest.out

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../EventKey
INC_DIR2=../../common

CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR2) 

# all .c files in this directory are my sources
SOURCES=$(wildcard *.cpp)
SOURCES+=../EventKey/EventKey.cpp
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR2)  $(SOURCES) > depends

clean:
	-rm -f $(TARGET) *.o $(INC_DIR)/*.o depends 
	-rm *.out
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
	

