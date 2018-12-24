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

using namespace std;

#define MAGIC_NUMBER 6

int answer = 0;

/* Checks if a given string has the following property:
    4150 = 4^5 + 1^5 + 5^5 + 0^5 */
void check_fifth_power(string number){
	long long sum = 0;
	for(int i = 0; i < (int)number.length(); i++){
		sum += pow((number[i]-'0'), 5);
	}

	if(stoi(number) == sum){
		cout << sum << endl;
		answer += sum;
	}
}

/* Generate all numbers with 'i' digits */
void backtraking(string number, int i){	
	// base case
	if(i == 0){
		check_fifth_power(number);
	}else{
		for(int j = 0; j < 10; j++){
			// choose
			number.append(to_string(j));

			//explore
			backtraking(number, i-1);

			//unchoose
			number.erase(number.end()-1);
		}
	}
}

int main(int argc, char *argv[]){
	string s = "";
	backtraking(s, MAGIC_NUMBER);

	cout << "Sum : " << answer-1 << endl;

	return EXIT_SUCCESS;
}