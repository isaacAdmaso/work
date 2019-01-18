TARGET=muTest.out
LIB_PATH= ../lib
CC=g++

CPPFLAGS= -I../../common -pedantic -Wall -Werror  -g -ansi -Wconversion -std=c++03
CPPFLAGS+= -I../Source/Console
CPPFLAGS+= -I../Source/factory
CPPFLAGS+= -I../Source/File
CPPFLAGS+= -I../Source/Interface
CPPFLAGS+= -I../Processor/ProcList
CPPFLAGS+= -I../Processor/factory
CPPFLAGS+= -I../Destination/Interface
CPPFLAGS+= -I../Destination/Console
CPPFLAGS+= -I../Destination/factory
CPPFLAGS+= -I../Destination/File
#
#
#
#
#SOURCElib=../Source/Console/ConsoleIn.cpp \
#		../Source/factory/Sfactory.cpp \
# 		../Source/File/FileIn.cpp \
# 		../Source/Interface/Isource.cpp \
#
#PROClib=../Processor/factory/Cfactory.cpp \
#	../Processor/ProcList/ITx.cpp  \
#	../Processor/ProcList/Erase.cpp \
#	../Processor/ProcList/Container.cpp \
#	../Processor/ProcList/Lower.cpp \
#	../Processor/ProcList/Upper.cpp \
#	../Processor/ProcList/Shift.cpp \
#
#DESTlib=../Destination/Interface/Idest.cpp \
# 	../Destination/Console/Console.cpp  \
# 	../Destination/factory/Dfactory.cpp \
# 	../Destination/File/FileOut.cpp \
#
.PHONY:	 dynamicPROC 
libs: 	 dynamicPROC

dynamicPROC:
	make -C ../Source libs
	make -C ../Processor libs
	make -C ../Destination libs


SOURCES= $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH)  -lPROC -lSOURCE -lDEST    -ldl


run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET) 
clean:
	find ../ -type f -name '*.o' -delete
	find ../ -type f -name '*.out' -delete
	find ../ -type f -name 'depends' -delete
	find ../ -type f -name 'log.txt' -delete
	find ../ -type f -name 'testFile' -delete
	find ../ -type f -name 'testFile2' -delete
	find ../ -type f -name 'testFile3' -delete
	find ../ -type f -name 'testFile4' -delete

cleanlib:clean
	rm $(LIB_PATH)/*.a
	rm $(LIB_PATH)/*.so
