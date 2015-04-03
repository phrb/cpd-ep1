CC=gcc
CFLAGS=-Wall -fopenmp -lrt

all: mult_seq mult_seq_prio mult_par_v1 mult_par_v2 mult_par_v3
clean:
	rm mult_seq mult_seq_prio mult_par_v1 mult_par_v2 mult_par_v3

mult_seq: mult_seq.c
	$(CC) $(CFLAGS) -o mult_seq mult_seq.c

mult_seq_prio: mult_seq_prio.c
	$(CC) $(CFLAGS) -o mult_seq_prio mult_seq_prio.c

mult_par_v1: mult_par_v1.c
	$(CC) $(CFLAGS) -o mult_par_v1 mult_par_v1.c

mult_par_v2: mult_par_v2.c
	$(CC) $(CFLAGS) -o mult_par_v2 mult_par_v2.c

mult_par_v3: mult_par_v3.c
	$(CC) $(CFLAGS) -o mult_par_v3 mult_par_v3.c
