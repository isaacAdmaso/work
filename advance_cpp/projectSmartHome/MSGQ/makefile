# this is my target
TARGET=muTest.out
LIBS = MSGQ

.PHONY: run clean gdb mklib


# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
INC_DIR= ../common

LIB_PATH= ../lib

# all .c files in this directory are my sources
SOURCES= 	muTest.cpp#$(wildcard *.cpp)
LIB_SRC= ./Msgq.cpp 

# all .o files in this directory are my objects
OBJECTS = $(SOURCES:.cpp=.o)
LIB_OBJ = $(LIB_SRC:.cpp=.o)


$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET)  -L$(LIB_PATH) -l$(LIBS)   

libMSGQ.a: $(LIB_OBJ) #let's link library files into a static library
	ar rcs $(LIB_PATH)/libMSGQ.a $(LIB_OBJ)
# built-in recipe for link

include depends

depends:
	$(CC) -MM $(SOURCES) $(LIB_SRC)> depends

libs: mklib lib$(LIBS).a

mklib:
	mkdir -p $(LIB_PATH)

clean:
	-rm -f $(TARGET) *.o depends 
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	-rm *.out

cleanlib:clean
	rm $(LIB_PATH)/*.a

	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
	

