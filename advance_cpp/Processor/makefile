TARGET=muTest
LIB_PATH= ./lib
CC=g++

all:$(TARGET)

CPPFLAGS= -I../common -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
CPPFLAGS+= -I./Source/Console
CPPFLAGS+= -I./Source/factory
CPPFLAGS+= -I./Source/File
CPPFLAGS+= -I./Source/Interface
CPPFLAGS+= -I./Processor/ProcList
CPPFLAGS+= -I./Processor/factory
CPPFLAGS+= -I./Destination/Interface
CPPFLAGS+= -I./Destination/Console
CPPFLAGS+= -I./Destination/factory
CPPFLAGS+= -I./Destination/File
CPPFLAGS+= -I./Destination/Container
CPPFLAGS+= -I./App


.PHONY:	 dynamicPROC 
libs: 	 dynamicPROC

dynamicPROC:
	make -C Source libs
	make -C Destination libs
	make -C Processor libs


#$(wildcard *.cpp)
SOURCES=	$(TARGET).cpp ./App/App.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	@echo Compilimg $(TARGET)
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH)  -lSOURCE -lDEST  -lPROC -ldl


include depends

depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET) 
clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	find . -type f -name 'log.txt' -delete
	find . -type f -name 'testFile' -delete
	find . -type f -name 'MainTestFile' -delete
	find . -type f -name 'testFile2' -delete
	find . -type f -name 'testFile3' -delete
	find . -type f -name 'testFile4' -delete
	-rm $(TARGET) 

cleanlib:clean
	-rm $(LIB_PATH)/*.a
	-rm $(LIB_PATH)/*.so
