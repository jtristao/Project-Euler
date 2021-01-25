/**************************************************************************
	Author: João V. Tristão
	Date: 05/10/2019
	Problem: Prime pair sets
	Approach: 
		- Find all possible Triplets within a certain range
		- Find all possible pairs within a certain range
		- Check all the matches triplets X pair:
			The first one is the smallest
			Print the sum
		

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define LIMIT 9000
#define RANGE 100000000

vector<bool> primes(RANGE, true);
vector<int> prime;

void sieve(){
	primes[0] = false;
	primes[1] = false;

	for(int i = 2; i*i <= RANGE; i++){
		int j = i*i;
		while(j <= RANGE){
			primes[j] = false;
			j += i;
		}
	}

	for(int i = 0; i < LIMIT; i++){
		if(primes[i] == true)
			prime.push_back(i);
	}
}

bool pair_test(int a, int b){
	string temp1 = to_string(a);
	string temp2 = to_string(b);
	int aux1 = stoi(temp1+temp2);
	int aux2 = stoi(temp2+temp1);

	if(primes[aux1] == false || primes[aux2] == false)
		return false;

	return true;
}

bool tuple_test(vector<int> tuple){
	if(tuple.size() != 5)
		return false;
	else{
		if(pair_test(tuple[0], tuple[3]) == true && pair_test(tuple[0], tuple[4]) == true &&
			pair_test(tuple[1], tuple[3]) == true && pair_test(tuple[1], tuple[4]) == true &&
			 pair_test(tuple[2], tuple[3]) == true && pair_test(tuple[2], tuple[4]) == true)
				return true;
		else
			return false;
	}
}

bool triplet_test(int a, int b, int c){
	if(pair_test(a, b) == true && pair_test(a, c) == true && pair_test(b, c) == true)
		return true;
	else
		return false;
}

int main(int argc, char *argv[]){
	cout << "Finding primes..." << endl;
	sieve();

	cout << "Finding Triplets..." << endl;
	vector<vector<int>> triplets;
	for(vector<int>::iterator i = prime.begin(); i != prime.end(); i++){
		for(vector<int>::iterator j = i+1; j != prime.end(); j++){
			for(vector<int>::iterator k = j+1; k != prime.end(); k++){
				if(triplet_test(*i, *j, *k) == true){
					triplets.push_back({*i, *j, *k});
					// cout << *i << " " << *j << " "  << *k << endl;
				}
			}
		}
	}

	cout << "Finding Pairs..." << endl;
	vector<pair<int, int>> pairs;
	for(vector<int>::iterator i = prime.begin(); i != prime.end(); i++){
		for(vector<int>::iterator j = i+1; j != prime.end(); j++){
			if(pair_test(*i, *j) == true){
				pairs.push_back({*i, *j});
			}
		}
	}

	printf("Checking matches...(%ld)(%ld)\n", triplets.size(), pairs.size());
	for(auto i : triplets){
		for(vector<pair<int, int>>::iterator j = pairs.begin(); j != pairs.end(); j++){
			vector<int> aux;
			if(i[0] != j->first && i[1] != j->first && i[2] != j->first){
				aux.push_back(i[0]);
				aux.push_back(i[1]);
				aux.push_back(i[2]);
				aux.push_back(j->first);
				aux.push_back(j->second);
				if(tuple_test(aux) == true){
					cout << i[0] << " " << i[1] << i[2] << j->first << j->second << endl;
					cout << i[0] + i[1] + i[2] + j->first + j->second;
					exit(0);
				}
			}
			aux.clear();
		}
	}


	return EXIT_SUCCESS;
}