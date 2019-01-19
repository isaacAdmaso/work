# this is my target
TARGET=muTest.out

# General compilation flags
CC=g++
CPPFLAGS= -pedantic -Wall -Werror  -g -ansi -Wconversion 

# Include directory
INC_DIR=../../../common
INC_DIR1=../../IAgent
INC_DIR2=../../Server/IServer
INC_DIR3=../../EventKey


CPPFLAGS += -I$(INC_DIR) 
CPPFLAGS += -I$(INC_DIR1) 
CPPFLAGS += -I$(INC_DIR2) 
CPPFLAGS += -I$(INC_DIR3) 

# all .c files in this directory are my sources
SOURCES= muTest.cpp AgentFactory.cpp
## all .o files in this directory are my objects
OBJECTS= $(SOURCES:.cpp=.o)


$(TARGET): $(OBJECTS) libs
	$(CC)  $(OBJECTS) -o $(TARGET) -ldl
# built-in recipe for link

include depends

depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2) -I$(INC_DIR3) $(SOURCES) > depends

libs:
	make -C	../../Sensors/SmokeSensore
	make -C	../../Sensors/TempSensore
	make -C ../../Controlers/Sprinkler
	make -C ../../Controlers/HVAC

clean:
	make -C ../../Controlers/HVAC	clean
	make -C ../../Controlers/Sprinkler	clean
	make -C	../../Sensors/SmokeSensore	clean
	make -C	../../Sensors/TempSensore	clean
	-rm *.o *.out depends
	
run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	