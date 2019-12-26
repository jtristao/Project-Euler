/**************************************************************************
	Author: João V. Tristão
	Date: 26/12/2019
	Problem: Counting fractions in a range
	Approach:
		- Produce all fractions in the range. (A little bit slow, took about 6 min)

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Fraction{
	public:
		int num, den;

		Fraction(int n = 1, int d = 1){
			int factor = __gcd(n, d);

			num = n/factor;
			den = d/factor;
		}

		void print(){
			printf("%d/%d\n", num, den);
		}

		Fraction operator + (Fraction a) {
			Fraction c;

			c.num = num*a.den + den*a.num;
			c.den = den*a.den;

			return c;
		}

		Fraction operator * (Fraction a) {
			Fraction c;

			c.num = num*a.num;
			c.den = den*a.den;

			return c;
		}

		bool operator < (Fraction a) {
			return a.num * this->den > this->num * a.den;
		}

		bool operator > (Fraction a) {
			return a.num * this->den < this->num * a.den;
		}
};

bool compare(const Fraction& a, const Fraction& b){
	return a.num * b.den < b.num * a.den;
}

int main(int argc, char *argv[]){
	int limit = 12000;
	set<Fraction, bool(*)(const Fraction&, const Fraction&)> farey_series(compare);

	for(int i = 0; i <= limit; i++){
		for(int j = 1; j <= limit; j++){
			Fraction aux(i,j);
			farey_series.insert(aux);	
		}
		if(i % 1200 == 0)
			printf("%d%%\n", i/1200);
	}

	Fraction begin(1,3), end(1,2);
	int count = 0;

	for(auto i:farey_series){
		if(i > begin && i < end){
			count++;
		}
	}

	printf("Count : %d\n", count);

	return 0;
}
