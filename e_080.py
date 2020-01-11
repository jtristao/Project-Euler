# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 10/01/2020
# 	Problem: Square root digital expansion
# 	Approach:
#		- Used a special python library
#
# **************************************************************************

from decimal import *

getcontext().prec = 105

total_sum = 0
perfect = 1
for i in range(1, 100):
	x = Decimal(i)
	sq = (x.sqrt()).as_tuple()

	if perfect*perfect == i:
		perfect += 1
	else:
		number = sq[1]

		partial_sum = 0
		for j in range(100):
			partial_sum += number[j]

		total_sum += partial_sum

print("Sum :", total_sum)