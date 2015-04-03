CC=gcc
CFLAGS=-Wall -fopenmp -lrt -lm

all: fork fork_hangs
clean:
	rm fork fork_hangs

fork_hangs: fork_hangs.c
	$(CC) $(CFLAGS) -o fork_hangs fork_hangs.c

fork: fork.c
	$(CC) $(CFLAGS) -o fork fork.c
