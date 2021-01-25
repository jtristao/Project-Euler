/*************************************************************************
	Author: João V. Tristão
	Date: 13/10/2020
	Problem: How many reversible numbers are there below one-billion?
	Approach: 
		- Check all numbers below 1 billion
	Obs:
		It took about 6min to run
*************************************************************************/


#include <bits/stdc++.h>

using namespace std;

bool reversible(int n){
	string num = to_string(n);
	string reversed = num;
	
	reverse(reversed.begin(), reversed.end());
	int n_reversed = stoi(reversed);

	int sum = n + n_reversed;
	string sum_str = to_string(sum);

	for(char c:sum_str){
		if(c % 2 == 0)
			return false;
	}

	if(num[0] == '0' || num[num.size()-1] == '0')
		return false;

	return true;
}

int main(int argc, char *argv[]){
	int cnt = 0;

	for(int i = 0; i <= 1000000000; ++i){
		if(reversible(i)){
			cnt++;
		}
		if(i%10000000 == 0)
			cout << i/10000000 << "%" << endl;
	}

	cout << "Reversible below one billion: " << cnt << endl;

	return 0;
}