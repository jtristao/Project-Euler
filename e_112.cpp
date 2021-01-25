/*************************************************************************
	Author: João V. Tristão
	Date: 12/10/2020
	Problem: Bouncy numbers
	Approach: 
		- Check all numbers until the desired proportion is found
*************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool check_bouncy(int n){
	string num = to_string(n);

	// increasing
	bool increasing = true;
	for(int i = 1; i < (int)num.size(); ++i){
		if(num[i] < num[i-1]){
			increasing = false;
			break;
		}
	}

	bool decreasing = true;
	for(int i = 1; i < (int)num.size(); ++i){
		if(num[i] > num[i-1]){
			decreasing = false;
			break;
		}
	}

	if(decreasing == false and increasing == false)
		return true;

	return false;

}

int main(int argc, char *argv[]){

	int bouncy = 0;
	int num = 99;

	while(100*bouncy <  99*num){
		if(check_bouncy(num)){
			bouncy++;
		}

		num++;
	}

	cout << "Solution:" << num << endl;

	return 0;
}