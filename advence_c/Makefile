CFLAGS=-I../include
libs:
	make -C Vector libs
	make -C Heap libs
	make -C Scheduler libs
	make -C genericDbLnkLst libs
	make -C HashMap libs
	make -C queue libs
	make -C Zlog libs
	gcc $(CFLAGS) -g -pedantic -Werror -Wall -ansi -shared -fPIC  genericDbLnkLst/list.c genericDbLnkLst/list_func.c HashMap/HashMap.c Vector/Vector.c queue/queue.c Heap/Heap.c Zlog/config.c Zlog/LogFile.c Zlog/Ztime.c Zlog/zlog.c Scheduler/scheduler.c Scheduler/task.c Scheduler/timeScd.c  -o ../lib/libADS.so

