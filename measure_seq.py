#! /usr/bin/python3

import subprocess
import sys
import math

#usage ./mult_measure.py prgname resultfilename

#execute testprogram (prgname)
n_rep = 10
#times

#for matrizes
matrix_sizes =  ["50", "100", "200", "400", "600", "800", "1000", "1200"]

n_matrix_sizes = len(matrix_sizes)

#result matrix resm[n_matrix_sizes][n_threads]
resm = [0 for i in range(n_matrix_sizes)]

if (len(sys.argv) == 3):
  #get program name
  prg = "./" + sys.argv[1]
  result = [0]*n_rep
  #get filename for result
  filename = sys.argv[2]


  for m in range(n_matrix_sizes):

    tsum = 0
    for i in range(n_rep):
      #call matrix multiplication and get output (calc time)
      #print("")
      resultStr = subprocess.check_output([prg, matrix_sizes[m]])
      result[i] = float(resultStr) / 1000                                #mult time in microseconds
      tsum += result[i]

    #calc mean
    mean = tsum / n_rep
    resm[m] = int(mean)
    print( sys.argv[1] + "\tsize: " + matrix_sizes[m] )
    #calc std deviation
    #diffquadsum = 0
    #for i in range(n_rep):
    #  diffquadsum += (result[i] - mean)**2
    #sigma = math.sqrt(diffquadsum/n_rep)

  #save result in file
  # line in output table: <matrix_size> <calctime> <calctime> ... <calctime>
  # calctimes for given thread numbers - see threads array
  f = open(filename, 'w')   #truncs old file with same name
  for m in range(n_matrix_sizes):
    line = matrix_sizes[m] + "\t" + str(resm[m]) + "\n"
    f.write(line)
  f.close()


