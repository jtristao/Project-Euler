/**************************************************************************
	Author: João V. Tristão
	Date:
	Problem:
	Approach:

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

bool is_palindrome(string s){
	int half_length = s.length()/2;
	for(int i = 0; i < half_length; i++){
		if(s[i] != s[s.length()-i-1])
			return false;
	}

	return true;
}

string convert_to_binary(int n){
	string binary = "";
	while(n > 0){
		binary.append(to_string(n%2));
		n /= 2;
	}

	reverse(binary.begin(), binary.end());

	return binary;
} 

int main(int argc, char *argv[]){
	long long sum = 0;

	for(int i = 0; i < 1000000; i++){
		if(is_palindrome(to_string(i)) && is_palindrome(convert_to_binary(i))){
			cout << i << endl;
			sum += i;
		}
	}

	cout << "Sum: " << sum << endl;

	return EXIT_SUCCESS;
}