# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 13/12/2019
# 	Problem: Totient maximum
# 	Approach:
#		- Realy nice explanation : https://www.xarg.org/puzzle/project-euler/problem-72/
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
spf = sieve(n+1)
sm = 0
for i in range(2, n+1):
	factors = factorization(i, spf)
	count = i
	for j in factors:
		count *= (1-1/j)
	sm += int(count)

print("Number of elements :", sm)


