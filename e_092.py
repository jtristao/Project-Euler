import numpy as np

def square_digits_sum(k):
	n = str(k)
	sum_ = 0
	for i in n:
		sum_ = sum_ + int(i)**2

	return sum_

n = 10000000
ending = np.zeros(800)
ending[1] = 1
ending[89] = 89

count = 0
print("Processing....")
for i in range(2, n+1):
	begin = square_digits_sum(i)
	cur = begin
	while ending[cur] == 0:
		cur = square_digits_sum(cur)

	if ending[cur] == 89:
		ending[begin] = 89
		count += 1
	else:
		ending[begin] = 1

print("Answer :", count)