#! /usr/bin/python3

#usage ./mult_measure.py prgname

#execute testprogram (prgname)
n_rep = 10 
#times 

#for matrizes
matrix_sizes =  ["100", "200", "300", "400", "500", "600"]

#print: matrix size, mean time, std deviation, std deviation in % 

import subprocess
import sys
import math

if (len(sys.argv) == 2):
  prg = "./" + sys.argv[1]   #set program name
  result = [0]*n_rep

  for N in matrix_sizes:
    
    tsum = 0
    for i in range(n_rep):
      resultStr = subprocess.check_output([prg, N]) #get prg output
      result[i] = float(resultStr) / 1000   #multiplication time in microseconds 
      tsum += result[i]
      
    mean = tsum / n_rep       #  calc mean
    #calc std deviation
    diffquadsum = 0           
    for i in range(n_rep):
      diffquadsum += (result[i] - mean)**2
    sigma = math.sqrt(diffquadsum/n_rep)  
    
    #print (int(N), int(mean), int(sigma), int(sigma/mean*100))
    print (int(N), int(mean))

