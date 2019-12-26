/**************************************************************************
	Author: João V. Tristão
	Date: 26/12/2019
	Problem: Ordered fractions
	Approach:
		- Use Stern-Brocot tree to perform binary search.

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Fraction{
	public:
		int num, den;

		Fraction(int n = 1, int d = 1){
			num = n;
			den = d;
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
};

bool fractions_less_than(Fraction a, Fraction b){
	return a.num * b.den < b.num * a.den;
}

int main(int argc, char *argv[]){
	Fraction left(0,1), right(1,1), middle(0,0);
	int count = 0;

	while(left.den + right.den <= 1000000){
		count++;
		middle.num = left.num + right.num;
		middle.den = left.den + right.den;
	
		bool side = (middle.num == 3 && middle.den == 7) || ! fractions_less_than(middle, {3,7});

		if(side){
			right = middle;
		}else{
			left = middle;
		}
	}

	middle.print();
	printf("%d\n", count);

	return 0;
}