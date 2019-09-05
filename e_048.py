# /**************************************************************************
	# Author: João V. Tristão
	# Date: 22/05/2019
	# Problem: Self Powers
	# Approach: 
		# Use only the last 10 digits of the powers and add they

# **************************************************************************/


def main():
	soma = 0;
	for i in range(1, 1000+1):
		soma += ((i ** i)%10000000000)
		print(i, soma)
	print(soma%10000000000)

if __name__ == "__main__":
	main()