# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 27/04/2020
# 	Problem: Optimum polynomial
# 	Approach:
#		- Use Lagrange interpolation to fit the numbers and find a function
#		- Find the next element in sequence
#
# **************************************************************************/

def generating_function(x):
	return 1 - x + x**2 - x**3 + x**4 - x**5 + x**6 - x**7 + x**8 - x**9 + x**10

def cubic(x):
	return x**3

def lagrange_interpolation(sequence):
	size = len(seq)
	interpolation_point = size+1

	x = list(sequence.keys())
	y = list(sequence.values())

	acc = 0
	for j in range(0, size):
		aux = y[j]

		for i in range(0, size):
			if i != j:
				aux *= (interpolation_point - x[i])/(x[j] - x[i])

		acc += aux

	return acc


# size = max_degree_of_function+1
size = 10+1

seq = dict()
sum_ = 0
for i in range(1, size):
	seq[i] = generating_function(i)
	sum_ += lagrange_interpolation(seq)

print(int(sum_))