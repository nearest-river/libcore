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

prelude: generate

intrinsics.o: prelude $(SRC)/intrinsics.h $(SRC)/intrinsics.c $(SRC)/intrinsics/*
	$(CC) $(CFLAGS) -c $(SRC)/intrinsics.c

num.o: prelude intrinsics.o $(SRC)/types.h $(SRC)/num/*
	$(CC) $(CFLAGS) -c $(SRC)/num/*.c

alloc.o: prelude $(SRC)/alloc.h $(SRC)/alloc/*.h
	echo "empty"

ptr.o: prelude $(SRC)/ptr.c $(SRC)/ptr.h
	$(CC) $(CFLAGS) -c $(SRC)/ptr.c

build: intrinsics.o num.o alloc.o
	mkdir -p $(TARGET)
	$(AR) -rcs $(LIB_NAME).a *.o

b: build



test: build $(TEST_DIR)/*.c
	mkdir -p $(TARGET)/tests
	for f in $(wildcard $(TEST_DIR)/*.c); do \
		filename=$$(basename $$f); \
		name=$${filename%.*}; \
		$(CC) $(CFLAGS) $$f -L. -l$(NAME) -o $(TARGET)/tests/$$name; \
		$(TARGET)/tests/$$name; \
	done


clean:
	rm *.o *.a
	rm -rf $(TARGET)/*











