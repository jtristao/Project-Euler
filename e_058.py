# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 19/08/2017
# 	Problem: Spiral Primes
# 	Approach:
#		- Use functions to find the value in the diagonal
#		- Check if the value is prime 
# 
# **************************************************************************/

import math

def sieve(primes):
	primes[0] = False
	primes[1] = False
	limit = math.ceil(math.sqrt(len(primes)))

	for i in range(2, limit):
		if primes[i] == True:
			j = i
			while j*i < len(primes):
				primes[i*j] = False
				j+=1

def f(x):
	return 4*x*x - 2*x + 1

def g(x):
	return 4*x*x + 1

def h(x):
	return 4*x*x + 2*x + 1

def is_prime(n, primes):
	limit = math.ceil(math.sqrt(n))
	if limit > len(primes):
		print("Larger value than expected")
		exit()
	for i in range(limit):
		if primes[i]:
			if n%i == 0:
				return False

	return True

def main():
	limit = 1000000
	primes = [True for i in range(limit+1)]
	sieve(primes)

	counter = 0
	rate = 1
	old_rate = 0
	i = 1

	while rate > 0.1:
		if is_prime(f(i), primes) == True:
			counter+=1
		
		if is_prime(g(i), primes) == True:
			counter+=1

		if is_prime(h(i), primes) == True:
			counter+=1

		old_rate = rate
		rate = counter/(1+4*i)
		i+=1;


	print((i-1)*2+1)

if __name__ == '__main__':
	main()