/*************************************************************************
	Author: João V. Tristão
	Date: 22/01/2018
	Objective: Find the largest prime factor of 600851475143
	Approach:
		-Uses the Project Euler's overview of the problem.
		-Similar to how it can be done manually.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main(){
	long long evil_number;
	long long last_factor, max_factor, factor;

	evil_number = 600851475143;
	if(evil_number % 2 == 0){
		last_factor = 2;
		evil_number /= 2;
		while(evil_number % 2 == 0)	
			evil_number /= 2;
	}else
		last_factor = 1;
	factor = 3;
	max_factor = sqrt(evil_number);
	while(evil_number > 1 && factor < max_factor){
		if(evil_number % factor == 0){
			evil_number /= factor;
			last_factor = factor;
			while(evil_number % factor == 0)
				evil_number /= factor;
		}
		factor += 2;
	}	
	if(evil_number == 1)
		printf("%ld\n", last_factor);
	else
		printf("%ld\n", evil_number);
	
	return EXIT_SUCCESS;
}
