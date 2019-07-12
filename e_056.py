# **************************************************************************
	# Author: João V. Tristão
	# Date: 
	# Problem: 
	# Approach:

# **************************************************************************

def char_count(k):
	count = 0
	number = str(k)
	for i in range(len(number)):
		count += int(number[i])

	return count

def main():
	max_value = 0
	for i in range(0, 100):
		for j in range(0, 100):
			max_value = max(char_count(i**j), max_value)
	print("Maximum digital sum = ",max_value)


if __name__ == '__main__':
	main()
