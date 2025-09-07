NAME=core
LIB_NAME=lib$(NAME)

SRC=src
TARGET=target
TEST_DIR=tests


CC=gcc
AR=ar
CFLAGS=-Wall -g





all: build

primitives.o: ./src/primitives.h ./src/primitives/*/*
	$(CC) $(CFLAGS) -c ./src/primitives/*/*.c

alloc.o: ./src/alloc.h ./src/alloc/*.h
	echo "empty"

build: primitives.o alloc.o
	mkdir -p $(TARGET)
	$(AR) rcs $(LIB_NAME).a *.o

test: build
	$(CC) $(CFLAGS) $(TEST_DIR)/*.c -L$(NAME) -o $(TARGET)/tests
	$(TARGET)/tests

clean:
	rm *.o *.a
	rm $(TARGET)/*


