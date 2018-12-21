/**************************************************************************
	Author: João V. Tristão
	Date: 23/07/2018
	Problem: 
	Approach:

**************************************************************************/

// How to find a recorrence in a string?

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check_decimals(int n){
	double k = 1000000000/(double)n;
	int hash[10] = {0};
	int len;
	char s[100];


	sprintf(s, "%.14lf", k);
	len = strlen(s);
	for(int i = 0; i < len; i++){
		hash[s[i]-48]++;
	}

	for(int i = 0; i < 10; i++)
		printf("%d %d\n", i, hash[i]);

	return 0;
}

int main(){
	int max;
	
	max = 7;
	check_decimals(max);
	// for(int i = 0; i < 1000; i++){
		// if(check_decimals(i) > max){
			// max = i;
		// }
	// }

	printf("Longest recurring cycle smaller than 1000 = %d\n", max);

	return EXIT_SUCCESS;
}