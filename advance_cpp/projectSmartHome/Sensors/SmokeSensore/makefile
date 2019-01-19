# this is my target
TARGET=muTest.out
LIB_PATH= ../../lib

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../../../common
INC_DIR1=../../EventKey
INC_DIR2=../../Event
INC_DIR3=../../IAgent
INC_DIR4=../../Server/IServer


CPPFLAGS += -I$(INC_DIR4) 
CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR1) 
CPPFLAGS += -I$(INC_DIR2) 
CPPFLAGS += -I$(INC_DIR3) 

# all .c files in this directory are my sources
SOURCES=muTest.cpp
LibSOURCES=../../Server/IServer/IServer.cpp
LibSOURCES+=../../EventKey/EventKey.cpp
LibSOURCES+=../../Event/Event.cpp
LibSOURCES+=../../IAgent/IAgent.cpp
LibSOURCES+=./FireSensor.cpp
# all .o files in this directory are my objects
OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lSMOKE   -ldl


include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2) -I$(INC_DIR3) -I$(INC_DIR4)  $(SOURCES) > depends

libs: mklib 
	$(CC) $(CPPFLAGS) -shared $(LibSOURCES) -fPIC -o $(LIB_PATH)/libSMOKE.so

mklib:
	mkdir -p $(LIB_PATH)

clean:
	-rm -f $(TARGET) *.o $(INC_DIR1)/*.o $(INC_DIR2)/*.o $(INC_DIR3)/*.o $(INC_DIR4)/*.o depends 
	-rm *.out
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	