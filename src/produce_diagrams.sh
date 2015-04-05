#! /bin/bash

gnuplot showresult_seq_vs_1thread_amd.dem > seq_vs_1thread_amd.png
gnuplot showresult_seq_vs_1thread_c2d.dem > seq_vs_1thread_c2d.png
gnuplot showresult_old_new.dem > old_new.png
gnuplot showresult_par_threads.dem

