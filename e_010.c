/*************************************************************************
	Author: João V. Tristão	
	Date:27/01/2018 
	Problem:Find the sum of all prime number below two million.
	Approach:
		-Use the sieve of eratosthenes to create a vector with all prime numbers between 2000000 and then add then;

Notes:
	-Just re-used the program in 'Problem 7', with few changes.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 2000000

int main(){
	double sum;
	double *primes;
	
	sum = 0;
	primes = (double *)calloc(sizeof(double), LIMIT);
	for(int i = 2; i*i < LIMIT; i++){
		if(primes[i] == 0){
			for(int j = i*2; j <= LIMIT; j+= i)
				primes[j] = 1;
		}
	}	

	for(int i = 2; i <= LIMIT; i++)
		if(primes[i] == 0)
			sum += i;
	
	printf("%.lf\n", sum);

	return EXIT_SUCCESS;
}
