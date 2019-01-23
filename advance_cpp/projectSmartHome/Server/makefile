# this is my target
TARGET=muTest.out
LIB_PATH= ../lib

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../../common
INC_DIR2=../IAgent
INC_DIR3=./IServer
INC_DIR4=../AgentHandler/AgentDispatcher
INC_DIR5=../EventKey
INC_DIR6=../AgentHandler/HandlerS
INC_DIR7=../AgentHandler/HandlerC
INC_DIR8=../Factory/AgentFactory
INC_DIR9=./MyServer

CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR2) 
CPPFLAGS += -I$(INC_DIR3) 
CPPFLAGS += -I$(INC_DIR4) 
CPPFLAGS += -I$(INC_DIR5) 
CPPFLAGS += -I$(INC_DIR6) 
CPPFLAGS += -I$(INC_DIR7) 
CPPFLAGS += -I$(INC_DIR8) 
CPPFLAGS += -I$(INC_DIR9) 

# all .c files in this directory are my sources
SOURCES=muTest.cpp
LibSOURCES=$(INC_DIR9)/MyServer.cpp
LibSOURCES+=$(INC_DIR3)/IServer.cpp
LibSOURCES+=$(INC_DIR2)/IAgent.cpp
LibSOURCES+=$(INC_DIR4)/AgentHandler.cpp
LibSOURCES+=$(INC_DIR5)/EventKey.cpp
LibSOURCES+=$(INC_DIR6)/SensorHandler.cpp
LibSOURCES+=$(INC_DIR7)/ControllerHandler.cpp
LibSOURCES+=$(INC_DIR8)/AgentFactory.cpp

# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lSERVER -lAGENTMANAGER   -ldl


include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2) -I$(INC_DIR3) -I$(INC_DIR4) -I$(INC_DIR5) $(SOURCES) > depends

libs: mklib 
	$(CC) $(CPPFLAGS) -shared $(LibSOURCES) -ldl -fPIC -o $(LIB_PATH)/libSERVER.so
	make -C ../AgentHandler

mklib:
	mkdir -p $(LIB_PATH)

clean:
	find ../ -type f -name '*.o' -delete
	find ../ -type f -name '*.out' -delete
	find ../ -type f -name 'depends' -delete
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	