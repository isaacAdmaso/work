# this is my target
TARGET=muTest.out
LIB_PATH= ../lib

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../../common
INC_DIR1=../EventKey
INC_DIR2=../Event
INC_DIR3=../IAgent
INC_DIR4=../Server/IServer
INC_DIR5=./HVAC
INC_DIR6=./Sprinkler


CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR1) 
CPPFLAGS += -I$(INC_DIR2) 
CPPFLAGS += -I$(INC_DIR3) 
CPPFLAGS += -I$(INC_DIR4) 
CPPFLAGS += -I$(INC_DIR5) 
CPPFLAGS += -I$(INC_DIR6) 

# all .c files in this directory are my sources
SOURCES=muTest.cpp
#libSOURCES+=../IServer/IServer.cpp
#libSOURCES+=../EventKey/EventKey.cpp
#libSOURCES+=../Event/Event.cpp
#libSOURCES+=../IAgent/IAgent.cpp
#libSOURCESFire=$(libSOURCES)
#libSOURCESFire+=./SmokeSensore/FireSensor.cpp
#libSOURCESTemp=$(libSOURCES)
#libSOURCESTemp+=./TempSensore/TempSensor.cpp
## all .o files in this directory are my objects
OBJECTS= $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lSPRINKLER -lHVAC   -ldl
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2) -I$(INC_DIR3) -I$(INC_DIR4) -I$(INC_DIR5) -I$(INC_DIR6) $(SOURCES) > depends

libs:
	make -C HVAC
	make -C Sprinkler

#libs: mklib 
#	$(CC) $(CPPFLAGS) -shared $(libSOURCESTemp) -fPIC -o $(LIB_PATH)/libTEMP.so
#	$(CC) $(CPPFLAGS) -shared $(libSOURCESFire) -fPIC -o $(LIB_PATH)/libSMOKE.so


#mklib:
#	mkdir -p $(LIB_PATH)

clean:
	make -C HVAC clean
	make -C Sprinkler clean
	rm *.o *.out depends
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	