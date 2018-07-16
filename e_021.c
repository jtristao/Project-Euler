/*************************************************************************
	Author: João V. Tristão
	Date: 31/01/2018
	Problem: Find the sum of all amicable numbers below 10000.
	Approach: 
		- Create a list with all of the sums of the divisors.
		- Check for a match.
	Compltexity:
		- time  -> O(n.sqrt(n))
		- space -> O(n)
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 10000

int find_sum_divisors(int n) {
	int sum = 1;
	int limit = sqrt(n);
	for(int i = 2; i <= limit; i++) {
		if(n % i == 0) {
			if(i != n/i){
				sum += n/i;
			}
			sum += i;
		} 
	}

	return sum;
}

int main(){
	long long sum;
	int *table;

	// Generate table with all the sums
	table = (int *)malloc(sizeof(int) * LIMIT);
	for(int i = 0; i < LIMIT; i++) {
		table[i] = find_sum_divisors(i);
	}

	// Check for the pairs
	sum = 0;
	for(int i = 0; i < LIMIT; i++) {
		int j = table[i];
		if(j < LIMIT && i == table[j] && i != j){
			sum = sum + j;
		}
	}

	printf("SUM = %lld\n", sum);

	return EXIT_SUCCESS;
}