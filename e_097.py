j = 1
for i in range(7830457+1):
	if i == 7830457:
		print(i, (28433*j)%10000000000+1)
	j = (j*2)%10000000000