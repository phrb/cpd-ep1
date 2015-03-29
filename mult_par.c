#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include <omp.h>


int main(int argc, char **argv) {

  long **a, **b, **c;
  int N = 100;

  struct timespec ts_start;
  struct timespec ts_stop;
  long unsigned int calctime;

  int nthreads = 1;

  omp_set_dynamic(0);
  long tmp;                       // reduce var (instead of c[i][j]


  if (argc == 3) {
    N = atoi (argv[1]);
    assert (N > 0);
    nthreads = atoi(argv[2]);
    assert (nthreads > 0);
  }

  int i,j,k,mul=5;
  long col_sum = N * (N-1) / 2;

  a = (long **)malloc (N * sizeof(long *));
  b = (long **)malloc (N * sizeof(long *));
  c = (long **)malloc (N * sizeof(long *));

  for (i=0; i<N; i++) {
    a[i] = (long *)malloc (N * sizeof(long));
    b[i] = (long *)malloc (N * sizeof(long));
    c[i] = (long *)malloc (N * sizeof(long));
  }


  for (i=0; i<N; i++)
    for (j=0; j<N; j++) {
        a[i][j] = i*mul;
      b[i][j] = i;
      c[i][j] = 0;
      }

  //printf ("Matrix generation finished.\n");

  omp_set_num_threads(nthreads);  // set thread number

  // start clock
  clock_gettime(CLOCK_MONOTONIC, &ts_start);

  for (i=0; i<N; i++)

    for (j=0; j<N; j++){

      tmp = 0L;
      #pragma omp parallel for reduction(+:tmp)
      for (k=0; k<N; k++){
        tmp += a[i][k] * b[k][j];
        if (omp_get_num_threads() != nthreads)
          printf ("Got %d threads but requested %d threads.\n", omp_get_num_threads(), nthreads);
      }

      c[i][j] = tmp;
    }

  // stop clock
  clock_gettime(CLOCK_MONOTONIC, &ts_stop);

  calctime = (ts_stop.tv_sec * 1000000000L + ts_stop.tv_nsec) - (ts_start.tv_sec * 1000000000L + ts_start.tv_nsec);
  printf ("%lu\n", calctime);

  //printf ("Multiplication finished.\n");

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      assert ( c[i][j] == i*mul * col_sum);

  //printf ("Test finished.\n");

  return 0;
}
