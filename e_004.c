/*************************************************************************
	Author: João V. Tristão
	Date: 23/01/2018
	Problem: Find the largest palindrome made from the product of two w3-digit numbers.
	Approach:
		-Basically, brute force
		-Starting with the larger combination(999*999), test all and output the largest.

*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int check_palindrome(int x){
	char number[7];
	snprintf(number, sizeof(number), "%d", x);
	for(int i = 0; i < 3; i++){
		if(number[i] != number[5-i])
			return FALSE;
	}
	
	return TRUE;
}

int main(){
	int n, max;
	
	max = 0;
	for(int i = 999; i > 100; i--){
		for(int j = 999; j > 100; j--){
			if(i*j < max)
				break;
			n = i * j;
			if(check_palindrome(n)){
				if(max < n)
					max = n;
			}
		}
	}
	printf("%d\n", max);

	return EXIT_SUCCESS;
}
