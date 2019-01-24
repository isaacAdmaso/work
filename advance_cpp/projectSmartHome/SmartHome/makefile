TARGET=main
LIB_PATH= ../lib
READER_LIB_PATH= ../../Processor/lib
AGENTMANAGER_PATH=../AgentHandler
READER_PATH=../Configuration
CC=g++

all:$(TARGET)

CPPFLAGS= -I../../common -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
CPPFLAGS+= -I../Configuration
CPPFLAGS+= -I../IAgent
CPPFLAGS+= -I../Server/IServer
CPPFLAGS+= -I../EventKey
CPPFLAGS+= -I../AgentHandler/AgentDispatcher
CPPFLAGS+= -I../AgentHandler/HandlerC
CPPFLAGS+= -I../AgentHandler/HandlerS
CPPFLAGS+= -I../Factory/ServerFactory
CPPFLAGS+= -I../MSGQ





.PHONY:	 dynamicReader dynamicAGENTMANAGER

dynamicReader:
	make -C $(READER_PATH) libs

dynamicAGENTMANAGER:
	make -C $(AGENTMANAGER_PATH) libs
	make -C ../Factory/AgentFactory libs
	make -C ../Server 

libs: dynamicReader dynamicAGENTMANAGER

SOURCES=	$(TARGET).cpp SmartHome.cpp ../Factory/ServerFactory/ServerFactory.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	@echo Compilimg $(TARGET)
	$(CC) $(OBJECTS) -o $(TARGET).out -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH)  -lREADER -lAGENTMANAGER -Wl,-rpath=$(READER_LIB_PATH) -L$(READER_LIB_PATH)  -lPROC -lSOURCE -lDEST  -ldl
	

include depends

depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

run: $(TARGET)
	./$(TARGET).out

gdb: $(TARGET)
	gdb -q ./$(TARGET).out

val: $(TARGET)
	valgrind -q --leak-check=full --show-leak-kinds=all -v ./$(TARGET).out
	
clean:
	-rm *.o depends 
	-rm $(TARGET).out 

cleanlib:clean
	make -C ../../Processor clean
	make -C ../Sensors clean
	make -C ../../Processor cleanlib
	make -C $(READER_PATH) cleanlib
	make -C $(AGENTMANAGER_PATH) cleanlib
	make -C ../Factory/AgentFactory clean 
	make -C ../Server clean
	-rm $(LIB_PATH)/*.so
	-rm $(READER_LIB_PATH)/*.so
