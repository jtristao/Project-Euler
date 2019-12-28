# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 28/12/2019
# 	Problem: Totient maximum
# 	Approach:
#		- Smart Brute force
#		Time : O(10000000)
#		Space : O(10000000)
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

def check_permutation(orig, perm):
	original = str(orig)
	permutation = str(perm)

	if len(original) != len(permutation):
		return False
	else:
		occr = [0 for i in range(10)]
		
		for i in original:
			occr[int(i)] += 1
		
		for i in permutation:
			occr[int(i)] -= 1
		
		for i in occr:
			if i != 0:
				return False

		return True

n = 10000000
min_ = 0x3f3f3f3f
min_index = 0

spf = sieve(n)

for i in range(2, n):
	factors = factorization(i, spf)
	count = i
	for j in factors:
		count *= (1-1/j)
	count = int(count)

	if check_permutation(i, count):
		ratio = i/count

		if ratio < min_:
			min_ = ratio
			min_index = i

	if i % 100000 == 0:
		print(i/100000)

print("Minimum Index : {}, Minimum value: {}".format(min_index, min_))
