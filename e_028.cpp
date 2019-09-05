/**************************************************************************
	Author: João V. Tristão
	Date: 23/07/2018
	Problem: 
	Approach:
		upper left diagonal: 1 ---- 7 ---- 21 ---- 43 ---- 73
	
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

enum{
	PROGNAME,
	DIM,
	NARGS	
};

int main(int argc, char *argv[]){
	if(argc != NARGS){
		printf("usage %s: DIMENSION\n", argv[PROGNAME]);
		exit(0);
	}	

	int dimension = atoi(argv[DIM]);
	long long sum = 0;
	int x = dimension/2;
	for(int i = 0; i <= x; i++){
		sum += 4*i*i + 2*i + 1; 	//upper left diagonal
		sum += 4*i*i + 1;			//lower left diagonal
		sum += 4*i*i + 4*i + 1;		//upper right diagonal
		sum += 4*i*i - 2*i + 1;		//lower right diagonal
	}

	printf("%lld\n", sum - 3);		//1 is added three extra times

	return 0;
}
