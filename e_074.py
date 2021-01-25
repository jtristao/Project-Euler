# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 16/12/2019
# 	Problem: Digit factorial chains
# 	Approach:
#		- Brute force
# 
# **************************************************************************

import numpy as np
import math as mt

def fact_sum(n):
	number = str(n)
	sum_ = 0
	for i in number:
		sum_ += mt.factorial(int(i))

	return sum_

def get_sequence(cur):
	seq = []

	while cur not in seq:
		seq.append(cur)
		cur = fact_sum(cur)

	return seq

n = 1000000
seq_len = {}

print("Processing(Takes 1 min)....")

for i in range(n):
	seq = get_sequence(i)
	size = len(seq)
	if size in seq_len:
		seq_len[size] += 1
	else:
		seq_len[size] = 1

print("Number of chains :", seq_len[60])