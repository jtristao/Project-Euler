# **************************************************************************
#
# 	Author: João V. Tristão
# 	Date: 26/06/2023
# 	Problem: Red, Green or Blue Tiles
# 	Approach:
#       - Conting the number of ways of arranging A and B blocks
#       - AAAB + AABBB + ABBBBB
#
# **************************************************************************

import math

def main():
    n = 6
    colors = [2,3,4]
    color_sums = [0,0,0]

    for i in range(3):
        a = math.floor(n/colors[i])
        b = n - a*colors[i]
        total = a
        for j in range(0, total):
            color_sums[i] += math.comb(a+b, a)
            b += colors[i]
            a -= 1

    print("Number of ways: ", sum(color_sums))


if __name__ == "__main__":
   main()