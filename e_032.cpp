/**************************************************************************
	Author: João V. Tristão
	Date: 24/12/2018
	Problem: Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
	Approach:
		- Generate all numbers with until 6 digits
		- Check if they fit the rule.
Obs: 
	Why 6? -> Number of digits | Maximum value
					1                  9^5 = 59049
					2                2*9^5 = 118.098
					3                3*9^5 = 177.147
					4                4*9^5 = 236.196
					5                5*9^5 = 295.245
					6                6*9^5 = 354.294
					7                7*9^5 = 413.343
	After six, its impossible to reach all numbers with 7 digits.
	Even though, it was checked until 10 digits.(Took a while)

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
	// cout << number << endl;
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

/* Generate all numbers with 'i' digits */
void backtraking(string number, string unchoosen){	
	// cout << number << "---" << unchoosen << endl;
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