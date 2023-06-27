# **************************************************************************
#
# 	Author: João V. Tristão
# 	Date: 27/06/2023
# 	Problem: Consecutive Positive Divisors
# 	Approach:
#		- Find all divisors up to n
#		- Check if n and n+1 had the same amount of divisors
#		- Tip: [number of natural divisors = (a+1)(b+1)(c+1)...] where a,b,c are powers of factors
#
# **************************************************************************

def divisor_count(k):
	cnt = 0
	i = 1
	while i*i <= k:
		if k % i == 0:
			cnt += 1
			if i != k/i:
				cnt += 1

		i += 1

	return cnt

def main():
	n = int(1e7)
	percent = n/100
	divisors = [0] * n

	for i in range(n):
		if i % percent == 0:
			print(i/n)
		divisors[i] = divisor_count(i)

	cnt = 0
	for i in range(2, n):
		if divisors[i] == divisors[i-1]:
			cnt += 1
	
	print("Number of positive divisors: ", cnt)

if __name__ == "__main__":
   main()