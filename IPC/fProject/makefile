CFLAGS=-I../../include  -ansi -pedantic -Wall -Werror -g
DSSOURCES=../../genericDbLnkLst/list.c \
		../../genericDbLnkLst/list_func.c \
		DataStorage/{bucket.c,ConcurrentHashMap.c} \


LOGSOURCES=../../Zlog/config.c\
		../../Zlog/LogFile.c\
		../../Zlog/Ztime.c\
		../../Zlog/zlog.c \


libs: dynamicDS loggerDS msqDS




mklib:
	mkdir -p $(LIB_PATH)

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	find . -type f -name 'log.txt' -delete

cleanlib:clean
	rm ../lib/*.so
	rm ../lib/*.a
