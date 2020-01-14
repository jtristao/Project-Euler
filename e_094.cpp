/**************************************************************************
	Author: João V. Tristão
	Date: 13/01/2020
	Problem: Almost equilateral triangles
	Approach:
		- All triangle have the format (a, a, b), where b = a +/- 1
		- The largest possible triangle is 3*k-1 = 1000000000, given the upper limit 333333333
		- Search all possible triangles chacking if the area is a integer
	Obs:
		- Got a lot of problems checking for larger numbers
		- Let s = sqrt(k), so s*s = int(k) only if k is a perfect number.
		- if k % 2 != 0, then (k/2)**2 is not a integer

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool integer_area(long i, long k){
	unsigned long long a = i*i;
	unsigned long long b = (k/2.0)*(k/2.0);

	unsigned long long temp = a-b;
	unsigned long long height = sqrt(temp);

	if(height*height == temp && k % 2 == 0)
		return true;
	else
		return false;

}

int main(int argc, char *argv[]){
	long limit = 1000000000;
	long upper_limit = (limit+1)/3+1;
	long long sum = 0;

	for(long i = 2; i <= upper_limit; i++){
		if(integer_area(i, i-1) == true)
			if(3*i-1 < limit)
				sum += 3*i-1;

		if(integer_area(i, i+1) == true)
			if(3*i-1 < limit)
				sum += 3*i+1;
	}

	printf("Sum : %lld\n",  sum);

	return 0;
}