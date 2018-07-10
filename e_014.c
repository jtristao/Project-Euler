/**************************************************************************
	Author: João V. Tristão
	Date: 10/07/2018
	Problem: Find the longest collatz sequence starting under a million.
	Approach:
		- Try every number under a million.

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>

enum{
	VALUE,
	SIZE,
};

//for a given n, returns the size of its collatz sequence
int collatz(unsigned long long n){
	int i = 0;
	while(n != 1){
		if(n % 2 == 0)
			n /= 2;
		else
			n = 3*n + 1;
		i++;
	}
	
	return i;
}

int main(){
	unsigned long long max[2], n[2];

	max[VALUE] = 0;
	max[SIZE] = 0;

	for(int i = 1000000; i > 1; i--){
		n[VALUE] = i;
		n[SIZE] = collatz(i);
		
		if(n[SIZE] > max[SIZE]){
			max[VALUE] = n[VALUE];
			max[SIZE] = n[SIZE];	
		}
	}

	printf("%llu\t%llu\n", max[VALUE], max[SIZE]);


	return EXIT_SUCCESS;
}
