#include <bits/stdc++.h> 

using namespace std;

vector<string> permutations;

#define VALUES "123456789"

void generate_permutations(string chosed, string avaible){
	if(avaible.size() == 0){
		cout << chosed << endl;
		permutations.push_back(chosed);
	}else{
		for(int i = 0; i < (int)avaible.size(); i++){
			chosed.push_back(avaible[i]);
			avaible.erase(avaible.begin()+i);

			generate_permutations(chosed, avaible);

			avaible.insert(i, 1, chosed.back());
			chosed.pop_back();
		}
	}
}

int main(int argc, char *argv[]){
	generate_permutations("", VALUES);	


	return EXIT_SUCCESS;
}