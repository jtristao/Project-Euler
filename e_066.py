# **************************************************************************
#	 Author: João V. Tristão
#	 Date: 28/01/2020
#	 Problem: Odd period square roots
#	 Approach:
#		- According to http://www.ams.org/notices/200202/fea-lenstra.pdf, 
#			the solution to x² - d*y² = 1 can be found serching for the conitnued fraction of sqrt(d)
#		- Construct the continued fraction based on http://www.kurims.kyoto-u.ac.jp/EMIS/journals/GMN/yahoo_site_admin/assets/docs/1_GMN-8492-V28N2.190180001.pdf
# **************************************************************************

from math import gcd
from math import floor

def continued_fraction_sqrt(n):
	a = [0,1]
	b = [1,0]
	c = [n,1]

	while True:
		q = floor(((n-c[0]*c[1])**0.5 + n**0.5)/c[1])
	
		a[0], a[1] = a[1], q*a[1] + a[0]
		b[0], b[1] = b[1], q*b[1] + b[0]
		c[0], c[1] = c[1], 2*q*(n-c[0]*c[1])**0.5 + c[0] - q**2*c[1]

		if a[1]**2 - n*b[1]**2 == 1:
			return a[1], b[1]

j = 1
limit = 1000
mx = 0
mx_d = 0
for i in range(1, limit+1):
	if j*j == i:
		j+=1
	else:
		x,y = continued_fraction_sqrt(i)
		if x > mx:
			mx = x
			mx_d = i
		# print("{}² - {}*{}² = 1 ({})".format(x, i, y, x*x-i*y*y))

print("Max :", mx_d)