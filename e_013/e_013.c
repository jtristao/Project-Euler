#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
	STACK *number_a, *number_b, *result;
	char n;

	number_a = stack_init();
	number_b = stack_init();
	result = stack_init();	

	for(int j = 0; j < 1; j++){
		for(int i = 0; i < 50; i++){
			scanf("%c", &n);
			stack_push(number_a, n-48);
		}
		getchar();
		for(int i = 0; i < 50; i++){
			scanf("%c", &n);
			stack_push(number_b, n-48);
		}
		big_add(number_a, number_b, &result);
	}	
	
	stack_print(result);
		
	return EXIT_SUCCESS;
}
