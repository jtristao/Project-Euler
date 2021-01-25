
def sum_digits(k):
	_sum = 0
	num = str(k)
	for c in num:
		_sum += int(c)

	return _sum

arbitrary_range = 1000
arbitrary_power = 10
numbers = list()

for i in range(2, arbitrary_range+1):
	for j in range(2, arbitrary_power+1):
		if i == sum_digits(i**j):
			numbers.append(i**j)

numbers.sort()
print(numbers[29])