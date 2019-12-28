/**************************************************************************
	Author: João V. Tristão
	Date: 26/12/2019
	Problem: Path Sum: Three ways
	Approach:
		- For every begining in the left:
			- For every ending in the right: 
				- Performa a exaustive search using the shortest path avaible. 
					
	Obs:
		- A little bit slow, took about 6 min. Find a single solution is kind of fast, but all possibilities took a while
		- A* wihtout a distance heuristic

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define N 80

vector<vector<int>> visited(N, vector<int>(N));
int movements[3][2] = {{-1,0}, {1,0}, {0,-1}};


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

vector<Position> find_movements(Position cur){
	vector<Position> moves;
	for(int i = 0; i < 3; i++){
		Position aux(cur.x + movements[i][0], cur.y + movements[i][1], 0);
		if(aux.x >= 0 && aux.x < N && aux.y >= 0 && aux.y < N){
			if(visited[aux.x][aux.y] == false){
				moves.push_back(aux);
			}
		}
	}

	return moves;
}

int search(int matrix[][N], Position begin, Position end){
	priority_queue<Position> to_visit;
	vector<Position> moves;
	Position current;

	to_visit.push(begin);
	while(!to_visit.empty()){
		current = to_visit.top();
		to_visit.pop();

		// current.print();

		visited[current.x][current.y] = true;

		if(current == end){
			return current.cost;
		}

		moves = find_movements(current);
		for(auto mv : moves){
			mv.cost = matrix[mv.x][mv.y] + current.cost;
			to_visit.push(mv);
		}

		// visited[current.x][current.y] = false;

	}
	return -1;
}

void reset_visited(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			visited[i][j] = 0;
	}
}
	

int main(int argc, char *argv[]){
	int matrix[N][N];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d,", &matrix[i][j]);
		}
	}

	Position begin, end;
	int cost = 0x3f3f3f3f;
	int cur_cost;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			begin = {i, 0, 0};
			end = {j, N-1, matrix[j][N-1]};
			
			cur_cost = search(matrix, end, begin);
			cost = min(cost, cur_cost);
			
			// printf("[%d]Shortest Path : %d\n", i*N+j, cur_cost);
			if((i*N + j) % 640 == 0)
				printf("%d%%\n", (i*N + j)/640);
			reset_visited();
		}
	}

	printf("Minimal distance : %d\n", cost);

	return 0;
}