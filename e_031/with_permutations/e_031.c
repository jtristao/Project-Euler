/**************************************************************************
	Author: João V. Tristão
	Date: 
	Problem: 
	Approach:

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VALUE 200

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; 
double memo[VALUE+1];
int count = 0;

double coin_sum(int remain){
	int sub_total = 0;
	if(remain == 0){
		count++;
		return 1;
	}
	if(remain > 0){
		if(memo[remain] != -1){
			count++;
			return memo[remain];
		}
		else {
			for(int i = 0; i < 8; i++){
				sub_total += coin_sum(remain - coins[i]);
			}
			memo[remain] = sub_total;
		}
	}

	return sub_total;
}

int main(int argc, char *argv[]){
	for(int i = 0; i <= VALUE; i++)
		memo[i] = -1;
	
	coin_sum(VALUE);

	for(int i = 0; i <= VALUE; i++)
		printf("%d  %lf\n", i, memo[i]);

	printf("%d\n", count);

	return EXIT_SUCCESS;
}