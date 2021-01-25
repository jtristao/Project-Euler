#include <bits/stdc++.h>

using namespace std;

#define N 80

vector<vector<int>> visited(N, vector<int>(N));
int movements[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};


class Position{
	public:
		int x, y, cost;

		Position(int a, int b, int c){
			this->x = a;
			this->y = b;
			this->cost = c;
		}

		Position(){};

		bool operator==(const Position p){
			if(this->x == p.x && this->y == p.y)
				return true;
			else
				return false;
		}

		void print(){
			printf("(%d, %d)[%d]\n", this->x, this->y, this->cost);
		}
};

bool operator<(const Position& p1, const Position& p2){ 
	return p1.cost > p2.cost; 
} 

/* BFS
	- Inicio a pilha
	- Adiciono Primeiro elemento
	- Enquanto a pilha nao estiver vazia:
		- Removo o topo
		- Adiciono os filhos do topo

*/

vector<Position> find_movements(Position cur){
	vector<Position> moves;
	for(int i = 0; i < 4; i++){
		Position aux(cur.x + movements[i][0], cur.y + movements[i][1], 0);
		if(aux.x >= 0 && aux.x < N && aux.y >= 0 && aux.y < N){
			if(visited[aux.x][aux.y] == false){
				moves.push_back(aux);
			}
		}
	}

	return moves;
}

void search(int matrix[][N], Position begin, Position end){
	priority_queue<Position> to_visit;
	vector<Position> moves;
	Position current;

	to_visit.push(begin);
	while(!to_visit.empty()){
		current = to_visit.top();
		to_visit.pop();

		visited[current.x][current.y] = true;

		if(current == end){
			printf("Shortest Path : %d\n", current.cost);
			exit(0);
		}

		moves = find_movements(current);
		for(auto mv : moves){
			mv.cost = matrix[mv.x][mv.y] + current.cost;
			to_visit.push(mv);
		}

		// visited[current.x][current.y] = false;

	}

}

	

int main(int argc, char *argv[]){
	int matrix[N][N];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d,", &matrix[i][j]);
		}
	}

	Position begin(0, 0, 0);
	Position end(N-1, N-1, matrix[N-1][N-1]);

	search(matrix, end, begin);

	return 0;
}