/**************************************************************************
	Author: João V. Tristão
	Date: 17/04/2019
	Problem: Pentagonal Numbers (https://projecteuler.net/problem=44)
	Approach:
		- Find pentagonal numbers within a arbitrary range
		- Verify if the sum and the difference would make a match

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define N 10000

void find_pentagonal_numbers(set<int>& p){
	for(int i = 1; i < N; i++){
		p.insert((i*(3*i-1))/2);
	}
}

int main(int argc, char *argv[]){
	set<int> pentagonal;
	find_pentagonal_numbers(pentagonal);

	int k;
	int d;
	for(set<int>::iterator i = pentagonal.begin(); i != pentagonal.end(); i++){
		for(set<int>::iterator j = pentagonal.begin(); j != pentagonal.end(); j++){
			k = *i + *j;
			d = abs(*j - *i);
			if(pentagonal.count(k) == 1 && pentagonal.count(d) == 1){
				printf("%d + %d = %d\n", *i, *j, k);
				printf("%d - %d = %d\n", *i, *j, d);
			}
		}
	}

	return EXIT_SUCCESS;
}