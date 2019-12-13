# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 13/12/2019
# 	Problem: Distinct primes factors
# 	Approach:
#		- Pre calculate the prime decomposition in a table from 2 to 1000000
#		- Add the factorization in a set.
#		- While the len of the set is smaller than 16, keep searching.
#		Time : O(n)
#		Space : O(1)
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

def normalize(factors):
	ret = list()
	i = 0
	while i < len(factors):
		temp = factors[i]
		while i < len(factors)-1 and factors[i] == factors[i+1]:
			temp *= factors[i]
			i += 1

		ret.append(temp)
		i+=1

	return ret

def find_factors(x, spf):
	factors = []
	while x != 1:
		factors.append(spf[x])
		x = x // spf[x]

	factors = normalize(factors)

	return factors

def length_test(factors, seq_len):
	for i in factors:
		if len(i) != seq_len:
			return True

	return False

n = 1000000
spf = sieve(n)
primes = set()
factors = []
k = 6
seq_len = 4


for i in range(2, 2+seq_len):
	factors.append(find_factors(i, spf))

for i in range(seq_len):
	primes.update(factors[i])



while len(primes) != seq_len*seq_len or length_test(factors, seq_len):
	# Remove first element from list
	factors.remove(factors[0])

	# Add new element
	factors.append(find_factors(k, spf))

	# Update set
	primes.clear()
	for i in range(seq_len):
		primes.update(factors[i])

	k += 1

print("First integer :", k-seq_len)