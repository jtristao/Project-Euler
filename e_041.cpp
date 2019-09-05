/**************************************************************************
	Author: João V. Tristão
	Date: 16/04/2019
	Problem: Pandigital Prime (https://projecteuler.net/problem=41)
	Approach:
		- Find all primes in a certain range
		- Start with the largest prime to the smallest
			- If its a pandigital, stop

	How large the range must be?
		It can't be larger than 9 digits, since it's a pandigital number
		theres no need to search for:
			9 digits : 1+2+3+4+5+6+7+8+9 = 45 wich is divisible by 3 -> there's no pandigital prime with 9 digits
			8 digits : 1+2+3+4+5+6+7+8 = 36 wich is divisible by 3 -> there's no pandigital prime with 8 digits
			7 digits : 1+2+3+4+5+6+7 = 28 -> nice

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define N 9999999
#define NOT_PRIME true
#define PRIME false

bool primes[N+1];

void eratosthenes_sieve(){
	int limit = floor(sqrt(N));
	
	primes[0] = NOT_PRIME;
	primes[1] = NOT_PRIME;

	for(int i = 2; i < limit; i++){
		if(primes[i] == PRIME){
			for(int j = i*i; j < N; j+=i)
				primes[j] = NOT_PRIME;
		}
	}
}

bool verify_pan_digital(string s){ 
	vector<int> histogram(s.size(), 0); 
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] > '0' && (s[i]-'0') <= (int)s.size())
			histogram[s[i]-'1']++; 
	}

	for(int i = 0; i < (int)s.size(); i++){
		if(histogram[i] != 1)
			return false;
	}

	return true;
}

int main(int argc, char *argv[]){
	eratosthenes_sieve();
	for(long long i = N-1; i > 0; i--){
		if(primes[i] == PRIME && verify_pan_digital(to_string(i))){
			cout << i << endl;
			exit(0);
		}
	}


	return EXIT_SUCCESS;
}