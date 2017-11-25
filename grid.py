# Enter your code here. Read input from STDIN. Print output to STDOUT

#!/bin/python
import sys

def Check(l, n):
    for j in xrange(n):
        for i in xrange(n-1):
            if l[i][j] > l[i+1][j]:
                return "NO"
    return "YES"
    
t=int(raw_input())
for i in xrange(t):
    l=[]
    n=int(raw_input())
    for i in xrange(n): 
        l.append("".join(sorted(raw_input())))
    print(Check(l,n))

