/**************************************************************************
	Author: João V. Tristão
	Date: 19/02/2018
	Problem: 
	Approach:

**************************************************************************/

#include <bits/stdc++.h>

#define LIMIT 28123

bool check_abundant(int n){
	int sum = 0;
	int limit = sqrt(n);
	for(int i = 2; i <= limit; i++) {
		if(n % i == 0) {
			if(i != n/i){
				sum += n/i;
			}
			sum += i;
		} 
	}

	return (sum > n) ? true : false;
}

int main(){
	int *abundant, *addition;
	int sum;

	// creates a list with all abundant numbers
	// might be optimized by inserting the multiples of a number
	abundant = (int *)calloc(LIMIT+1, sizeof(int));
	int j = 0;
	for(int i = 0; i <= LIMIT; i++) {
		if(check_abundant(i) == true){
			abundant[i] = i;
			j++;
		}
	}

	addition = (int *)calloc(LIMIT+1, sizeof(int));
	for(int i = 0; i <= LIMIT-1; i++){
		for(int j = 0; j <= LIMIT; j++){
			int k = abundant[i] + abundant[j];
			if(k > LIMIT) break;

			if(abundant[i] != 0 && abundant[j] != 0)
				addition[k] = 1;
		}
	}

	sum = 0;
	for(int i = 1; i < LIMIT; i++){
		if(addition[i] == 0){
			// printf("%d\t", i);
			sum += i;
		}
	}

	printf("\nSUM = %d\n", sum);

	return EXIT_SUCCESS;
}