# **************************************************************************
# 	Author: João V. Tristão
# 	Date: 07/01/2020
# 	Problem: Right triangles with integer coordinates
# 	Approach:
#		- Generate all possible triangles
#		- Check if they form a right triangle
#		- Divide by two, since every right triangle is counterd twice
# 
# **************************************************************************

limit = 50
points = []

for x in range(0, limit+1):
	for y in range(0, limit+1):
		points.append((x,y))

count = 0
for p1 in points:
	for p2 in points:
		cat_a = (p1[0]**2 + p1[1]**2)
		cat_b = (p2[0]**2 + p2[1]**2)
		cat_c = ((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]))

		if cat_a != 0 and cat_b != 0 and cat_c != 0:
			if cat_a + cat_b == cat_c or cat_a + cat_c == cat_b or cat_b + cat_c == cat_a:
				count += 1


print("Triangles :", count/2)