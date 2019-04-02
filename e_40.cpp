/**************************************************************************
	Author: João V. Tristão
	Date: 02/04/2019
	Problem: https://projecteuler.net/problem=40
	Approach:
		- Create a partial string with 100 digits
		- While creating, search for the right positions and multiply their values 

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define N 1000000

int main(int argc, char *argv[]){
	long long sum = 1;
	int limit = 100;
	int pos = 1;
	int div = 1;
	string s;
	string k;

	for(int i = 1; i < N; i++){
		k = to_string(i);
		pos += k.size(); 
		s += k;

		if(pos > div){
			sum *= (s[div-1]-'0');
			div *= 10;
		}

		if((int)s.size() == limit){
			s.clear();
		}
	}

	cout << sum << endl;


	return EXIT_SUCCESS;
}