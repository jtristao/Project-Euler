/*************************************************************************
	Author: João V. Tristão	
	Date: 24/02/2018
	Problem: Find the 10001th Prime
	Approach:
		-Create a big list with primes using sieve of ertosthenes wihtin  a certain limit.
		-Check for the 10001th.
Notes:Not a exactly a goo program:
	- calculates a lot of unnecessary primes
	- you need to manually adjust LIMIT in order to find another prime.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 110000

int main(){
	int k;
	double *primes;
	
	primes = (double *)calloc(sizeof(double), LIMIT);
	for(int i = 2; i*i < LIMIT; i++){
		if(primes[i] == 0){
			for(int j = i*2; j <= LIMIT; j+= i)
				primes[j] = 1;
		}
	}	

	k = 0;
	for(int i = 2; i <= LIMIT; i++)
		if(primes[i] == 0){
			printf("%d %d\n", i, k);
			k++;
		}

	return EXIT_SUCCESS;
}
