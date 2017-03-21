CFLAGS += -pedantic -Wall
CFLAGS += -I../include

%.o: %.c ../include/sparse_array.h
	$(CC) $(CFLAGS) -c $*.c -o $@

