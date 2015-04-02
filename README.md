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

## Hardware

CPU A:

```
$ uname -a
Linux HAL8k 3.2.0-4-amd64 #1 SMP Debian 3.2.65-1 x86_64 GNU/Linux
```

```
$ cat /proc/cpuinfo | grep model\ name
model name      : AMD FX(tm)-6100 Six-Core Processor 
```

```
$ lscpu
Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                6
On-line CPU(s) list:   0-5
Thread(s) per core:    2
Core(s) per socket:    3
Socket(s):             1
NUMA node(s):          1
Vendor ID:             AuthenticAMD
CPU family:            21
Model:                 1
Stepping:              2
CPU MHz:               3300.000
BogoMIPS:              6622.20
Virtualization:        AMD-V
L1d cache:             16K
L1i cache:             64K
L2 cache:              2048K
L3 cache:              8192K
NUMA node0 CPU(s):     0-5
```
