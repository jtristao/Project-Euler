# /*************************************************************************
# 	Author: João V. Tristão
# 	Date: 16/10/2020
# 	Problem: Concealed Square
# 	Approach: 
# 		- Check all numbers within a valid range
# 	Obs:
# 		It took about 8min to run
# *************************************************************************/

def check_val(n):
	num = str(n)

	for i in range(0, len(num)-1, 2):
		if int(num[i]) != 1+i/2:
			return False

	if int(num[len(num)-1]) != 0:
		return False

	return True

def main():
	min_abs_val = 1020304050607080900
	max_abs_val = 1929394959697989990

	min_val = int(min_abs_val**0.5)
	max_val = int(max_abs_val**0.5)
	spread = max_val-min_val

	for i in range(min_val, max_val):
		if check_val(i**2):
			print(i)
			break
		if i % 10000000 == 0:
			print("{:.2f} %".format(((i-min_val)/spread)*100), flush=True)

	
if __name__ == '__main__':
	main()