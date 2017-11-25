#!/bin/python

import sys


n = int(raw_input().strip())
calories = map(int, raw_input().strip().split(' '))
# your code goes here
print sum(c*2**j for (j,c) in enumerate(sorted(calories, reverse=True)))
