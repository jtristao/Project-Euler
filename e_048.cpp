/**************************************************************************
	Author: João V. Tristão
	Date: 22/05/2019
	Problem: Self Powers
	Approach: 
		Use only the last 10 digits of the powers and add they

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define N 1000

unsigned long long power(int k, int p, long long mod){
	unsigned long long sum = 1;
	for(int i = 0; i < p; i++){
		sum = (sum * k)%mod;
	}

	return sum;
}

int main(int argc, char *argv[]){
	unsigned long long sum = 0;
	for(int i = 1; i <= N; i++){
		sum += power(i, i, 100000000000);
		printf("%d %lld\n", i, sum);
	}

	printf("%lld\n", sum%10000000000);

	return EXIT_SUCCESS;
}