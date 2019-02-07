# this is my target
TARGET=muTest.out

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../../../common
INC_DIR2=../


CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR2) 

# all .c files in this directory are my sources
SOURCES= muTest.cpp 
## all .o files in this directory are my objects
OBJECTS= $(SOURCES:.cpp=.o)


$(TARGET): $(OBJECTS) 
	$(CC)  $(OBJECTS) -o $(TARGET) -ldl
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR2) $(SOURCES) > depends

clean:
	-rm *.o *.out depends
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full --show-leak-kinds=all -v ./$(TARGET)
	