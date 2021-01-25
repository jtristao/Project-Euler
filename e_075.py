# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 07/01/2020
# 	Problem: Singular integer right triangles
# 	Approach:
#		- Generate all pythagorean triplets using euclides formula
#		- Count the occurrence of every lentgh
#		- Count the ones that happened only once
# 
# **************************************************************************

from math import gcd

limit = 1500000
triplets_range = 1000

triplets = []
length = {}
for i in range(1, triplets_range+1):
	for j in range(i, triplets_range+1):
		if gcd(i,j) == 1 and not (i%2 == 1 and j%2 == 1):
			a = j**2 - i**2
			b = 2*i*j
			c = j**2 + i**2

			triplets.append((a, b, c))

for tri in triplets:
	k = 1
	total = sum(tri)

	while total <= limit:
		if total in length:
			length[total] += 1
		else:
			length[total] = 1

		k += 1
		total = sum(tri) * k


count = 0
for i in length:
	if length[i] == 1:
		count += 1

print(count)