# /**************************************************************************
	# Author: João V. Tristão
	# Date: 11/07/2019
	# Problem: Lychrel numbers
	# Approach:
		# Assume that every number is a Lynchrel and test for a max of 50 itrations

# **************************************************************************

def palindrome(str):
	size = len(str)//2

	for i in range(0, size):  
		if str[i] != str[len(str)-i-1]: 
			return False
	return True

def reverse_add(number):
	# Reverse number
	aux = str(number)
	aux = int(aux[::-1])
			
	# add
	number += aux

	return number

def main():
	counter = 0
	for i in range(10000):
		number = reverse_add(i)
		k = 0
		
		while(palindrome(str(number)) == False and k <= 50):
			k += 1
			number = reverse_add(number)

		if(k == 51):
			print(i, end='\t')
			counter += 1

	print("\nThere are:", counter, "Lychrel numbers below ten-thousand")


if __name__ == '__main__':
	main()
	