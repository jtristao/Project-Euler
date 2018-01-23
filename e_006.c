/*************************************************************************
	Author: João V. Tristão
	Date: 23/01/2018
	Problem: Find the differeance between the sum of the squares of the first one hundred natural nubers and the square sum;
	Approach:
		-Using a simple example, with only 3 numbers:
			(a + b + c)^2 - (a^2 + b^2 + c^2) =
		 	a^2 + b^2 + c^2 + 2*a*b + 2*a*c + 2*b*c - a^2 - b^2 - c^2 =
			2*a*b + 2*a*c + 2*b*c =
			2(A*b + a*c + b*c)

		-Add all the combinations of products of the 100 first numbers
		-Multiply by two.
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

int main(){
	int sum;
	
	sum = 0;
	for(int i = 1; i <= LIMIT; i++)
		for(int j = i+1; j <= LIMIT; j++)
			sum += i*j;
	printf("%d\n", 2*sum); 

	return EXIT_SUCCESS;
}
