# **************************************************************************
#	 Author: João V. Tristão
#	 Date: 22/01/2020
#	 Problem: Anagramic squares
#	 Approach:
#		- Gentle brute force
# **************************************************************************

from math import ceil

def palindrome(word_a, word_b):
	if len(word_a) == len(word_b):
		size = len(word_a)-1

		for i in range(size//2):
			if word_a[i] != word_b[size-i]:
				return False

		return True
	else:
		return False


def match(word_a, word_b):
	if len(word_a) == len(word_b) and palindrome(word_a,word_b) == False:
		letters = {}
		for i in word_a:
			if word_a in letters:
				letters[i] += 1
			else:
				letters[i] = 1

		for i in word_b:
			if i in letters:
				letters[i] -= 1
			else:
				letters[i] = -1

		for i in letters:
			if letters[i] != 0:
				return False

		return True
	else:
		return False

def repetition(k):
	num = str(k)
	letters = {}
	for i in num:
		if i in letters:
			return True
		else:
			letters[i] = 1

	return False

def verify_pattern(src, key, mask, squares):
	code = {}
	source = str(src)
	mask = str(mask)
	key = str(key)

	j = 0
	for i in source:
		code[i] = mask[j]
		j += 1

	num = ""
	for i in key:
		num += code[i]

	if int(num) in squares:
		return True
	else:
		return False


file_name = "e_098.in"
file = open(file_name, "r")

words = file.read()
words = words.split(",")
size = len(words)


# Find pairs
print("Finding pairs...")
pairs = []
for i in range(size):
	for j in range(i+1,size):
		if match(words[i], words[j]):
			pairs.append((words[i], words[j]))

# Find the size of the largest squre root
max_square = 0
for i, j in pairs:
	max_square = max(max_square, len(i), len(j))


max_square = 10**(ceil(max_square/2))

# Create all possible perfect numbers up to max_square
print("Finding perfect squares...")
pft_squares = {}
limit = 10
n_digits = 1
squares = set()
for i in range(1, max_square):
	if i*i > limit:
		pft_squares[n_digits] = squares.copy()
		squares.clear()

		limit *= 10
		n_digits += 1
	
	if repetition(i*i) == False:
		squares.add(i*i)

# Try all pairs codifications
print("Trying masks...")
square_anagram_word_pairs = []
for i,j in pairs:
	squares = pft_squares[len(i)]
	for num in squares:
		if verify_pattern(i, j, num, squares) == True:
			square_anagram_word_pairs.append((i, j, num))
		if verify_pattern(j, i, num, squares) == True:
			square_anagram_word_pairs.append((j, i, num))

# Search the max value
mx = 0
for triplet in square_anagram_word_pairs:
	if triplet[2] > mx:
		mx = triplet[2]
		mx_triplet = triplet

print(mx_triplet)