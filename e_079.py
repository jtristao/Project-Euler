# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 13/12/2019
# 	Problem: Passcode derivation
# 	Approach:
#		- Empirically explore the options
# 
# **************************************************************************/


import numpy as np

numbers = [319, 680, 180, 690, 129, 620, 762, 689, 762, 318, 368, 710, 720, 710, 629, 168, 160, 689, 716, 731, 736, 729, 316, 729, 729, 710, 769, 290, 719, 680, 318, 389, 162, 289, 162, 718, 729, 319, 790, 680, 890, 362, 319, 760, 316, 729, 380, 319, 728, 716]

numbers = np.asarray(numbers)
numbers = np.unique(numbers)

list_of_precedence = []
for i in range(0, 10):
	pre = set()
	value = str(i)
	for j in numbers:
		number = str(j)

		if value in number:
			begin = number.find(value)
			size = len(number)
			for i in range(begin, 0, -1):
				pre.add(int(number[i-1]))

	list_of_precedence.append(pre)

password = ""
discarded = {4, 5}
while len(discarded) != 10:
	j = 0
	for i in list_of_precedence:
		if j not in discarded:
			if len(i) == 0:
				to_discard = j
				break
		j += 1
	discarded.add(to_discard)
	password += str(to_discard)
	for i in list_of_precedence:
		i.discard(to_discard)

print("Password :", password)