/*************************************************************************
	Author: João V. Tristão
	Date: 22/01/2018
	Objective: Find the largest prime factor of 600851475143
	Approach:
		-Start factor equal to the square root of 'number'
		-Make a simple test in order to ensure htat factor is odd
		-Check if it divisible by factor
			-if so, check if it prime
		-keep searching.

Note: In order to perform the primality test, a simple algorith is used.
Further explanation can be found on https://en.wikipedia.org/wiki/Primality_test.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER 600851475143
#define TRUE 1
#define FALSE 0

int check_prime(int n){
	int i;

	if(n <= 1)
		return FALSE;
	else if(n <= 3)
		return TRUE;
	else if(n % 2 == 0 || n % 3 == 0)
		return FALSE;
	i = 5;
	while(i*i <= n){
		if(n % i == 0 || n % (i+2) == 0)
			return FALSE;
		i += 6;
	}	
	
}
	
int main(){
	int factor;
	
	factor = sqrt(NUMBER);
	if(factor % 2 == 0) {
		if(NUMBER % factor == 0 && check_prime(factor)){
			printf("%d\n", factor);
			exit(0);
		}else
			factor--;
	}
	
	while(1){
		//if a divisor is found, check for primality
		if(NUMBER % factor == 0){
			if(check_prime(factor)){
				printf("%d\n", factor);
				exit(0);
			}
		}
		
		factor-=2;
	}
	
	return EXIT_SUCCESS;
}
