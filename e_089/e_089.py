# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 11/01/2020
# 	Problem: Roman numerals
# 	Approach:
#		- Convert the roman numeral to arabic
#		- Convert the arabic to roman
#		- Compare the size difference
# **************************************************************************

roman = {"M":1000, "D":500, "C":100, "L":50, "X":10, "V":5, "I":1}
decimal = {1000:"M", 900:"CM", 500:"D", 400:"CD", 100:"C", 90:"XC", 50:"L", 40:"XL", 10:"X", 9:"IX", 5:"V", 4:"IV", 1:"I"}

def read_number(num):
	size = len(num)

	sm = 0
	i = 0
	while i < size: 
		cur = roman[num[i]]
		nxt = 0
		if i < size-1:
			nxt = roman[num[i+1]]
		
		if nxt > cur:
			sm += (nxt - cur)
			i += 1
		else:
			sm += cur

		i += 1

	return sm


def min_number(k):
	dec_n = list(decimal.keys())

	index = 0
	char_cnt = 0
	while k > 0:
		while k < dec_n[index]:
			index += 1

		quotient = k//dec_n[index]
		k %= dec_n[index]

		char_cnt += quotient * len(decimal[dec_n[index]])

	return char_cnt


file = open("e_089.in", "r")
numbers = file.read()
numbers = numbers.split("\n")

min_number(3569)

sm = 0
for num in numbers:
	dec_number = read_number(num)
	char_cnt = min_number(dec_number)
	sm += (len(num)-char_cnt)

print("Saved chars:", sm)
	