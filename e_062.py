# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 04/10/2019
# 	Problem: Cubic permutations
# 	Approach:
#		- Build a dictionary where 	every key is the the digits count of i^3, 
# 			and the value is a list of i's for that histogram, with i e N in (0,10000)
#
# **************************************************************************

import numpy as np

def hist(n):
	to_str = str(n)
	occ = np.zeros(10)
	for i in range(len(to_str)):
		occ[int(to_str[i])] += 1

	return tuple(occ)

numbers = {}
for i in range(0, 10000):
	h = hist(i**3)
	numbers.setdefault(h, []).append(i)

for i,j in numbers.items():
	if len(j) == 5:
		ans = i, j
		break

print(i, j)
print("Ans = ", j[0]**3)