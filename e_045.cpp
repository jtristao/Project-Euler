/**************************************************************************
	Author: João V. Tristão
	Date: 18/04/2019
	Problem: Triangular, pentagonal, and hexagonal (https://projecteuler.net/problem=45)
	Approach:
		- Try a lot of different things
	 	- Give up
	 	- Search for help

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

bool is_pentagonal(unsigned long long int n){
	double x = (1 + sqrt(1+24*n))/6.0;
	if(ceil(x) == floor(x))
		return true;

	return false;
}

int main(int argc, char *argv[]){
	int i = 144;
	while(1){
		unsigned long long int k = (i*(2*i-1));
		if(is_pentagonal(k)){
			printf("%lld\n", k);
			exit(0);
		}
		i++;
	}


	return EXIT_SUCCESS;
}