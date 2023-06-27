# **************************************************************************
#
# 	Author: João V. Tristão
# 	Date: 26/06/2023
# 	Problem: Red, Green, and Blue Tiles
# 	Approach:
#       - Dynamic Programming
#
# **************************************************************************

def main():
    n = 50
    dp = [0] * (n+5)
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4

    for i in range(4, n+1):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4]

    print("Number of ways: ", dp[n])

if __name__ == "__main__":
   main()