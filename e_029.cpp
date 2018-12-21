/**************************************************************************
	Author: João V. Tristão
	Date: 
	Problem: 
	Approach:

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "InfInt.h"

enum{
	PROGNAME,
	N,
	NARGS	
};

int main(int argc, char *argv[]){
	int n;

	if(argc != NARGS){
		printf("usage %s: N\n", argv[PROGNAME]);
		exit(0);
	}	

	n = atoi(argv[N]);

	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++)
			printf("%8.lf\t", pow(i, j));
		printf("\n");
	}

	printf("a\n");

	return EXIT_SUCCESS;
}