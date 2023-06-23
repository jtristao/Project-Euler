/**************************************************************************
    Author: João V. Tristão
    Date: 23/06/2023
    Problem: Square Remainders
    Approach: 
        - Good old brute force

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
    long long total = 0;
    for(int a = 3; a <= 1000; ++a) {
        int maximum = INT_MIN;

        for(int i = 0; i <= 10000; ++i) {
            int left = 1, right = 1;
            for(int j = 1; j < i; ++j) {
                left = (left *(a-1)) % i;
                right = (right *(a-1)) % i;
            }
            int sum = left + right;
            int r = sum % a*a;
            maximum = max(maximum, r);
        }

        printf("Max(%d) = %d\n", a, maximum);
        total += maximum;
    }

    printf("Total: %lld", total);

    return 0;
}