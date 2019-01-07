/**************************************************************************
	Author: João V. Tristão
	Date: 24/12/2018
	Problem: Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
	Approach:
		- Generate all pandigital numbers
		- Check if they fit the rule.

**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>

using namespace std;

#define MAGIC_NUMBER 3

set<int>answer;

void check_pandigital(string number){
	int a, b, result;

	for(int i = 0; i < 7; i++){
		for(int j = 1; j < 8-i; j++){
			a = stoi(number.substr(0, i+1));
			b = stoi(number.substr(i+1, j));
			result = stoi(number.substr(j+i+1, number.length()));

			if(a*b == result){
				cout << a << " x " << b << " = " << result << endl;
				answer.insert(result);
			}
		}
	}
}

/* Generate all pandigital numbers by permuting the unchoosen string */
void backtraking(string number, string unchoosen){	
	// base case
	if(number.length() == 9){
		check_pandigital(number);
	}else{
		for(int j = 0; j < (int)unchoosen.length(); j++){
			// choose
			number.push_back(unchoosen[j]);
			unchoosen.erase(unchoosen.begin()+j);

			//explore
			backtraking(number, unchoosen);

			//unchoose
			unchoosen.insert(unchoosen.begin(), *(number.end()-1));
			number.erase(number.length()-1);
		}
	}
}

int main(int argc, char *argv[]){
	string number = "";
	string unchoosen = "123456789";
	long long sum = 0;

	backtraking(number, unchoosen);

	for(set<int>::iterator it = answer.begin(); it != answer.end(); it++){
		sum += *it;
	}

	cout << sum << endl;


	return EXIT_SUCCESS;
}