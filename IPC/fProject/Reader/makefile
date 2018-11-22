# this is my target
TARGET = Trgger.out
TARGET2 = Reader.out

.PHONY: run clean gdb mklib val

# General compilation flags Concurrent

# The compiler will be gcc("CC" is MAKE variable)
CC = gcc
# The compiler flags will be... ("CFLAGS" is MAKE variable)
CFLAGS = -ansi -pedantic -Wall -Werror -g 
# The debugger flags will be... ("LDFLAGS" is MAKE variable)
LDFLAGS = -g -pthread -D_XOPEN_SOURCE = 500

# Include directory
INC_DIR = ../MsqM
INC_DIR1 = ../
INC_DIR2 = ./lib
CFLAGS += -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2)


# All .c files in this directory are my sources
SOURCES2 = ./lib/CDR.c ./lib/Parser.c Reader.c ../MsqM/MyMsq.c
SOURCES = Trigger.c ../MsqM/MyMsq.c
#LIB_SRC = HashMap.c
# All .o files in this directory are my objects
OBJECTS = $(SOURCES:.c=.o)
OBJECTS2 = $(SOURCES2:.c=.o)
#LIB_OBJ = $(LIB_SRC:.c=.o)

# The default command, compile all the sources
$(TARGET): $(OBJECTS) $(TARGET2)
	$(CC) $(OBJECTS) -o $(TARGET) 

$(TARGET2): $(OBJECTS2) 
	$(CC) $(OBJECTS2) -o $(TARGET2) 

#libADS.a: $(LIB_OBJ) #let's link library files into a static library
#	ar rcs $(LIB_PATH)/libADS.a $(LIB_OBJ)
	
# Built-in recipe for link("include" is MAKE command), include call "depends"

include depends

# Compile the sources, going over the c.files and create new file with list of the h.files that need to be included to each c.file.
# In the next time, if there where no changes in the h.files thet are needed, the depends file will be exist so the include will go to the file instead of build new one. 
depends:
	$(CC) -MM -I$(INC_DIR) -I$(INC_DIR1) -I$(INC_DIR2) $(SOURCES) $(SOURCES2) > depends

#libs: mklib libADS.a

#mklib:
#	mkdir -p $(LIB_PATH)

clean:
	-rm $(TARGET) *.o depends 
	find . -type f -name '*.o' -delete
	find . -type f -name '*.out' -delete
	find . -type f -name 'depends' -delete
	find . -type f -name 'log.txt' -delete
	ipcrm -a
run:  $(TARGET)
	 ./$(TARGET)

gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
	
val: $(TARGET)
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./$(TARGET)
