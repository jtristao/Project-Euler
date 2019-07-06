/**************************************************************************
	Author: João V. Tristão
	Date: 06/07/2019
	Problem: Permuted multiples
	Approach: 
		- Check if x and 2*x, 3*x, 4*x, 5*x, 5*x have the same digits with the same quantity

**************************************************************************/

#include <bits/stdc++.h> 

#define SIZE 10

using namespace std;

int palindrome(string a, string b){
	if(a.size() != b.size())
		return false;

	int hist[SIZE];
	memset(hist, 0, SIZE*sizeof(int));

	for(int i = 0; i < (int)a.size(); i++){
		hist[(int)a[i]-'0']++;
	}

	for(int i = 0; i < (int)b.size(); i++){
		hist[(int)b[i]-'0']--;
	}

	for(int i = 0; i < SIZE; i++){
		if(hist[i] != 0)
			return false;
	}

	return true;
}

int main(int argc, char *argv[]){
	bool found = false;

	for(int i = 1; i < 1000000000 && found == false; i++){
		string a = to_string(i);
		string two = to_string(2*i);
		string three = to_string(3*i);
		string four = to_string(4*i);
		string five = to_string(5*i);
		string six = to_string(6*i);

		if(palindrome(a, two) && palindrome(a, three) && palindrome(a, four) && palindrome(a, five) && palindrome(a, six)){
			printf("%d %d %d %d %d %d\n", i, 2*i, 3*i, 4*i, 5*i, 6*i);
			found = true;
		}
	}


	return EXIT_SUCCESS;
}