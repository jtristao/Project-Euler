/**************************************************************************
	Author: João V. Tristão
	Date: 26/12/2019
	Problem: Counting Rectangles
	Approach:
		- A rectangle is formed by two horizontal lines and two vertical lines.
		- Given a grid with M vertical lines and N horizontal lines, there are
		  (M+1 chopse 2) ways of picking a vertical line and (N+1 choose 2) ways of picking a horizontal line
		
**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
	int limit = 2000000;
	int n = 2000;
	int minimun = INT_MAX;
	int area;

	for(int x = 1; x < n; x++){
		for(int y = 1; y < n; y++){
			int n_rectangles = ((x+1)*x*(y+1)*y)/4;

			if(abs(n_rectangles - limit) < minimun){
				minimun = abs(n_rectangles-limit);
				area = x*y;
			}
		}
	}

	printf("Area : %d\n", area);

	return 0;
}