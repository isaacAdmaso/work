CC = gcc -ansi -pedantic -Wall -Werror -g -I../../QueryManager -I../../MsqM -I../../Dispatcher/Manager -I../../../../include -I../../DataStorage -I../../Reader/lib -I../../Reader/Reader -I../../Reader/Trigger -I../../Dispatcher/Dispatcher -I../ -pthread -D_XOPEN_SOURCE=500   -Wl,-rpath=../../../../lib -L../../../../lib -lADS -lpthread 
# The compiler flags will be... ("CFLAGS" is MAKE variable)
CFLAGS = -ansi -pedantic -Wall -Werror -g  
# The debugger flags will be... ("LDFLAGS" is MAKE variable)
LDFLAGS = -g -pthread -D_XOPEN_SOURCE = 500 

.PHONY: Insight Insight.o Dispatcher.o Trigger.o QueryManager.o

Insight:CDR.o Parser.o MyMsq.o Sobject.o bucket.o ConcurrentHashMap.o Manager.o Dispatcher.o Trigger.o QueryManager.o ../Insight.c 
	$(CC) ../Insight.c CDR.o Parser.o MyMsq.o Sobject.o bucket.o ConcurrentHashMap.o Manager.o Dispatcher.o Trigger.o QueryManager.o -Wl,-rpath=../../../../lib -L../../../../lib -lADS -lpthread -o $@ 

QueryManager.o:Manager.o ../../QueryManager/query.c	../../QueryManager/query.h
	$(CC) -c ../../QueryManager/query.c  Manager.o -o QueryManager.o

Dispatcher.o:MyMsq.o CDR.o Manager.o  ../../Dispatcher/Dispatcher/Dispatcher.c ../../Dispatcher/Dispatcher/Dispatcher.h
	$(CC) -c ../../Dispatcher/Dispatcher/Dispatcher.c  MyMsq.o CDR.o Manager.o 

Trigger.o:MyMsq.o Reader ../../Reader/Trigger/Trigger.c  ../../Reader/Trigger/Trigger.h 
	$(CC) -c ../../Reader/Trigger/Trigger.c MyMsq.o 

Reader:MyMsq.o Parser.o CDR.o ../../Reader/Reader/Reader.c ../../Reader/Reader/Reader.h  
	$(CC)  ../../Reader/Reader/Reader.c CDR.o MyMsq.o Parser.o -o $@ 

Manager.o:CDR.o Sobject.o ConcurrentHashMap.o ../../Dispatcher/Manager/Manager.c ../../Dispatcher/Manager/Manager.h
	$(CC) -c ../../Dispatcher/Manager/Manager.c CDR.o Sobject.o ConcurrentHashMap.o 

ConcurrentHashMap.o:bucket.o ../../DataStorage/ConcurrentHashMap.c ../../DataStorage/HashMapC.h
	$(CC) -c  bucket.o ../../DataStorage/ConcurrentHashMap.c

bucket.o: ../../DataStorage/bucket.c ../../DataStorage/bucket.h ../../../../include/list_functions.h ../../../../include/list_itr.h  ../../../../include/list.h
	$(CC) -c  ../../DataStorage/bucket.c

Sobject.o:../../Dispatcher/Manager/Sobject.c ../../Dispatcher/Manager/Sobject.h
	$(CC) -c ../../Dispatcher/Manager/Sobject.c

MyMsq.o:../../MsqM/MyMsq.c ../../MsqM/MyMsq.h
	$(CC) -c ../../MsqM/MyMsq.c

Parser.o:../../Reader/lib/Parser.c ../../Reader/lib/Parser.h
	$(CC) -c ../../Reader/lib/Parser.c

CDR.o:../../Reader/lib/CDR.c ../../Reader/lib/CDR.h
	$(CC) -c ../../Reader/lib/CDR.c
include depends

# Compile the sources, going over the c.files and create new file with list of the h.files that need to be included to each c.file.
# In the next time, if there where no changes in the h.files thet are needed, the depends file will be exist so the include will go to the file instead of build new one. 
depends:
	$(CC) -MM ../Insight.c CDR.o Parser.o MyMsq.o Sobject.o bucket.o ConcurrentHashMap.o Manager.o Dispatcher.o Trigger.o -Wl,-rpath=../../../../lib -L../../../../lib -lADS -lpthread -o $@   > depends


clean:
	rm *.o
	rm Insight
	rm depends
	rm logQ.txt
	rm Reader
	rm *.out

run:  Insight
	 ./Insight

gdb:  Insight
	 gdb -q ./Insight
	
val: Insight
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./Insight

#LIB_PATH = ../../../lib
#
#
#Insight:Insight.o Dispatcher.o Trigger.o 
#	$(CC) -o Insight Trigger.o Dispatcher.o Insight.o
#
#Insight.o:Insight.c ../Reader/Trigger/Trigger.h ../Dispatcher/Dispatcher/Dispatcher.h 
#	$(CC) -c Insight.c 
#
#
#Dispatcher.o:$(OBJECTS) 
#	$(CC) -c $(OBJECTS) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lADS -lpthread
#
#Trigger.o: $(OBJECTST) 
#	$(CC) -c  $(OBJECTST) 
#
#Reader.out: $(OBJECTST2) 
#	$(CC) $(OBJECTST2) -o Reader.out
#
#INC_DIR  = ../Reader/lib
#INC_DIR1 = ../MsqM
#INC_DIR2 = ../../../include
#INC_DIR3 = ../DataStorage
#INC_DIR4 = ../Dispatcher/Manager
#INC_DIR5 = ../Dispatcher/Dispatcher
#CFLAGS += -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2)
#CFLAGS += -I$(INC_DIR3) -I$(INC_DIR4)
#CFLAGS += -I$(INC_DIR5)
#
#
## All .c files in this directory are my sources
#SOURCES  = ../Reader/lib/CDR.c 	../MsqM/MyMsq.c
#SOURCES += ../DataStorage/bucket.c 	../DataStorage/ConcurrentHashMap.c
#SOURCES += ../Dispatcher/Manager/Manager.c  	../Dispatcher/Manager/Sobject.c  ../Dispatcher/Dispatcher/Dispatcher.c 
#
#OBJECTS = $(SOURCES:.c=.o)
#
#
#INC_DIRT = ../MsqM
#INC_DIRT1 = ../Reader/Reader
#INC_DIRT2 = ../Reader/lib
#INC_DIRT3 = ../Reader/Trigger
#CFLAGS += -I$(INC_DIRT) -I$(INC_DIRT1) -I$(INC_DIRT2) -I$(INC_DIRT3)
#
#
## All .c files in this directory are my sources
#SOURCEST2 = ../Reader/lib/CDR.c ../Reader/lib/Parser.c ../Reader/Reader/Reader.c ../MsqM/MyMsq.c
#SOURCEST = ../Reader/Trigger/Trigger.c ../MsqM/MyMsq.c
##LIB_SRC = HashMap.c
## All .o files in this directory are my objects
#OBJECTST = $(SOURCEST:.c=.o)
#OBJECTST2 = $(SOURCEST2:.c=.o)
##LIB_OBJ = $(LIB_SRC:.c=.o)
#
#