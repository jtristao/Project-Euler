# **************************************************************************
#
# 	Author: João V. Tristão
# 	Date: 25/01/2021
# 	Problem: Prime generating integers
# 	Approach:
# 		- Clever Brute force:
#           - Break when a divisor is invalid
#           - Check only half of the divisors (The operarion d+n/d yields simetric results)
#
# **************************************************************************

import primesieve


def main():
    limit = 100000000
    total_sum = 0

    primes = set(primesieve.primes(limit + 1))

    for num in range(1, limit):

        # Find divisors
        div_are_prime = True
        div_limit = int(num ** 0.5) + 1
        for i in range(1, div_limit):
            if num % i == 0:
                if i + num / i not in primes:
                    div_are_prime = False
                    break

        if div_are_prime:
            total_sum += num

    print("Total sum:", total_sum)


if __name__ == "__main__":
    main()