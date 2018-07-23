/**************************************************************************
	Author: João V. Tristão
	Date: 20/07/1998
	Problem: 
	Approach:

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stack.h"

int check_fibonacci(STACK *fib) {
	return (stack_total(fib) > 1000) ? 1 : 0;
}

int main(){
	STACK *a, *b, *fib;
	int i;

	fib = stack_init();
	a = stack_init();
	b = stack_init();

	stack_push(a, 1);
	stack_push(b, 1);

	i = 2;
	while(check_fibonacci(fib) == 0) {
		big_add(a, b, &fib);
		stack_copy(a, b);
		stack_copy(b, fib);

		i++;

		stack_print(fib);
	}

	printf("Fibonacci[%d] with more than 1000 digits = ", i);
	stack_print(fib);

	stack_free(a);
	stack_free(b);
	stack_free(fib);

	return EXIT_SUCCESS;
}