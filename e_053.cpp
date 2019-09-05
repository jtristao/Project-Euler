/**************************************************************************
	Author: João V. Tristão
	Date: 08/07/2019
	Problem: Combinatoric selections
	Approach:
		- start generating the pascal triangle until reaching the first 1000000 value and storing its position
		after that, every line will be generated until the last position.

			The idea its that given the first number in a line that is bigger than LIM and the number of the line, due to properties
		in the Pascal triangle, it's possible to calculate the number of values greater than LIM.
			The algorithm just keep track of the first occurance of LIM in every line. It stops the line calculation when a number greater
		than LIM is found. It avoids overflow by tracking just values smaller or slightly higher than LIM.

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define LIM 1000000
#define H 100

int pascal[H][H];

int distance(int line, int begin){
	return (line+1) - begin*2;
}

int main(int argc, char *argv[]){
	int count = 0;
	int end = 10;
	pascal[0][0] = 1;

	for(int i = 1; i <= H; i++){
		for(int j = 0; j <= i && j <= end; j++){
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
			
			if(pascal[i][j] > N){
				end = j;
				count += distance(i, end);
				break;
			}
		}
	}

	printf("%d\n", count);

	return EXIT_SUCCESS;
}