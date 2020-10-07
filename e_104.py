# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 07/10/2020
# 	Problem: Pandigital Fibonacci ends
# 	Approach:
#		- Check for the last digits using modolus (the rest of the nubmer is not relevant for that)
#		- If the end is pandigital, find the kth fibonacci using the golden ratio
#		- Use a especial power function to avoid overflow
#
# **************************************************************************
from math import sqrt

def check_pandigital(string):
	count = [0 for i in range(0,10)]

	for c in string:
		count[int(c)] += 1

	for i in range(1,10):
		if count[i] != 1:
			return False

	if count[0] == 1:
		return False
	return True

def pow(x, n):
	res=1.0
	for i in range(n):
		res *= x
			# truncation to avoid overflow:
		if res>1E20: 
			res*=1E-10
	
	return res

def fibonacci(n):
	golden_ratio = (1+sqrt(5))/2

	return round(pow(golden_ratio, n)/(5**0.5))

def main():
	a = 1
	b = 1
	found = False
	index = 3

	while not found:
		fib = (a + b)%1000000000
		a = b
		b = fib

		end = str(fib)      
		if(check_pandigital(end)):
			fib = str(fibonacci(index))
			
			begin = fib[0:9]
			
			if(check_pandigital(begin)):
				found = True;

		index += 1

	print("Answer:", index-1)

if __name__ == '__main__':
	main()

