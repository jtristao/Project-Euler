# **************************************************************************
	# Author: João V. Tristão
	# Date: 17/07/2019
	# Problem: Square root convergents
	# Approach:
		# Use a Fraction class and brute force the operation

# **************************************************************************

class Fraction:
	def __init__(self, a, b):
		self.num = a
		self.den = b

	def __str__(self):
		return str(self.num) + "/" + str(self.den)

	def __add__(self, b):
		num = self.num*b.den + b.num*self.den
		den = self.den * b.den

		return Fraction(num, den)

	def invert(self):
		aux = self.num
		self.num = self.den
		self.den = aux


def count_digits(a):
	counter = 0
	while(a > 0):
		counter+=1
		a = a//10

	return counter

def compare_num_den(f):
	if(count_digits(f.num) > count_digits(f.den)):
		return True

	return False

def main():
	partial = Fraction(1,2)
	two = Fraction(2,1)
	one = Fraction(1,1)
	aux = Fraction(0, 0)

	counter = 0

	for i in range(1000):
		partial = partial + two
		partial.invert()

		aux = partial + one
		if(compare_num_den(aux)):
			counter += 1

	print("Number of fractions: ", counter)

if __name__ == '__main__':
	main()