# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 13/01/2020
# 	Problem: Amicable chains
# 	Approach:
#		- Store in a vector the sum of the divisors
#		- Generate all possible sequences
#		- Check the valid sequence
#		- Took about 1 min to run
#
# **************************************************************************

def divisor_sum(k):
	sm = 0
	i = 1
	while i*i <= k:
		if k % i == 0:
			sm += i
			if i != k/i:
				sm += (k/i)

		i += 1

	return int(sm-k)

limit = 1000000
divisors = [0 for i in range(limit)]

for i in range(1, limit):
	divisors[i] = divisor_sum(i)
	# print(i, divisors[i])

visited = [0 for i in range(limit)]
chains = {}

for i in range(1, limit):
	seq = []
	cur = i
	while cur not in seq:
		seq.append(cur)
		if divisors[cur] < limit:
			cur = divisors[cur]
		else:
			break


	chains[i] = seq

max_len = 0
max_seq = []
for i in chains:
	seq = chains[i]
	last = seq[len(seq) - 1] 
	if last != 0:
		if divisors[last] == i:
			if len(seq) > max_len:
				max_len = len(seq)
				max_seq = seq

print("Largest sequence :", max_seq)
print("Smallest member :", min(max_seq))
