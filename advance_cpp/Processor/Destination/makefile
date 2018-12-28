# this is my target
TARGET=muTest.out

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03

# Include directory
INC_DIR=../../common
INC_DIR2=./Console
INC_DIR3=./factory
INC_DIR4=./File
INC_DIR5=./Interface

CPPFLAGS += -I$(INC_DIR)    
CPPFLAGS += -I$(INC_DIR2)
CPPFLAGS += -I$(INC_DIR3)
CPPFLAGS += -I$(INC_DIR4)
CPPFLAGS += -I$(INC_DIR5)
# all .c files in this directory are my sources
SOURCES=$(wildcard *.cpp)
SOURCES+= ./Interface/Idest.cpp
SOURCES+= ./Console/Console.cpp 
SOURCES+= ./factory/Dfactory.cpp
SOURCES+= ./File/FileOut.cpp
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR)  $(SOURCES) > depends

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
	
	

