# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 14/05/2020
# 	Problem: Palindromic sums
# 	Approach:
#		- Use accumulate sum of squares
#		- For every pair (begin, end) = (i,j) -> acc[j] - acc[i] = a sum of a continuos sequence of squares
#			- Check if below the limit anf if it is a palindrome
#
# **************************************************************************


import numpy as np

def is_palindrome(n):
	""" Check if a number is a palidrome """
	num = str(int(n))

	begin = 0
	end = len(num)-1

	while begin < end:
		if num[begin] != num[end]:
			return False

		begin += 1
		end -= 1

	return True

def find_index_limit(n):
	""" find the optimal limit for a given n, using: x**2 + (x-1)**2 = n """

	delta = 4*(n//2)

	return int((1 + delta**0.5)//2 + 1)

limit = 100000000
index_limit = find_index_limit(limit)

# Pre-calculates the accumulate sum of squares
acc_sum = np.zeros(index_limit)
for i in range(1, index_limit):
	acc_sum[i] = acc_sum[i-1] + i**2


nums = set()
for i in range(0, index_limit):
	for j in range(i+2, index_limit):
		temp = acc_sum[j] - acc_sum[i]
		if temp < limit and is_palindrome(temp):
			nums.append(temp)


print("Sum = {}".format(np.sum(nums)))