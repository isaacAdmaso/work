CFLAGS=-I../include  -ansi -pedantic -Wall -Werror -g
DSSOURCES=genericDbLnkLst/list.c \
		genericDbLnkLst/list_func.c \
		HashMap/HashMap.c \
		Vector/Vector.c \
		Heap/Heap.c \
		

SCHSOURCES=Scheduler/scheduler.c\
		Scheduler/task.c\
		Scheduler/timeScd.c\
		
LOGSOURCES=Zlog/config.c\
		Zlog/LogFile.c\
		Zlog/Ztime.c\
		Zlog/zlog.c \
		
.PHONY: staticDS dynamicDS loggerDS schedulerDS clean

libs: 	staticDS dynamicDS loggerDS schedulerDS

staticDS:
	make -C Vector libs
	make -C Heap libs
	make -C Scheduler libs
	make -C genericDbLnkLst libs
	make -C HashMap libs
	make -C queue libs
	make -C Zlog libs
dynamicDS: ../lib/libADS.so
../lib/libADS.so:
	gcc $(CFLAGS) -shared $(DSSOURCES) -fPIC -o ../lib/libADS.so

loggerDS: ../lib/libLOGGER.so
../lib/libLOGGER.so:
	gcc $(CFLAGS) -shared $(LOGSOURCES) -fPIC -o ../lib/libLOGGER.so
	
schedulerDS: ../lib/libSCH.so
../lib/libSCH.so:
	gcc $(CFLAGS) -shared $(SCHSOURCES) -fPIC -o ../lib/libSCH.so

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	find . -type f -name 'log.txt' -delete

cleanlib:clean
	rm ../lib/*.so
	rm ../lib/*.a
