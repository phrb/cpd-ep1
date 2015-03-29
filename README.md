## Files
* Makefile                  builds all C sources
* mult_orig.c               original version of matrix multiplication (with quirk)
* README.md                 this file

* mult_measure_seq.py       measure sequential version repeatedly output stats
* mult_seq.c                sequential version of matrix multiplication (with time measuring)
* mult_seq_prio.c           sequential version with realtime priority

* mult_measure_par.py       measure parallel version repeatedly and save stats in file
* mult_par.c                parallel version of matrix multiplication (with time measuring)

* mult_par_test.result      example test result
* showresult.dem            example gnuplot script to display results


## Measurement

* compile executables: make
* edit mult_measure_par.py to set matrix size, iterations, number of threads
* measurement: ./mult_measure_par.py <filename executable> <filename results>
* edit showresult.dem to adjust
* plot: gnuplot showresult.dem


## Tips n tricks

### Generate stress on os [tool](http://weather.ou.edu/~apw/projects/stress/)
```stress --cpu 8 --vm 4 --timeout 200s```
