# this is my target
TARGET=muTest.out
LIB_PATH= ../lib

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../../../common
INC_DIR2=../../IAgent
INC_DIR3=../../Server/IServer
INC_DIR4=../../EventKey


CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR2) 
CPPFLAGS += -I$(INC_DIR3) 
CPPFLAGS += -I$(INC_DIR4) 

# all .c files in this directory are my sources
SOURCES=muTest.cpp ServerFactory.cpp
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)


$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET)  -ldl


include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR2) -I$(INC_DIR3) $(SOURCES) > depends

libs:
	make -C ../../AgentHandler
	make -C ../../Server


clean:
	-rm *.out *.o
	make -C ../../AgentHandler clean
	make -C ../../Server	clean
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	