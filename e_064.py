# **************************************************************************
#	 Author: João V. Tristão
#	 Date: 21/01/2020
#	 Problem: Odd period square roots
#	 Approach:
#		- Construct the continued fraction based on https://www.mathblog.dk/project-euler-continued-fractions-odd-period/
#		- Use the limit of corollary 3.3 on https://web.williams.edu/Mathematics/sjmiller/public_html/mathlab/public_html/jr02fall/Periodicity/alexajp.pdf 
# **************************************************************************

from decimal import *

def continued_fraction_sqrt(k):
	fraction = []

	m = 0
	d = 1
	a = int(k**0.5)
	begin = a

	while True:
		m = d*a-m
		d = (k-m**2)/d
		a = int((k**0.5+m)/d)

		fraction.append(a)

		if a == 2*begin:
			break

	return fraction

j = 1
cnt = 0
for i in range(1, 10000+1):
	if j*j == i:
		j+=1
	else:
		cnt_frac = continued_fraction_sqrt(i)
		if len(cnt_frac) % 2 == 1:
			cnt+=1

print("Odd period :",cnt)