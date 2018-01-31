/*************************************************************************
	Author: João V. Tristão
	Date: 31/01/2018
	Problem: Find the first triangular number to hava more than 500 divisors.
	Approach: 
		-For every even number, test how many divisors it have.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_divisor(int n){
	int n_divisors, limit;
	
	n_divisors = 1;
	limit = sqrt(n);
	for(int i = 1; i < limit; i++)
		if(n % i == 0)
			n_divisors++;

	return n_divisors*2;		
}

int main(){
	int i, j, n;

	j = i =1;
	while(1){
		if(i % 2 == 0){
			n = check_divisor(i);
			printf("%d %d\n", i, n);
			if(n > 500)
				break;
		}	
		j++;
		i += j;
	}	

	printf("%d %d\n", i, n);
	
	return EXIT_SUCCESS;
}
