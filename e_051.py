def magic_function(n, k):
	


limit = 50000
begin = 0

# For every number in range
for i in range(begin, limit):
	number = str(i)
	len_ = len(number)
	
	# For every k (n chose k)
	for k in range(len_):
		magic_function(i, k)