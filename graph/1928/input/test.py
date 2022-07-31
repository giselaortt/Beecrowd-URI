import os
import sys


fptr = open( "C_23" )

t = 0
p = 0
for line in fptr.readlines():
    if( "T" in line ):
        t = t+1
    if( "P" in line ):
        p = p+1

print( "number of p's = ", p, "\nnumber of t's: ", t )
