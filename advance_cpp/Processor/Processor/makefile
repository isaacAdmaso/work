# this is my target
TARGET=muTest.out
LIBS = PROC

.PHONY: run clean gdb mklib

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03

# Include directory
INC_DIR=../../common
INC_DIR2=./ProcList
INC_DIR3=./factory
LIB_PATH= ../lib

CPPFLAGS += -I$(INC_DIR)    
CPPFLAGS += -I$(INC_DIR2)
CPPFLAGS += -I$(INC_DIR3)
# all .c files in this directory are my sources
SOURCES=   muTest.cpp
LIB_SRC= ./factory/Cfactory.cpp
LIB_SRC+= ./ProcList/ITx.cpp 
LIB_SRC+= ./ProcList/Erase.cpp
LIB_SRC+= ./ProcList/Container.cpp
LIB_SRC+= ./ProcList/Lower.cpp
LIB_SRC+= ./ProcList/Upper.cpp
LIB_SRC+= ./ProcList/Shift.cpp
# all .o files in this directory are my objects
OBJECTS = $(SOURCES:.cpp=.o)
LIB_OBJ = $(LIB_SRC:.cpp=.o)


$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET)  -L$(LIB_PATH) -lPROC   


$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lPROC   -ldl

libPROC.so:
	$(CC) $(CPPFLAGS) -shared $(LIB_SRC) -fPIC -o $(LIB_PATH)/libPROC.so


libPROC.a: $(LIB_OBJ) #let's link library files into a static library
	ar rcs $(LIB_PATH)/libPROC.a $(LIB_OBJ)

# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR2) -I$(INC_DIR3) $(SOURCES) $(LIB_SRC) > depends

libs: mklib libPROC.a libPROC.so
 
mklib:
	mkdir -p $(LIB_PATH)

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
	
	

