# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 13/12/2019
# 	Problem: Totient maximum
# 	Approach:
#		- Smart Brute force
#		Time : O(1000000)
#		Space : O(1000000)
# 
# **************************************************************************/

import math as mt

def sieve(n):
	spf = [i for i in range(n)]

	for i in range(4, n, 2):
		spf[i] = 2

	limit = mt.ceil(n**0.5)
	for i in range(3, limit, 2):
		# if prime
		if spf[i] == i:

			for j in range(i*i, n, i):
				if spf[j] == j:
					spf[j] = i

	return spf

def factorization(x, spf):
	factors = set()
	while x != 1:
		factors.add(spf[x])
		x = x // spf[x]

	return factors

n = 1000000
max_ = 0
max_index = 0

spf = sieve(n)

for i in range(2, n):
	factors = factorization(i, spf)
	count = i
	for j in factors:
		count *= (1-1/j)
	
	if i/count > max_:
		max_ = i/count
		max_index = i

print("Maximum Index : {}, Maximum value: {}".format(max_index, max_))


