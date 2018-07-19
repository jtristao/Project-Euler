/**************************************************************************
	Author: João V. Tristão
	Date: 18/07/2018
	Problem: Find the "alphabetical" value off a unsorted file.
	Approach: 
		- Sort the file using quick sort
		- Multiply the string value by its index.
	Complexity:
		- Time O(nlogn)
		- Space O(1)

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Read the word betwen '"' and return it.
char *read_line(FILE *f){
	if(f == NULL) return FALSE;

	int i;
	char *s;

	i = 0;
	s = (char *)malloc(sizeof(char));
	char c = '"';
	while(c != ',' && c != EOF) {
		if(c != '"') {
			s = (char *)realloc(s, sizeof(char) * (i+2));
			s[i] = c;
			i++;
		}
		c = getc(f);
	}
	
	s[i] = '\0';

	return s;
}

// Iterate through the file and store all the names between '"'
int read_input(FILE *f, char ***names){
	if(f == NULL || names == NULL) return FALSE; 

	int i = 0;
	while(!feof(f)) {	
		*names = (char **)realloc(*names, sizeof(char *) * (i+1));
		if(((*names)[i] = read_line(f)) == FALSE) return FALSE;
		i++;
	}

	return i;
}

void swap(char **names, int i, int j) {
	char *aux = names[i];
	names[i] = names[j];
	names[j] = aux;
}

int partition(int left, int right, char **names) {
	int j = left;
	char *pivot = names[left];

	for(int i = left + 1; i <= right; i++) {
		if(strcmp(names[i], pivot) < 0) {
			j++;
			swap(names, i, j);
		}
	}

	swap(names, left, j);

	return j;
}

// Quick sort
int sort_names(int left, int right, char **names) {
	if(names == NULL) return FALSE;

	int mid;
	if(left < right){
		mid = partition(left, right, names);
		sort_names(left, mid-1, names);
		sort_names(mid+1, right, names);
	}

	return TRUE;
}

// Returns the "alphabetical" value of a word
int word_value(char *s) {
	int sum = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		sum += (s[i] - 64);

	return sum;	
}

int main(){
	FILE *file;
	long long sum;
	char **names;

	if((file = fopen("e_022.in", "r")) == NULL){
		printf("File not found.\n");
		exit(0);
	}	

	names = (char **)malloc(sizeof(char *));
	int size = read_input(file, &names);

	sort_names(0, size-1, names);

	sum = 0;
	for(int i = 0; i < size; i++) 
		sum = sum + word_value(names[i]) * (i+1);
	

	printf("SUM = %lld\n", sum);

	return EXIT_SUCCESS;
}