# this is my target
TARGET=muTest.out

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03

# Include directory
INC_DIR=../../common
INC_DIR2=./ProcList
INC_DIR3=./factory

CPPFLAGS += -I$(INC_DIR)    
CPPFLAGS += -I$(INC_DIR2)
CPPFLAGS += -I$(INC_DIR3)
# all .c files in this directory are my sources
SOURCES=   muTest.cpp
SOURCES+= ./factory/Cfactory.cpp
SOURCES+= ./ProcList/ITx.cpp 
SOURCES+= ./ProcList/Erase.cpp
SOURCES+= ./ProcList/Container.cpp
SOURCES+= ./ProcList/Lower.cpp
SOURCES+= ./ProcList/Upper.cpp
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR2) -I$(INC_DIR3)   $(SOURCES) > depends

clean:
	-rm -f $(TARGET) *.o depends testFile
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	-rm *.out
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
	

