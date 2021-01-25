# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 20/01/2020
# 	Problem: Convergents of e
# 	Approach:
#		- Used https://oeis.org/A003417 for euler's continued fraction
#		- Constructed the fraction
#		- Added the numerator
# **************************************************************************

from math import gcd

euler = [2, 1, 2, 1, 1, 4, 1, 1, 6, 1, 1, 8, 1, 1, 10, 1, 1, 12, 1, 1, 14, 1, 1, 16, 1, 1, 18, 1, 1, 20, 1, 1, 22, 1, 1, 24, 1, 1, 26, 1, 1, 28, 1, 1, 30, 1, 1, 32, 1, 1, 34, 1, 1, 36, 1, 1, 38, 1, 1, 40, 1, 1, 42, 1, 1, 44, 1, 1, 46, 1, 1, 48, 1, 1, 50, 1, 1, 52, 1, 1, 54, 1, 1, 56, 1, 1, 58, 1, 1, 60, 1, 1, 62, 1, 1, 64, 1, 1, 66, 1]

class Fraction:
	def __init__(self, num, den):
		self.num = num
		self.den = den

	def add(self, b):
		den = self.den * b.den
		num = self.num*b.den + b.num*self.den
		ratio = gcd(num, den)

		self.num = num//ratio
		self.den = den//ratio

	def get_num(self):
		return self.num

	def inverse(self):
		self.num, self.den = self.den, self.num

	def __str__(self):
		return "{}/{}".format(self.num, self.den)



def find_fraction(cnt_fract):
	temp = Fraction(1, cnt_fract[-1])
	cnt_fract = cnt_fract[0:len(cnt_fract)-1]

	for i in reversed(cnt_fract):
		temp.add(Fraction(i,1))
		temp.inverse()

	temp.inverse()

	return temp


convergent = find_fraction(euler[0:100])
num = str(convergent.get_num())

sm = 0
for i in num:
	sm += int(i)

print("Sum of the numberator of the 1000th converget :",sm)
