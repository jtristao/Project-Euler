# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 07/01/2020
# 	Problem: Coin partitions
# 	Approach:
#		- Dynamic Programming:
#			- It's the coin problem, but all the coins are all the numbers from 1 to n
#		- A little bit slow, took about 6 min.
#		- Cheated to find a good superior limit
# **************************************************************************


limit = 56000
piles = [0 for i in range(limit+1)]

piles[0] = 1

for i in range(1, limit+1):
	for j in range(i, limit+1):
		piles[j] += piles[j-i]

	if piles[i] % 1000000 == 0:
		print("Answer", i)
		exit(0)

print(piles)