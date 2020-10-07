/**************************************************************************
	Author: João V. Tristão
	Date: 7/10/2020
	Problem: Triangle containment
	Approach:
		- Parse the triangles
		- for every triangle, check if origin is inside
	reference:
		https://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-point-lies-inside-a-triangle-defined-by-three-points

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x;
	int y;

	Point(){
		this->x = 0;
		this->y = 0;		
	}

	Point(int a, int b){
		this->x = a;
		this->y = b;
	}

	Point operator-(const Point a){
		return Point(this->x - a.x, this->y - a.y);
	}

	void print(){
		printf("(%d, %d)\n", x, y);
	}
};

struct Triangle{
	Point a, b, c;

	Triangle(){
		this->a = Point();
		this->b = Point();
		this->c = Point();
	}

	Triangle(Point a, Point b, Point c){
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void print(){
		a.print();
		b.print();
		c.print();
		printf("\n");
	}
};

int cross_product(const Point a, const Point b){
	return a.x*b.y - a.y*b.x;
}

int check_origin(Triangle t){
	Point a = t.a;
	Point b = t.b;
	Point c = t.c;
	Point p(0,0);

	Point ab = b-a;
	Point bc = c-b;
	Point ca = a-c;

	Point ap = p-a;
	Point bp = p-b;
	Point cp = p-c;

	if(cross_product(ab, ap) > 0 and cross_product(bc,bp) > 0 and cross_product(ca, cp) > 0){
		return 1;
	}else if(cross_product(ab, ap) < 0 and cross_product(bc,bp) < 0 and cross_product(ca, cp) < 0){
		return 1;
	}else
		return 0;
}

Triangle parse_line(string line){
	stringstream stream(line);

	vector<int> nums;
	while(stream.good()){
		string substring;
		getline(stream, substring, ',');

		nums.push_back(stoi(substring));
	}

	Point a(nums[0], nums[1]);
	Point b(nums[2], nums[3]);
	Point c(nums[4], nums[5]);

	Triangle t(a,b,c);

	return t;
}

int main(int argc, char *argv[]){
	fstream file;
	int origin_cnt = 0;

	file.open("e_102.in", ios::in);

	if(file.is_open()){
		string line;
		Triangle t;

		while(getline(file, line)){
			t = parse_line(line);
			origin_cnt += check_origin(t);
		}

		cout << origin_cnt << endl;


	}else{
		cout << "File (e_102.in) not found" << endl;
		exit(0);
	}


	file.close();

	return 0;
}