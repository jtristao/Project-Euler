/**************************************************************************
	Author: João V. Tristão
	Date: 10/01/2020
	Problem: Cube digit pairs
	Approach:
		- Gererate all possible sets of dice
		- Check for evey pair if the combination is valid

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void set_print(set<int> s){
	printf("(");
	for(auto i : s)
		printf("%d  ", i);
	printf(")");
}


void find_sets(vector<int> avaible, set<int> chosen, int pos, int len, set<set<int>>& sets){
	if(chosen.size() == 6){
		sets.insert(chosen);
	}else if(pos < len){

		// Do not add element
		find_sets(avaible, chosen, pos+1, len, sets);

		// Add element
		chosen.insert(avaible[pos]);	

		find_sets(avaible, chosen, pos+1, len, sets);
	}
}

bool check_perfect_square(set<int> s1, set<int> s2){
	vector<string> squares = {"01", "04", "09", "16", "25", "36", "49", "64", "81"};
	// printf("%d hehe\n", squares[0][0]+'0');
		
	for(auto num : squares){
		int a = num[0]-'0';
		int b = num[1]-'0';

		if(a == 6){
			if(!((s1.count(a) != 0 && s2.count(b) != 0) || (s1.count(b) != 0 && s2.count(a) != 0) || (s1.count(9) != 0 && s2.count(b) != 0) || (s1.count(b) != 0 && s2.count(9) != 0)))
				return false;
		}else if(b == 6){
			if(!((s1.count(a) != 0 && s2.count(b) != 0) || (s1.count(b) != 0 && s2.count(a) != 0) || (s1.count(a) != 0 && s2.count(9) != 0) || (s1.count(9) != 0 && s2.count(a) != 0)))
				return false;
		}else if(b == 9){
			if(!((s1.count(a) != 0 && s2.count(b) != 0) || (s1.count(b) != 0 && s2.count(a) != 0) || (s1.count(a) != 0 && s2.count(6) != 0) || (s1.count(6) != 0 && s2.count(a) != 0)))
				return false;
		}else if(!((s1.count(a) != 0 && s2.count(b) != 0) || (s1.count(b) != 0 && s2.count(a) != 0))){
			return false;
		}
	}

	return true;
}

// (s1.count(a) == 0 || s2.count(b) == 0) && (s1.count(b) == 0 || s2.count(a) == 0)

int main(int argc, char *argv[]){
	set<set<int>> sets;
	int n = 10;

	vector<int> numbers(n);
	for(int i = 0; i < n; i++)
		numbers[i] = i;

	find_sets(numbers, {}, 0, n, sets);

	int count = 0;
	for(set<set<int>>::iterator s1 = sets.begin(); s1 != sets.end(); s1++){
		for(set<set<int>>::iterator s2 = next(s1); s2 != sets.end(); s2++){
			if(check_perfect_square(*s1, *s2) == true){
				set_print(*s1);
				set_print(*s2);
				printf("\n");
				count++;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}