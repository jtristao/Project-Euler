/**************************************************************************
	Author: João V. Tristão
	Date: 08/01/2019
	Problem: How many circular primes are there below one million?
	Approach:
		- Use sieve to find all primes
		- Check if they are circular

**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define N 1000000
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

bool check_circular_prime(int k){
	string number = to_string(k);

	for(int i = 0; i < number.size(); i++){
		number.push_back(number[0]);
		number.erase(number.begin());

		if(primes[stoi(number)] == NOT_PRIME)
			return false;
	}

	return true;
}


int main(int argc, char *argv[]){
	eratosthenes_sieve();

	long long counter = 0;
	for(int i = 0; i < N; i++){
		if(primes[i] == PRIME && check_circular_prime(i) == true){
			cout << i << endl;
			counter++;
		}
	}


	cout<< "Number of circular primes: " << counter << endl;

	return EXIT_SUCCESS;
}