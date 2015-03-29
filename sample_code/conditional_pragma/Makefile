CC=gcc
CFLAGS=-Wall

all: omp_if
clean:
	rm omp_if

omp_if: omp_if.c
	$(CC) $(CFLAGS) -o omp_if omp_if.c -fopenmp -lrt
