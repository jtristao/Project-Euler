import numpy as np

def create_pandigital(n, limit):
	s = ""
	for i in range(1, limit+1):
		s += str(n*i)

	return s

def test_pandigital(s):
	digits = np.zeros(9)
	for i in s:
		digits[int(i)-1] += 1

	for i in digits:
		if i != 1:
			return False
	return True

pandigitals = []
for i in range(9, 10000):
	for j in range(2, 6):
		s = create_pandigital(i, j)
		if test_pandigital(s) == True:
			pandigitals.append(int(s))

pandigitals.sort(reverse=True)
print("Largest pandigital : ", pandigitals[0])