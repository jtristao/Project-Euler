/**************************************************************************
	Author: João V. Tristão
	Date: 07/02/2018
	Problem: Find the first ten digits of the sum of one-hundred 50-digit.
	Approach:
		-Use a stack to store the numbers
	Usage:
		$gcc e_013.c stack.c
		$./a.out < e_013.in
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
	STACK *number_a, *number_b, *result;
	char n, flag;

	number_a = stack_init();
	number_b = stack_init();
	result = stack_init();	
	flag = 0;

	for(int i = 0; i < 50; i++){
		scanf("%c", &n);
		stack_push(number_b, n-48);
	}
	getchar();
	for(int j = 0; j < 99; j++){
		for(int i = 0; i < 50; i++){
			scanf("%c", &n);
			stack_push(number_a, n-48);
		}
		getchar();
		if(flag == 0){
			big_add(number_a, number_b, &result);
			stack_reset(number_b);
			flag = 1;
		}else{
			big_add(number_a, result, &number_b);
			stack_reset(result);
			flag = 0;
		}
	}	
	
	stack_print(result);

	return EXIT_SUCCESS;
}
