TARGET=main
READER_LIB_PATH= ../../Processor/lib
CC=g++

all:$(TARGET)

CPPFLAGS= -I../../common -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
CPPFLAGS+= -I../../Processor/Source/Console
CPPFLAGS+= -I../../Processor/Source/factory
CPPFLAGS+= -I../../Processor/Source/File
CPPFLAGS+= -I../../Processor/Source/Interface
CPPFLAGS+= -I../../Processor/Processor/ProcList
CPPFLAGS+= -I../../Processor/Processor/factory
CPPFLAGS+= -I../../Processor/Destination/Interface
CPPFLAGS+= -I../../Processor/Destination/Console
CPPFLAGS+= -I../../Processor/Destination/factory
CPPFLAGS+= -I../../Processor/Destination/File
CPPFLAGS+= -I../../Processor/Destination/Container
CPPFLAGS+= -I../../Processor/App



.PHONY:	 dynamicPROC 
libs: 	 dynamicPROC

dynamicPROC:
	make -C ../../Processor/Source libs
	make -C ../../Processor/Processor libs
	make -C ../../Processor/Destination libs


#$(wildcard *.cpp)
SOURCES=	$(TARGET).cpp  ../../Processor/App/App.cpp SmartHome.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	@echo Compilimg $(TARGET)
	$(CC) $(OBJECTS) -o $(TARGET).out -Wl,-rpath=$(READER_LIB_PATH) -L$(READER_LIB_PATH)  -lPROC -lSOURCE -lDEST  -ldl

include depends

depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

run: $(TARGET)
	./$(TARGET).out

gdb: $(TARGET)
	gdb -q ./$(TARGET) 

clean:
	-rm $(TARGET).out 
	-rm *.o depends 
	make -C ../../Processor clean

cleanlib:clean
	make -C ../../Processor cleanlib
	-rm $(READER_LIB_PATH)/*.so
