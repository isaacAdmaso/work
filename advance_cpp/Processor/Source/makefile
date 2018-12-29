# this is my target
TARGET=muTest.out
LIBS = SOURCE

.PHONY: run clean gdb mklib


# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03

# Include directory
INC_DIR=../../common
INC_DIR2=./Console
INC_DIR3=./factory
INC_DIR4=./File
INC_DIR5=./Interface
INC_DIR6=./Socket
LIB_PATH= ../lib

CPPFLAGS += -I$(INC_DIR)    
CPPFLAGS += -I$(INC_DIR2)
CPPFLAGS += -I$(INC_DIR3)
CPPFLAGS += -I$(INC_DIR4)
CPPFLAGS += -I$(INC_DIR5)
CPPFLAGS += -I$(INC_DIR6)
# all .c files in this directory are my sources
SOURCES= 	muTest.cpp#$(wildcard *.cpp)
LIB_SRC= ./Console/ConsoleIn.cpp 
LIB_SRC+= ./factory/Sfactory.cpp
LIB_SRC+= ./File/FileIn.cpp
LIB_SRC+= ./Interface/Isource.cpp
# all .o files in this directory are my objects
OBJECTS = $(SOURCES:.cpp=.o)
LIB_OBJ = $(LIB_SRC:.cpp=.o)


$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET)  -L$(LIB_PATH) -lSOURCE   

libSOURCE.a: $(LIB_OBJ) #let's link library files into a static library
	ar rcs $(LIB_PATH)/libSOURCE.a $(LIB_OBJ)
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR2) -I$(INC_DIR3) -I$(INC_DIR4) -I$(INC_DIR5) -I$(INC_DIR6) $(SOURCES) $(LIB_SRC)> depends

libs: mklib libSOURCE.a

mklib:
	mkdir -p $(LIB_PATH)

clean:
	-rm -f $(TARGET) *.o depends 
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
	
	

