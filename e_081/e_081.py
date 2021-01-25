# /**************************************************************************
# 	Author: João V. Tristão
# 	Date: 16/12/2019
# 	Problem: Path sum: two ways
# 	Approach:
#		- Accumulate the sum, chosing from the minimun between upper or lefter options.
#		Time : O(m*n), m = n_rows, n = n_cols
#		Space : O(1)
# 
# **************************************************************************/

import numpy as np

def matrix_print(matrix):
	for row in matrix:
		for elem in row:
			print(elem, end=" ")
		print()
	print()

matrix = np.genfromtxt("input.in", delimiter=",", dtype=int)
row_len = len(matrix)
col_len = len(matrix[0])

size = row_len + col_len

for i in range(0, size):
	# matrix_print(matrix)
	start = max(0, i-col_len)
	count = min(i, row_len-start, row_len)

	for j in range(0, count):
		row = start+j
		col = min(row_len, i)-j-1

		min_ = 0x3f3f3f3f
		if row-1 >= 0:
			min_ = min(min_, matrix[row-1][col])
		if col-1 >= 0:
			min_ = min(min_, matrix[row][col-1])

		if min_ != 0x3f3f3f3f:
			matrix[row][col] += min_

print("Minimal path sum :", matrix[row_len-1][col_len-1])