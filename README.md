## Files

* Makefile:

    Builds all C sources.
    
=======

* mult_orig.c:

    Original version of matrix multiplication (with quirk).

* mult_seq.c:

    Sequential version of matrix multiplication (with time measuring).

* mult_seq_prio.c:

    Sequential version with realtime priority.
    
* mult_par_v1.c:

    Parallel version of matrix multiplication. Parallelization: inner loop (k)
    
* mult_par_v2.c:

    Parallel version of matrix multiplication. Parallelization: middle loop (j)

* mult_par_v3.c:

    Parallel version of matrix multiplication. Parallelization: outer loop (i)


=======

* measure_par.py:

    Measure parallel version repeatedly and save stats in file.

* measure_seq.py:

    Measure sequential version repeatedly output stats.
    
=======

* mult_par_test.result:

    Example test result.

* showresult.dem:

    Example gnuplot script to display results.

* measure_all.sh:

    Bash script to execute test series with different program versions.

## Measurement

* Compile executables: make
* Edit mult_measure_par.py to set matrix size, iterations, number of threads.
* Measurement: ./mult_measure_par.py <filename executable> <filename results>.
* Edit showresult.dem to adjust.
* Plot: gnuplot showresult.dem.


## Tips 'n tricks

Generate stress on OS with [this tool](http://weather.ou.edu/~apw/projects/stress/):

```stress --cpu 8 --vm 4 --timeout 200s```
