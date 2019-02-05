/**************************************************************************
	Author: João V. Tristão
	Date: 05/02/2019
	Problem: Find the perimeter p <= 1000, with the largest number of pythagorean triplets(a*a + b*b = c*c; a+b+c = p)	
	Approach:
		- Find all Pythagorean triplets smaller than 1000
		- Use a set to add the sum
		- Find the largest

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char *argv[]){
	int n[1001];
	memset(n, 0, sizeof(int)*1001);

	for(int i = 1; i < 1000; i++){
		for(int j = i+1; j < 1000; j++){
			int k = sqrt(i*i + j*j);
			if(i*i + j*j == k*k){ // Valid triplet
				if(i+j+k < 1000)
					n[i+j+k]++;
			}
		}
	}

	int max = 0;
	int max_index = 0;
	for(int i = 0; i <= 1000; i++){
		if(n[i] > max){
			max = n[i];
			max_index = i;
		}
	}

	cout << max_index << " " << max << endl;

	return EXIT_SUCCESS;
}