/**************************************************************************
	Author: João V. Tristão
	Date: 20/12/2019
	Problem: Su Doku
	Approach:
		- Backtrack to solve the board. (Reused an old implementation)

**************************************************************************/

#include <bits/stdc++.h>
#include "sudoku.h"

using namespace std;

#define N_GRIDS 50

int **get_grid(){
	int **grid;

	grid = (int **)malloc(sizeof(int *) * DIM);
	for(int i = 0; i < DIM; i++)
		grid[i] = (int *)malloc(sizeof(int) * DIM);

	string line;

	// Read grid header
	getline(cin, line);
	for(int i = 0; i < DIM; i++){
		getline(cin, line);
		for(int j = 0; j < DIM; j++){
			grid[i][j] = line[j] - '0';
		}
	}

	return grid;
}

void free_grid(int **grid){
	for(int i = 0; i < DIM; i++)
		free(grid[i]);
	free(grid);
}


int main(int argc, char *argv[]){
	int **board;
	int sum = 0;

	for(int i = 0; i < N_GRIDS; i++){
		board = get_grid();

		sum += sudoku_back_tracking(board, 0);

		free_grid(board);
	}

	cout << "Sum : " << sum << endl;

	return 0;
}