CC=gcc
CFLAGS=-Wall -fopenmp -lrt -lm

all: nowait
clean:
	rm nowait

mult_par_v2: mult_par_v2.c  
	$(CC) $(CFLAGS) -o nowait nowait.c
