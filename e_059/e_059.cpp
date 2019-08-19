/**************************************************************************
	Author: João V. Tristão
	Date: 19/08/2019
	Problem: XOR decryption
	Approach: 
		- Trial all possible keys, checking if they form the word 'the'.
		- Store the possible keys
		- Decrypt the text with all possible keys (The file output keep the keys and text)
		- Find the text that makes sense
		- Add all the letters values

	ps:
		the commented lines are running all the possible keys
**************************************************************************/


#include<bits/stdc++.h>

using namespace std;

typedef struct{
	int a, b, c;
} Secret;

int main(int argc, char const *argv[]){
	FILE *data = fopen("s_059.txt", "r");
	vector<int> letters;

	char aux;
	char temp[3];
	int integer = 0;
	int i = 0;	
	while(!feof(data)){
		fread(&aux, sizeof(char), 1, data);
		if(aux == ','){
			for(int j = 0; j < i; j++){
				integer += (temp[i-j-1]-'0')*pow(10,j);
			}
			letters.push_back(integer);
			integer = 0;
			i = 0;
		}else{
			temp[i] = aux;
			i++;
		}
	}

	letters.push_back(94);

	// int counter = 0;
	// vector<Secret> keys;
	// // Para cada letra no texto
	// for(int l = 0; l < (int)letters.size(); l++){
		
	// 	for(int i = 97; i <= 122; i++){
		
	// 		for(int j = 97; j <= 122; j++){
		
	// 			for(int k = 97; k <= 122; k++){
	// 				int a, b, c;
	// 				a = letters[l] ^ i; 
	// 				b = letters[l+1] ^ j; 
	// 				c = letters[l+2] ^ k;

	// 				if(a == 't' && b == 'h' && c == 'e'){
	// 					keys.push_back({i, j, k});
	// 					counter++;
	// 				} 
	// 			}
	// 		}
	// 	}
	// }

	// for(auto i : keys){
	// 	cout << char(i.a) << char(i.b) << char(i.c) << endl;
	// 	for(int j = 0; j < (int)letters.size(); j+=3){
	// 		int a, b, c;
	// 		a = letters[j] ^ i.a;
	// 		b = letters[j+1] ^ i.b;
	// 		c = letters[j+2] ^ i.c;

	// 		cout << char(a) <<","<< char(b) <<","<< char(c)<<",";
	// 	}
	// 	cout << endl << "------------------------------------------" << endl;
	// }


	long long sum = 0;
	for(int i = 0; i < (int)letters.size(); i+=3){
		char a = 'e' ^ letters[i];
		char b = 'x' ^ letters[i+1];
		char c = 'p' ^ letters[i+2];

		cout << a << b << c;
		
		sum += a + b + c;
	}

	cout << endl << sum << endl;

	return 0;
}