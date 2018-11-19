CFLAGS=-ansi -pedantic -Wall -Werror -g
DSSOURCES=Reader/lib/{CDR.c,Parser.c}


.PHONY:dynamicDS



libs: dynamicDS 
dynamicDS: dynamicDS.so
dynamicDS.so:
	gcc $(CFLAGS) -shared $(DSSOURCES) -fPIC -o dynamicDS.so






clean:
	rm ../lib/*.so log.txt
