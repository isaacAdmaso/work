# this is my target
TARGET1=test1.out
TARGET2=test2.out

.PHONY: run clean gdb 


# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
INC_DIR= ../common


# all .c files in this directory are my sources
SOURCES1=test1.cpp Msgq.cpp 
SOURCES2=test2.cpp Msgq.cpp

# all .o files in this directory are my objects
OBJECTS1 = $(SOURCES1:.cpp=.o)
OBJECTS2 = $(SOURCES2:.cpp=.o)

all:$(TARGET1) $(TARGET2)

$(TARGET1): $(OBJECTS1) 
	$(CC) $(OBJECTS1) -o $(TARGET1) -lrt

$(TARGET2): $(OBJECTS2) 
	$(CC) $(OBJECTS2) -o $(TARGET2) -lrt



clean:
	-rm -f $(TARGET) *.o depends 
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	-rm *.out


gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
	

