/**************************************************************************
	Author: João V. Tristão
	Date: 21/12/2018 
	Problem: Find all unique numbers in the form a^b, with 2 <= a,b <= 100
	Approach:
        - Calculate all numbers and insert in a set
        - Return the number os elements in the set

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unordered_set>

using namespace std;

enum{
	PROGNAME,
	N,
	NARGS	
};

int main(int argc, char *argv[]){
	unordered_set <double>s;
	int n;

	if(argc != NARGS){
		printf("usage %s: N\n", argv[PROGNAME]);
		exit(0);
	}	

	n = atoi(argv[N]);

	for(int i = 2; i <= n; i++){
		int count = 0;
		for(int j = 2; j <= n; j++){
			s.insert(pow(i, j));			
		}
	}

	printf("%ld\n", s.size());

	return EXIT_SUCCESS;
}