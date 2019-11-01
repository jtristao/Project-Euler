import numpy as np
import math as mt

numbers = np.genfromtxt("base_exp.txt", delimiter=",")

max_ = mt.log(numbers[0][0])*numbers[0][1]
max_index = 0
for i in range(1000):
	n = mt.log(numbers[i][0])*numbers[i][1]
	if max_ < n:
		max_ = n
		max_index = i

print("Ans = ", max_index+1)

