/**************************************************************************
	Author: João V. Tristão
	Date: 05/02/2019
	Problem: Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
	Approach:
		- Use the eratosthenes_sieve to find the primes until an arbitrary N (hopefullt, is smaller than 2 billion)
		- Check truncability left and right

**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define N 100000000
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

bool left_truncate(int n){
	while(n > 10){
		n /= 10;
		if(primes[n] != PRIME)
			return false;
	}

	return true;
}

bool right_truncate(int n){
	int k = 1;
	int i = 1;
	
	while(n/10 > k){
		k = pow(10, i);
		if(primes[n%k] != PRIME)
			return false;
		i++;
	}

	return true;
}


int main(int argc, char *argv[]){
	long long sum = 0;
	int primes_found = 0;
	int i = 11;

	eratosthenes_sieve();

	while(primes_found != 11 || i != N-1){
		if(primes[i] == PRIME){
			if(left_truncate(i) == true && right_truncate(i) == true){
				primes_found++;
				sum += i;
				cout << i << endl;
			}
		}
		i++;
	}	

	cout << "Sum: " << sum << " (" << primes_found << ")" << endl;

	return EXIT_SUCCESS;
}