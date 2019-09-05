/**************************************************************************
	Author: João V. Tristão
	Date: 09/07/2019
	Problem: Poker hands
	Approach:
		- Simulate a poker game, using diferents pontuations for every hand

**************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

#define TEN ':'
#define JACK ';'
#define QUEEN '<'
#define KING '='
#define ACE '>'

typedef struct _card{
	char value;
	char suit;
} CARD;

typedef struct HAND{
	CARD card[5];

	void print_hand(){
		for(int i = 0; i < 5; i++){
			printf("%c%c\t", this->card[i].value, this->card[i].suit);
		}
		printf("\n");
	}
} HAND;

void open_file(FILE **pointer){
	*pointer = fopen("poker.txt", "r");
	if(*pointer == NULL){
		printf("Invalid file\n");
		exit(0);
	}
}

void get_hands(FILE *file, HAND *h1, HAND *h2){
	for(int i = 0; i < 5; i++){
		fread(&(h1->card[i].value), 1, sizeof(char), file);
		fread(&(h1->card[i].suit), 1, sizeof(char), file);
	
		if(h1->card[i].value == 'T'){
			h1->card[i].value = TEN;
		}else if(h1->card[i].value == 'J'){
			h1->card[i].value = JACK;
		}else if(h1->card[i].value == 'Q'){
			h1->card[i].value = QUEEN;
		}else if(h1->card[i].value == 'K'){
			h1->card[i].value = KING;
		}else if(h1->card[i].value == 'A'){
			h1->card[i].value = ACE;
		}
	
		getc(file);
	}

	for(int i = 0; i < 5; i++){
		fread(&(h2->card[i].value), 1, sizeof(char), file);
		fread(&(h2->card[i].suit), 1, sizeof(char), file);
		
		if(h2->card[i].value == 'T'){
			h2->card[i].value = TEN;
		}else if(h2->card[i].value == 'J'){
			h2->card[i].value = JACK;
		}else if(h2->card[i].value == 'Q'){
			h2->card[i].value = QUEEN;
		}else if(h2->card[i].value == 'K'){
			h2->card[i].value = KING;
		}else if(h2->card[i].value == 'A'){
			h2->card[i].value = ACE;
		}

		getc(file);
	}
}

int compare(const void *a, const void *b){
	CARD ca = *(CARD *)a;
	CARD cb = *(CARD *)b;

	return ca.value > cb.value;
}


int evaluate_hand(HAND *h){
	qsort(h->card, 5, sizeof(CARD), compare);

	// All cards have the same suit
	if(h->card[0].suit == h->card[1].suit && h->card[1].suit == h->card[2].suit && h->card[2].suit == h->card[3].suit && h->card[3].suit == h->card[4].suit){
		// Royal flush
		if(h->card[0].value == TEN && h->card[1].value == JACK && h->card[2].value == QUEEN && h->card[3].value == KING && h->card[4].value == ACE)
			return 15000;

		// Straight flush
		else if(h->card[0].value == h->card[1].value-1 && h->card[1].value == h->card[2].value-1 && h->card[2].value == h->card[3].value-1 && h->card[3].value == h->card[4].value-1)
			return 14000+h->card[4].value;

		// Flush
		else
			return 10000+h->card[4].value;

	}else {
		// Four of a kind
		if(h->card[0].value == h->card[1].value && h->card[1].value == h->card[2].value && h->card[2].value == h->card[3].value)
			return 12000+h->card[0].value; 
		else if(h->card[1].value == h->card[2].value && h->card[2].value == h->card[3].value && h->card[3].value == h->card[4].value)
			return 12000+h->card[1].value;

		// Full house
		else if((h->card[0].value == h->card[1].value && h->card[1].value == h->card[2].value && h->card[3].value == h->card[4].value))
			return 11000 + 10*h->card[0].value + h->card[3].value;
		else if((h->card[0].value == h->card[1].value && h->card[2].value == h->card[3].value && h->card[3].value == h->card[4].value))
			return 11000 + 10*h->card[2].value + h->card[0].value;

		// Straight
		else if(h->card[0].value == h->card[1].value-1 && h->card[1].value == h->card[2].value-1 && h->card[2].value == h->card[3].value-1 && h->card[3].value == h->card[4].value-1)
			return 9000;

		// Three of a kind
		else if(h->card[0].value == h->card[1].value && h->card[1].value == h->card[2].value)
			return 8000 + h->card[0].value;
		else if(h->card[1].value == h->card[2].value && h->card[2].value == h->card[3].value)
			return 8000 + h->card[1].value;
		else if(h->card[2].value == h->card[3].value && h->card[3].value == h->card[4].value)
			return 8000 + h->card[2].value;

		// Two pairs
		else if(h->card[0].value == h->card[1].value && h->card[2].value == h->card[3].value)
			return 7000 + h->card[0].value + h->card[2].value;
		else if(h->card[1].value == h->card[2].value && h->card[3].value == h->card[4].value)
			return 7000 + h->card[1].value + h->card[3].value;
		else if(h->card[0].value == h->card[1].value && h->card[3].value == h->card[4].value)
			return 7000 + h->card[0].value + h->card[3].value;

		// One pair
		else if(h->card[0].value == h->card[1].value)
			return 6000 + h->card[0].value;
		else if(h->card[1].value == h->card[2].value)
			return 6000 + h->card[1].value;
		else if(h->card[2].value == h->card[3].value)
			return 6000 + h->card[2].value;
		else if(h->card[3].value == h->card[4].value)
			return 6000 + h->card[3].value;

		// High card
		else
			return 1;
	}
}

int main(int argc, char *argv[]){
	FILE *poker_file;

	open_file(&poker_file);

	long long player_1_wins = 0;
	long long player_2_wins = 0;

	while(!feof(poker_file)){
		HAND p1, p2;
		get_hands(poker_file, &p1, &p2);

		int points_p1 = evaluate_hand(&p1);
		int points_p2 = evaluate_hand(&p2);

		if(points_p1 > points_p2){
			player_1_wins++;
		}else if(points_p1 == points_p2){
			
			int k = 4;
			while(p1.card[k].value == p2.card[k].value && k>=0)
				k--;

			if(p1.card[k].value > p2.card[k].value){
				player_1_wins++;
			}else{
				player_2_wins++;
			}
		}else{
			player_2_wins++;
		}
	}

	printf("Player 1 wins: %lld \n", player_1_wins);
	printf("Player 2 wins: %lld \n", player_2_wins);

	return EXIT_SUCCESS;
}