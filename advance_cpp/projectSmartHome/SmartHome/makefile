TARGET=main
LIB_PATH= ../../Processor/lib
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
	$(CC) $(OBJECTS) -o $(TARGET).out -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH)  -lPROC -lSOURCE -lDEST  -ldl

include depends

depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

run: $(TARGET)
	./$(TARGET).out

gdb: $(TARGET)
	gdb -q ./$(TARGET) 

clean:
	rm $(TARGET).out 
	find ../../Processor  -type f -name '*.o' -delete
	find ../../Processor  -type f -name '*.out' -delete
	find ../../Processor  -type f -name 'depends' -delete
	find ../../Processor  -type f -name 'log.txt' -delete
	find ../../Processor  -type f -name 'testFile' -delete
	find ../../Processor  -type f -name 'MainTestFile' -delete
	find ../../Processor  -type f -name 'testFile2' -delete
	find ../../Processor  -type f -name 'testFile3' -delete
	find ../../Processor  -type f -name 'testFile4' -delete
	rm *.o depends 

cleanlib:clean
	rm $(LIB_PATH)/*.so
