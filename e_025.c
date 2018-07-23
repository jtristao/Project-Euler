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

int main(){
	STACK *a, *b, *fib;

	fib = init_stack();
	a = init_stack();
	b = init_stack();

	stack_push(fib, 0);
	stack_push(a, 1);
	stack_push(b, 1);

	stack_print(fib);
	stack_print(a);
	stack_print(b);
	/*for(int i = 0; i < 100; i++){
		printf("%.0lf\n", fib);
		fib = a+b;
		a = b;
		b = fib;
		if(check_fib(fib) == 1) break;
	}*/

	printf("Fibonacci with more than 1000 digits = %d\n", fib);

	return EXIT_SUCCESS;
}