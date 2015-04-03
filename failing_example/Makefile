CC=gcc
CFLAGS=-Wall -fopenmp -lrt -lm

all: nowait barrier
clean:
	rm nowait barrier

nowait: nowait.c  
	$(CC) $(CFLAGS) -o nowait nowait.c

barrier: barrier.c  
	$(CC) $(CFLAGS) -o barrier barrier.c
