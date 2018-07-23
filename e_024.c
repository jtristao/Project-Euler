/**************************************************************************
	Author: João V. Tristão
	Date: 20/07/2018
	Problem: Find the 1000000th(sorted) permutation of 0~9.
	Approach:
		- Find all the permutations in ascending order
	Complexity:
		- Time (10! * 10^2)
		- Space O(1)

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEN 3628800
#define N 10

int check_string(char *s){
	for(int i = 0; i < N-1; i++){
		for(int j = i+1; j < N; j++)
			if(s[i] == s[j])
				return 0;
	}

	return 1;
}

int main(){
	char factorial[11];
	int x = 0;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				for(int l = 0; l < N; l++) {
					for(int m = 0; m < N; m++) {
						for(int n = 0; n < N; n++) {
							for(int o = 0; o < N; o++) {
								for(int p = 0; p < N; p++) {
									for(int q = 0; q < N; q++) {
										for(int r = 0; r < N; r++) {
											factorial[0] = i+48;
											factorial[1] = j+48;
											factorial[2] = k+48;
											factorial[3] = l+48;
											factorial[4] = m+48;
											factorial[5] = n+48;
											factorial[6] = o+48;
											factorial[7] = p+48;
											factorial[8] = q+48;
											factorial[9] = r+48;
											factorial[10] = '\0';
											
											if(check_string(factorial) == 1)	x++;

											if(x == 1000000){
												printf("%s\n", factorial);
												exit(0);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}



	return EXIT_SUCCESS;
}