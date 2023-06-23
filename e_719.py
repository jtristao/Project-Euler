# **************************************************************************
#
# 	Author: João V. Tristão
# 	Date: 30/01/2021
# 	Problem:
# 	Approach:
#       - For every perfect square smaller then 10^12
#           - Find all splits
#           - Check if adds up
#   Complexity:
#       O(10^6 * 2^12)
#   Obs:
#       A little bit slow, took a few minutes to run
#
#
# **************************************************************************


def check_aux(num, pos, div, div_pos):
    if len(num) == pos:
        values = list(map(int, div.split(",")))
        total_sum = sum(values)

        if total_sum == int(num) ** 0.5:
            return True
        else:
            return False

    ret = check_aux(num, pos + 1, div, div_pos + 1)

    div = div[:div_pos] + "," + div[div_pos:]
    ret |= check_aux(num, pos + 1, div, div_pos + 2)

    return ret


def check_s_number(num):
    num = str(num)

    return check_aux(num, 1, num, 1)


def main():
    N = 10 ** 12

    limit = int(N ** 0.5)

    perfect_sqrs = [i * i for i in range(4, limit + 1)]

    total_sum = 0
    for i in range(len(perfect_sqrs)):
        sqr = perfect_sqrs[i]
        if check_s_number(sqr):
            print(i, sqr)
            total_sum += sqr

    print("Sum:", total_sum)


if __name__ == "__main__":
    main()
