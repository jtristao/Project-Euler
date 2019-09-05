/****************************************
 *	João Vitor S. Tristão
 *	05/01/2017
 *	Sum of Multiples of two numbers within a superior limit
*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum{
	PROGNAME,
	A,
	B,
	LIMIT,
	NARGS	
};

float finite_sum(int a, int limit){
	int last, n;
 	float venn;

       	n = (limit-1)/a; 
        last = n*a;
	venn = (a + last)*n/2.0;

	return venn;
}

int main(int argc, char *argv[]){
	int a, b, limit;
	float vennA, vennB, intersection;

	if(argc != NARGS){
		printf("usage %s: A B LIMIT\n", argv[PROGNAME]);
		exit(0);
	}	
	
	a = atoi(argv[A]);
	b = atoi(argv[B]);
	limit  = atoi(argv[LIMIT]);

	vennA = finite_sum(a, limit);
	vennB = finite_sum(b, limit);
	intersection = finite_sum(a*b, limit);

	printf("Result = %.f\n", vennA + vennB - intersection);
	return EXIT_SUCCESS;
}
