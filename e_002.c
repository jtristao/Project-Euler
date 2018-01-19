/**************************************************************************
	Author: João V. Tristão
	Date: 19/01/2017
	
	Ojective: Find the sum of every even fibonacci number smaller than 4000000.
	Approach: 
	    -Every third fibonacci number is even
	    -The golden ratio is also the ratio between every fibonacci number (works better on large number)
	    -Starting with 2, every even fibonacci number will be 'n * golen_ratio^3'
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CUBE_GOLDEN_RATIO 4.2360679775 

int main(){
	double sum;	
	double even_fibonacci;
	
	even_fibonacci = 2;
	while(even_fibonacci < 4000000){
		sum += even_fibonacci;
		even_fibonacci *= CUBE_GOLDEN_RATIO;
		even_fibonacci = round(even_fibonacci);
		//printf("%lf %.4lf\n", round(even_fibonacci), sum);
	}	
	
	printf("%.lf\n", sum);

	return EXIT_SUCCESS;
}
