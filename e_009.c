/*************************************************************************
	Author: João V. Tristão
	Date: 27/01/2018
	Problem: Find the product of the pythagorean triplet wich sum equals 1000.
	Approach:
		-Brute force: try every all the combinations and stop with the first that appears.

Note: It's guarateed that there's only one answer.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int k;
	for(int i = 1; i < 1000; i++)
		for(int j = i + 1; j < 1000; j++){
			k = 1000 - i - j;
			if(i*i + j*j == k*k){
				printf("%d\n", i*j*k);
				exit(0);
			}
		}


	return EXIT_SUCCESS;
}
