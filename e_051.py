# **************************************************************************
#	 Author: João V. Tristão
#	 Date: 21/01/2020
#	 Problem: Prime digit replacements
#	 Approach:
#		- Create all possible masks below 1000000
#		- Explore all masks
#	Complexity:
#		- Sieve + n*2^len(n) + n*10
# **************************************************************************

def find_permutations_aux(num, pos, n, permutations):
	if pos == n:
		permutations.add(num)
	elif pos < n:
		find_permutations_aux(num, pos+1, n, permutations)

		# copy = num.replace(num[pos], "*")
		copy = list(num)
		copy[pos] = "*"
		copy = "".join(copy)

		find_permutations_aux(copy, pos+1, n, permutations)

def find_permutations(k):
	permutations = set()

	num = str(k)
	find_permutations_aux(num, 0, len(num), permutations)

	# Remove first(num) and last element("******")
	extra = "*"*len(num)
	permutations.remove(num)
	permutations.remove(extra)

	return permutations

def sieve(n):
	primes = [True for i in range(n)]

	primes[0] = False
	primes[1] = False

	limit = int(n**0.5)+1
	for i in range(limit):
		if primes[i] == True:
			for j in range(i*i, n, i):
				primes[j] = False

	return primes

primes_limit = 1000000
print("Finding primes...")
primes = sieve(primes_limit)

print("Generating masks...")
limit = 999999
number = set()
for pri in range(limit):
	if primes[pri] == True:
		permutations = find_permutations(pri)
		for num in permutations:
			number.add(num)


print("Exploring maks...")
for num in number:
	cnt = 0
	family = []
	for i in range(10):
		aux = num.replace("*", str(i))
		if int(aux) < limit and primes[int(aux)] == True and aux[0] != '0':
			family.append(int(aux))
			cnt += 1
	if cnt == 8:
		print("Prime :", min(family))
		exit()