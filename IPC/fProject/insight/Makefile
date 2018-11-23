CC = gcc
# The compiler flags will be... ("CFLAGS" is MAKE variable)
CFLAGS = -ansi -pedantic -Wall -Werror -g 
# The debugger flags will be... ("LDFLAGS" is MAKE variable)
LDFLAGS = -g -pthread -D_XOPEN_SOURCE = 500

LIB_PATH = ../../../lib

Insight:Insight.o Trigger.o Dispatcher.o
	$(CC) -o Insight Trigger.o Dispatcher.o Insight.o

Insight.o:Insight.c ../Reader/Trigger/Trigger.h ../Dispatcher/Dispatcher/Dispatcher.h 
	$(CC) -c Insight.c 

Trigger.o: MyMsq.o ../Reader/Trigger/Trigger.c ../MsqM/MyMsq.h ../Reader/Trigger/Trigger.h ../MsqM/MyMsq.h
	$(CC) -c ../Reader/Trigger/Trigger.c MyMsq.o

MyMsq.o: ../MsqM/MyMsq.c ../MsqM/MyMsq.h
	$(CC) -c ../MsqM/MyMsq.c



INC_DIR  = ../Reader/lib
INC_DIR1 = ../MsqM
INC_DIR2 = ../../../include
INC_DIR3 = ../DataStorage
INC_DIR4 = ../Dispatcher/Manager
INC_DIR5 = ../Dispatcher/Dispatcher
CFLAGS += -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2)
CFLAGS += -I$(INC_DIR3) -I$(INC_DIR4)
CFLAGS += -I$(INC_DIR5)


# All .c files in this directory are my sources
SOURCES  = ../Reader/lib/CDR.c 	../MsqM/MyMsq.c
SOURCES += ../DataStorage/bucket.c 	../DataStorage/ConcurrentHashMap.c
SOURCES += ../Dispatcher/Manager/Manager.c  	../Dispatcher/Manager/Sobject.c  ../Dispatcher/Dispatcher/Dispatcher.c 

OBJECTS = $(SOURCES:.c=.o)


Dispatcher.o:$(OBJECTS) 
	$(CC) -c $(OBJECTS) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lADS -lpthread

