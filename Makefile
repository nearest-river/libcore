NAME=core
LIB_NAME=lib$(NAME)

SRC=src
TARGET=target
TEST_DIR=tests
MACRO_SCRIPTS=macro_scripts


CC=gcc
AR=ar
CFLAGS=-Wall -g





all: build


macro_scripts_uint: $(MACRO_SCRIPTS)/*
	echo "TODO"

generate: macro_scripts_uint
	echo "generated macros..."


num.o: generate $(SRC)/types.h $(SRC)/num/*
	$(CC) $(CFLAGS) -c $(SRC)/num/*.c

alloc.o: generate $(SRC)/alloc.h $(SRC)/alloc/*.h
	echo "empty"

build: num.o alloc.o
	mkdir -p $(TARGET)
	$(AR) rcs $(LIB_NAME).a *.o

test: build
	$(CC) $(CFLAGS) $(TEST_DIR)/*.c -L$(NAME) -o $(TARGET)/tests
	$(TARGET)/tests

clean:
	rm *.o *.a
	rm $(TARGET)/*















