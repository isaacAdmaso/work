LIB_PATH= ../lib
CC=g++


CPPFLAGS= -I../../common -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
CPPFLAGS+= -I./HandlerC
CPPFLAGS+= -I./HandlerS
CPPFLAGS+= -I./AgentDispatcher
CPPFLAGS+= -I../EventKey
CPPFLAGS+= -I../Factory/AgentFactory
CPPFLAGS+= -I../IAgent
CPPFLAGS+= -I../Server/IServer
all:libs


SOURCES=./HandlerC/ControllerHandler.cpp 
SOURCES+=./HandlerS/SensorHandler.cpp
SOURCES+=./AgentDispatcher/AgentHandler.cpp
SOURCES+=../EventKey/EventKey.cpp
SOURCES+=../Factory/AgentFactory/AgentFactory.cpp
SOURCES+=../IAgent/IAgent.cpp
SOURCES+=../Server/IServer/IServer.cpp
OBJECTS = $(SOURCES:.cpp=.o)

include depends

depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

libs:mklib
	$(CC) $(CPPFLAGS) -shared $(SOURCES) -fPIC -o $(LIB_PATH)/libAGENTMANAGER.so

mklib:
	mkdir -p $(LIB_PATH)

clean:
	-rm *.o depends
	
cleanlib:clean
	-rm ../lib/libAGENTMANAGER.so
