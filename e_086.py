# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 14/01/2020
# 	Problem: Cuboid route
# 	Approach:
#		- Brute Force a O(n^3) solution
#		- Result would took too long
#		- Give up
#		- Given a box of dimensions (a, b, c), the shortest path have the possible formats:
#				(a+b)**2 + c**2 or (a+c)**2 + b**2  or  (b+c)**2 + a**2
#			And forms the pythagorean triplet
#		
#		- Searched all possible pythagorean triplets within max range, generating the triples such as:
#			Given the pythagorean triplet (a,b,c), search for all values of (i,j,c), where 1<i<j, j>i
# **************************************************************************

from math import gcd

def integer_length(a, b, c):
	path1 = ((a+c)**2 + b**2)**0.5
	path2 = ((a+b)**2 + c**2)**0.5
	path3 = ((b+c)**2 + a**2)**0.5

	path = min(path1, path2, path3)
	
	if path % 1 == 0:
		return True
	else:
		return False

def find_boxes(a, b, c, limit):
	boxes = []
	while a <= b:
		if max(a, b, c) <= limit and integer_length(a, b, c):
			boxes.append(frozenset({a, b, c}))
		a += 1
		b -= 1

	return boxes

def find_triplets(triplets_range):
	triplets = []
	length = {}
	for i in range(1, triplets_range+1):
		for j in range(i, triplets_range+1):
			if gcd(i,j) == 1 and not (i%2 == 1 and j%2 == 1):
				a = j**2 - i**2
				b = 2*i*j
				c = j**2 + i**2

				if a > b:
					triplets.append((b, a, c))
				else:
					triplets.append((a, b, c))

	return triplets


triplets = find_triplets(200)

limit = 1818
boxes = set()
for tri in triplets:
	k = 1
	mn = min(tri)
	while mn <= limit:
		ret = find_boxes(1, tri[1]*k-1, tri[0]*k, limit)
		for i in ret:
			boxes.add(i)
		
		ret = find_boxes(1, tri[0]*k-1, tri[1]*k, limit)
		for i in ret:
			boxes.add(i)
		
		k += 1
		mn = min(tri)*k

print(limit, len(boxes))