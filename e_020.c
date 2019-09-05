/**************************************************************************
	Author: João V. Tristão
	Date: 15/07/2018
	Problem: Find the sum of the digits of 100!.
	Approach:
		- Use https://www.calculator.net/big-number-calculator.html to calculate the number
		- Add the digits
	Usage:
		- $./a.out n

**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

enum{
	PROGNAME,
	NUMBER,
	NARGS
};

void prepare_string(char *dsty, char const *src) {
	int len = strlen(src);
	int j = 0;
	for(int i = 0; i < len; i++){
		if(src[i] != ','){
			dsty[j] = src[i];
			j++;
		}
	}
}

int main(int argc, char const *argv[]){
	if(argc != NARGS){
		printf("usage: %s number\n", argv[PROGNAME]);
		exit(0);
	}

	int len, sum;
	char *answer;

	answer = (char *)malloc(sizeof(char) * strlen(argv[NUMBER])); 
	prepare_string(answer, argv[NUMBER]);
	
	len = strlen(answer);
	sum = 0;
	for(int i = 0; i < len; i++){
		sum += (answer[i]-48);
	}
	
	printf("%d\n", sum);
}
