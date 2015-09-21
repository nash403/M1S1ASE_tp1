CC=gcc
CFLAGS=-m32 -Wall -g

all: display_stack try_mul

try.o:
	$(CC) -o try.h try.c

try_mul: try.o
	$(CC) -o try_mul try_mul.c $(CLFAGS)

display_stack: display_stack.c
	$(CC) -o display_stack display_stack.c $(CFLAGS)
	./display_stack

clean:
	rm -f *~ *.o display_stack try_mul