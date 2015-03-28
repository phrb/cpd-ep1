CC=gcc
CFLAGS=-Wall

all: mult_seq mult_seq_prio mult_par

mult_seq: mult_seq.c  
	$(CC) $(CFLAGS) -o mult_seq mult_seq.c -lrt

mult_seq_prio: mult_seq_prio.c  
	$(CC) $(CFLAGS) -o mult_seq_prio mult_seq_prio.c -lrt

mult_par: mult_par.c  
	$(CC) $(CFLAGS) -o mult_par mult_par.c -fopenmp -lrt


