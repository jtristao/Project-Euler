/*************************************************************************
	Author: João V. Tristão
	Date: 28/10/2018
	Problem: Find the greatest product of four adjacent numbers in the same direction(up, dow, left, right, diagonally) in a 20x20 grid.
	Approach:
		-Try all the combinations and store the maximum
	Usage:
		$gcc e_011.c -o p7
		$./p7 < i_011.in
Note: Requires a file with the 20x20 grid.
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
	double sum_horizontal, sum_vertical, sum_diag_rig, sum_diag_lef, max_sum;
	int i, j, n, matrix[20][20];
	
	for(i = 0; i < 20; i++)
		for(j = 0; j < 20; j++){
			scanf("%d ", &n);
			matrix[i][j] = n;
		} 	

	max_sum = sum_horizontal = sum_vertical = sum_diag_rig = sum_diag_lef = 0;	
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			if(i <= 16)
				sum_horizontal = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
			if(j <= 16)
				sum_vertical = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];   
			if(i <= 16 && j <= 16)
				sum_diag_rig = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
			if(i <= 16 && j >= 3)
				sum_diag_lef = matrix[i][j] * matrix[i+1][j-1] * matrix[i+2][j-2] * matrix[i+3][j-3];		
			
			if(sum_horizontal > max_sum)
				max_sum = sum_horizontal;
			if(sum_vertical > max_sum)
				max_sum = sum_vertical;
			if(sum_diag_rig > max_sum)
				max_sum = sum_diag_rig;
			if(sum_diag_lef > max_sum)
				max_sum = sum_diag_lef;
		}
	}
	
	printf("%.lf\n", max_sum);

	return EXIT_SUCCESS;
}
