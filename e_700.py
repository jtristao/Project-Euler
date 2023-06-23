# **************************************************************************
#
# 	Author: João V. Tristão
# 	Date: 30/01/2021
# 	Problem:
# 	Approach:
#
# **************************************************************************


def euler_coin(n):
    m = 1504170715041707 * n % 4503599627370517

    return m


def main():
    min_val = float("inf")
    euler_coins = list()

    for i in range(1, 1000000000):
        coin = euler_coin(i)

        if coin < min_val:
            euler_coins.append(coin)
            min_val = coin

    print(euler_coins)


if __name__ == "__main__":
    main()