/**************************************************************************
	Author: João V. Tristão
	Date: 15/04/2019
	Problem: 42
	Approach: 
		- Create a set with the first N triangular numbers
		- Run through the file:
			- For every word
				- Find its value
				- Check if is a triangular number

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define N 20

int word_sum(const char *s, int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += s[i] - 'A' + 1;
	}

	return sum;
}

void find_triangular_numbers(set<int>& tn){
	for(int i = 1; i < N; i++){
		tn.insert(i*(i+1)/2);
	}
}

int main(int argc, char *argv[]){
	FILE *text;
	set<int> triangular_numbers;
	int count = 0;
	char word[100];

	text = fopen("p042_words.txt", "r");
	if(text == NULL){
		printf("Erro ao abrir o arquivo\n");
		exit(0);
	}

	find_triangular_numbers(triangular_numbers);

	int i = 0;
	while(!feof(text)){
		char c = fgetc(text);
		if(c != '"' && c != ',' && c != -1){
			word[i] = c;		
			i++;
		}
		if(c == ',' || c == -1){
			word[i] = '\0';
			int sum = word_sum(word, i);

			if(triangular_numbers.count(sum) == 1){
				count++;
				// printf("%s %d\t", word, sum);
			}
			i = 0;
		}
	}

	printf("Count = %d\n", count);

	return EXIT_SUCCESS;
}

// Ler uma palavra
// Obter sua soma
// Obter as raizes
// Se uma raiz for inteira
	//count++
// reptir ate o final do arquivo