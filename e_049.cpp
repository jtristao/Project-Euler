/**************************************************************************
	Author: João V. Tristão
	Date: 31/05/2019
	Problem: Prime permutations
	Approach:
		- Find all primes below 10000
		- Starting in a arbitrary number within the range [1000; 10000] (All 4-digits numbers)
		- For all possible arithmetic sequences with 3 numbers ( the largest increment is 4500 -> 1000, 5500, 10000)
			- if the three numbers are prime
				- if they are permutations
					- append answer
	Complexity:
		O(number_of_possible_begins * number_of_possible_increments * check_if_prime * check_if_permutation)
		O(9000*4500*1*4)
**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define N 100000
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

bool check_permutation(int a, int b){
	string n_a = to_string(a); 
	string n_b = to_string(b); 
	unordered_map<char, int> m;

	for(int i = 0; i < (int)n_a.size(); i++)
		m[n_a[i]]++;

	for(int i = 0; i < (int)n_a.size(); i++)
		m[n_b[i]]--;

	for(auto i:m){
		if(i.second != 0)
			return false;
	}

	return true;
}


int main(int argc, char *argv[]){
	eratosthenes_sieve();
	string answer;

	for(int i = 1000; i < 10000; i++){
		for(int j = 1; j <= 4500; j++){
			if(primes[i] == PRIME && primes[i+j] == PRIME && primes[i+2*j] == PRIME){
				if(check_permutation(i, i+j) == true && check_permutation(i+j, i+2*j)){
					if(i != 1487){
						answer.append(to_string(i));
						answer.append(to_string(i+j));
						answer.append(to_string(i+2*j));
					}
				}
			}
		}
	}	

	cout << answer << endl;


	return EXIT_SUCCESS;
}