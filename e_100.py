# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 07/01/2020
# 	Problem: Arranged probability
# 	Approach:
#		- The probabilitie equation yelds a diophatine equation
#		- Searched for a recursive solution to diophatine's equation
#		- Kudos to https://www.alpertron.com.ar/QUAD.HTM
# **************************************************************************

x = 15
y = 6
limit = 1000000000000

while(x+y < limit):
    xn = 5*x + 2*y - 2
    yn = 2*x + y - 1
    
    x = xn
    y = yn

print("Answer :",x)
