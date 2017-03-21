CFLAGS += -fopenmp
CFLAGS += -pedantic -Wall
CFLAGS += -I../include

OBJ=$(patsubst %.c, %.o, $(wildcard *.c))

%.o: %.c ../include/sparse_array.h
	$(CC) $(CFLAGS) -c $*.c -o $@

test: test.c $(OBJ)
	$(CC) $* $(CFLAGS) *.o -o $@

default: test

clean:
	rm *.o
