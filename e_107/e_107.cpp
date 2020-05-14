/**************************************************************************
	Author: João V. Tristão
	Date: 28/04/2020
	Problem: Minimal network
	Approach:
	- Use kruskall algorithm to find minimum spanning tree

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int dim = 40;

class Edge{
public:
	int u, v, w;

	Edge(int u, int v, int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}

	bool operator<(const Edge a){
		return this->w < a.w;
	}

	void print(){
		cout << "(" << this->u << "," << this->v << ")" << "[" << this->w << "]" << endl; 
	}
};

int parse_line(string s, vector<vector<int>>& graph, int i){
	int counter = 0;
	int pos = 0;
	int sum = 0;
	while(pos < (int)s.size()){
		if(s[pos] == '-') 
			counter++;
		else{
			if(s[pos] >= '0' and s[pos] <= '9'){
				int begin = pos;
				while(s[pos] >= '0' and s[pos] <= '9'){
					pos++;
				}

				graph[i][counter] = stoi(s.substr(begin, pos-begin)) ;
				sum += graph[i][counter];
				counter++;
			}
		}

		pos++;
	}

	return sum;
}

int find(vector<int>& parent, int x){
	if(x == parent[x]) return x;
	else
		return parent[x] = find(parent, parent[x]);
}

void join(vector<int>& parent, vector<int>& rank, int a, int b){
	a = find(parent, a);
	b = find(parent, b);
	if(rank[a] < rank[b]) swap(a,b);
	if(a != b){
		if(rank[a] == rank[b]) rank[a]++;
		parent[b] = a;
	} 
}

int kruskal(vector<vector<int>> graph){
	vector<Edge> edges;

	for(int i = 0; i < dim; ++i){
		for(int j = i; j < dim; ++j){
			if(graph[i][j] != -1)
				edges.push_back(Edge(i, j, graph[i][j]));
		}
	}

	sort(edges.begin(), edges.end());

	vector<int> rank(dim, 1);
	vector<int> parent(dim);
	for(int i = 0; i < dim; ++i)
		parent[i] = i;


	int total = 0;
	for(int i = 0; i < (int)edges.size(); ++i){
		Edge temp = edges[i];
		
		if(find(parent, temp.u) != find(parent, temp.v)){
			total += temp.w;

			join(parent, rank, temp.u, temp.v);
		}
	}

	return total;
}


int main(int argc, char *argv[]){
	std::ifstream file("network.txt");
	
	vector<vector<int>> graph(dim, vector<int>(dim, -1));

	int i = 0;
	long long total = 0;
	if (file.is_open()) {
	    std::string line;
	    while (std::getline(file, line)) {
	    	total += parse_line(line, graph, i);
	    	++i;
	    }
    	file.close();
	}

	total /= 2;

	int sub_total = kruskal(graph);

	cout << total - sub_total << endl;

	return 0;
}