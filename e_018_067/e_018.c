/**************************************************************************
	Author: João V. Tristão
	Date: 12/07/2018
	Problem: Find the maximum total from top to bottom of a given triangle.
	Approach:
		- Add every row to its row below chosing the largest parent.
	Complexity:
		time = O(n)
		memory = O(1)

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

enum{
	PROGNAME,
	HEIGHT,
	NARGS
};

int main(int argc, char const *argv[]){
	
	if(argc != NARGS){
		printf("usage: %s height of the triangle\n", argv[PROGNAME]);
		exit(0);
	}

	int **triangle;
	int height;

	//allocate the triangle
	height = atoi(argv[HEIGHT]);
	triangle = (int **)malloc(sizeof(int *) * height);
	for(int i = 0; i < height; i++) {
		triangle[i] = (int *)malloc(sizeof(int) * (i+1));
	}

	//read the input
	for(int i = 0; i < height; i++) {
		for(int j = 0 ; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}
	
	//go through the triangle adding the lines with the largest parent
	for(int i = 1; i < height; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == 0) { //the first element of the row has only one parent
				triangle[i][j] += triangle[i-1][j];
			} else if(j == i) { //the last element of the row has only one parent
				triangle[i][j] += triangle[i-1][j-1];
			} else {
				if(triangle[i-1][j-1] > triangle[i-1][j]) { //check which parent(left or right) is larger
					triangle[i][j] += triangle[i-1][j-1];
				} else {
					triangle[i][j] += triangle[i-1][j];
				}
			}
		}
	}

	//the last line holds all some of the possible largest paths
	//the largest one is the desired one
	int max = INT_MIN;
	for(int i = 0; i < height; i++) {
		if(triangle[height-1][i] > max){
			max = triangle[height-1][i];
		}
	}

	printf("Maximum = %d\n", max);

	return EXIT_SUCCESS;
}