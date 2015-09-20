CC=gcc
CFLAGS=-m32 -Wall -g

all: display_stack

try.o: try.c try.h
	$(CC) -o try.o 

try_mul: try.o try.h try_mul.c
	$(CC) -o try_mul try_mul.c $(CLFAGS)

display_stack: display_stack.c
	$(CC) -o display_stack display_stack.c $(CFLAGS)