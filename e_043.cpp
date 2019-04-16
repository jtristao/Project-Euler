/**************************************************************************
	Author: João V. Tristão
	Date: 16/04/2019
	Problem: Sub-string divisibility (https://projecteuler.net/problem=43)
	Approach:
		- Find all pan_digital
		- Check if they fit the property

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

vector<string> pan_digital;

void generate_pan_digital(string chosed, string avaible){
	if(avaible.size() == 0 && chosed[0] != '0'){
		pan_digital.push_back(chosed);
	}else{
		for(int i = 0; i < (int)avaible.size(); i++){
			chosed.push_back(avaible[i]);
			avaible.erase(avaible.begin()+i);

			generate_pan_digital(chosed, avaible);

			avaible.insert(i, 1, chosed.back());
			chosed.pop_back();
		}
	}
}

bool test_property(string s){
	vector<int> primes = {2, 3, 5, 7, 11, 13, 17};

	for(int i = 1; i < 8; i++){
		string aux;
		for(int j = 0; j < 3; j++)
			aux.push_back(s[i+j]);
		int k = stoi(aux);
		if(k % primes[i-1] != 0)
			return false;
	}

	return true;
}

int main(int argc, char *argv[]){
	long long sum = 0;
	generate_pan_digital("", "0123456789");
	
	for(int i = 0; i < (int)pan_digital.size(); i++){		
		if(test_property(pan_digital[i])){
			cout << pan_digital[i] << endl;
			sum += stoll(pan_digital[i]);
		}
	}

	cout << "Sum = " << sum << endl;

	return EXIT_SUCCESS;
}