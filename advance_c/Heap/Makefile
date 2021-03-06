# this is my target
TARGET = HeapTestMU.out
LIBS = ADS

.PHONY: run clean gdb val mklib

# General compilation flags

# The compiler will be gcc("CC" is MAKE variable)
CC = gcc
# The compiler flags will be... ("CFLAGS" is MAKE variable)
CFLAGS = -ansi -pedantic -Wall -Werror -g
# The debugger flags will be... ("LDFLAGS" is MAKE variable)
LDFLAGS = -g

# Include directory
INC_DIR = ../../include
LIB_PATH= ../../lib
CFLAGS += -I$(INC_DIR)


# All .c files in this directory are my sources
SOURCES = HeapTestMU.c
LIB_SRC = Heap.c
# All .o files in this directory are my objects
OBJECTS = $(SOURCES:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)

# The default command, compile all the sources
$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -Wl,-rpath=$(LIB_PATH) -L$(LIB_PATH) -lADS 

libADS.a: $(LIB_OBJ) #let's link library files into a static library
	ar rcs $(LIB_PATH)/libADS.a $(LIB_OBJ)
	
# Built-in recipe for link("include" is MAKE command), include call "depends"

include depends

# Compile the sources, going over the c.files and create new file with list of the h.files that need to be included to each c.file.
# In the next time, if there where no changes in the h.files thet are needed, the depends file will be exist so the include will go to the file instead of build new one. 
depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

libs: mklib libADS.a

mklib:
	mkdir -p $(LIB_PATH)

clean:
	-rm $(TARGET) *.o depends

run:  $(TARGET)
	 ./$(TARGET)

gdb:  $(TARGET)
	 gdb -q ./$(TARGET)

val: $(TARGET)
	valgrind -q --leak-check=full -v ./$(TARGET)
	
