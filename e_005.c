/*************************************************************************
	Author: João V. Tristão
	Date: 23/02/2018
	Problem: Find the smallest positve number that is evenly divisible by all of number from 1 to 20.
	Approach: 
		-LCM(x,y) = x * y/ GCD(x,y)
		-Since the LCM is commutative, it can be applied to a collection of numbers.

*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(long long answer, int i){
	long long remainder;
	
	remainder = answer % i;
	if(remainder == 0)
		return i;
	
	return gcd(i, remainder);
}

int main(){
	long long answer;

	answer = 1;
	for(int i = 1; i <= 20; i++){
		answer = (answer * i)/gcd(answer, i);
	}	

	printf("%lld", answer);

	return EXIT_SUCCESS;
}
