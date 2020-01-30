#include <bits/stdc++.h>

// MArkov chain

using namespace std;

typedef struct{
	long prob_board[40] = {0};

	void print(int n){
		for(int i = 0; i < 40; i++){
			if(i %10 == 0)
				printf("\n");

			printf("%ld ", prob_board[i]);
		}
		printf("\n");
	}
} Board;


typedef struct {
	unordered_set<int> places = {7, 22, 36};	
	vector<int> cards = {0, 10, 11, 24, 39, 5, -1, -1, -2, -3, 50, 50, 50, 50, 50, 50};
	bool shuffle = false;


	void prepare_cards(){
		if(this->shuffle == false){
			random_shuffle(cards.begin(), cards.end()); 
			this->shuffle = true;
		}
	}

	int pick_card(){
		this->prepare_cards();

		int card = cards[0];
		cards.erase(cards.begin());
		cards.push_back(card);

		return card;
	}

	void print_cards(){
		for(int i = 0; i < (int)cards.size(); i++){
			printf("%d ", cards[i]);
		}
		printf("\n");
	}
} Chance;


typedef struct {
	unordered_set<int> places = {2, 17, 33};
	vector<int> cards = {0, 10, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
	bool shuffle = false;

	void prepare_cards(){
		if(this->shuffle == false){
			random_shuffle(cards.begin(), cards.end()); 
			this->shuffle = true;
		}
	}

	int pick_card(){
		this->prepare_cards();

		int card = cards[0];
		cards.erase(cards.begin());
		cards.push_back(card);

		return card;
	}

	void print_cards(){
		for(int i = 0; i < (int)cards.size(); i++){
			printf("%d ", cards[i]);
		}
		printf("\n");
	}

} ComunityChest;

bool sortf(const pair<int,long> &a, const pair<int,long> &b){ 
    return (a.second > b.second); 
} 

int main(int argc, char *argv[]){
	srandom(time(NULL));

	Board b;
	ComunityChest cc;
	Chance ch;
	int iter_limit = 10000000, pos = 0, equal_dice = 0;
	int d1, d2, card;
	
	for(int i = 0; i < iter_limit; i++){
		d1 = random()%4+1;
		d2 = random()%4+1;
		// printf("%d (%d)\n", pos, d1+d2);

		if(d1 == d2){
			equal_dice += 1;
		}else{
			equal_dice = 0;
		}

		if(equal_dice == 3){
			pos = 10;
			// equal_dice = 0;
		}else{
			pos = (pos + d1 + d2)%40;
			if(pos == 30)
				pos = 10;
			else if(ch.places.find(pos) != ch.places.end()){
				card = ch.pick_card(); 
				// printf("Chance: ");
				
				if(card < 40){
					// Railway company
					if(card == -1){
						// printf("Railway\n");
						if(pos == 7){ //CH1
							pos = 15;
						}else if(pos == 22){ // CH2
							pos = 25;
						}else if(pos == 36){ // CH3
							pos = 5;
						}
					}else if(card == -2){ // Utility company
						// printf("Utility\n");
						if(pos == 7 || pos == 36){ //CH1 || CH3
							pos = 12;
						}else if(pos == 22){ // CH2
							pos = 28;
						}
					}else if(card == -3){
						// printf("Go back\n");
						pos -= 3;
					}else {
						pos = card;
					}
				}else{
					// printf("Nothing\n");
				}
			}else if(cc.places.find(pos) != cc.places.end()){
				// printf("ComunityChest\n");

				card = cc.pick_card();

				if(card < 40){
					pos = card;
				}
			}
		}

		b.prob_board[pos] += 1;		
	}

	vector<pair<int, long>> probs;
	for(int i = 0; i < 40; i++){
		probs.push_back({i, b.prob_board[i]});
	}

	sort(probs.begin(), probs.end(), sortf);
	printf("String: ");
	for(int i = 0; i < 3; i++){
		printf("%d", probs[i].first);
	}
	printf("\n");

	return 0;
}