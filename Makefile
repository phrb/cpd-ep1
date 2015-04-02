CC=gcc
CFLAGS=-Wall

all: mult_seq mult_seq_prio mult_par_v1 mult_par_v2 mult_par_v3
clean:
	rm mult_seq mult_seq_prio mult_par_v1 mult_par_v2 mult_par_v3

mult_seq: mult_seq.c  
	$(CC) $(CFLAGS) -o mult_seq mult_seq.c -lrt

mult_seq_prio: mult_seq_prio.c  
	$(CC) $(CFLAGS) -o mult_seq_prio mult_seq_prio.c -lrt

mult_par_v1: mult_par_v1.c  
	$(CC) $(CFLAGS) -o mult_par_v1 mult_par_v1.c -fopenmp -lrt

mult_par_v2: mult_par_v2.c  
	$(CC) $(CFLAGS) -o mult_par_v2 mult_par_v2.c -fopenmp -lrt

mult_par_v3: mult_par_v3.c  
	$(CC) $(CFLAGS) -o mult_par_v3 mult_par_v3.c -fopenmp -lrt
