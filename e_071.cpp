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

int main(int argc, char *argv[]){
	int n = 1000000;

	for(int num = 1; num < n; num++){
		for(int den = 1; den <=n; den++){
		}
		if(num % 10000 == 0)
			printf("%d\n", num/10000);

	}

	return 0;
}