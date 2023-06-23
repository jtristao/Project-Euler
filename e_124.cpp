/**************************************************************************
    Author: João V. Tristão
    Date: 23/06/2023
    Problem: Ordered Radicals
    Approach: 
        - Good old brut force

**************************************************************************/

#include <bits/stdc++.h>

using namespace std;

long long find_prime_factors(int x) {
    int prime = 2;
    long long sum = 1;
    while(x != 1) {
        if(x % prime == 0)
            sum *= prime;
        while(x % prime == 0)
            x = x / prime;
        prime++;
    }

    return sum;
}

bool compare(const vector<long long>& a, const vector<long long>& b) {
    return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
}

int main(int argc, char *argv[]){
    int n = 100000;
    vector<vector<long long>> radicals(n+1, vector<long long>(2));

    for(int i = 1; i <= n; ++i) {
        radicals[i][0] = i;
        radicals[i][1] = find_prime_factors(i);
    }
    
    sort(radicals.begin(), radicals.end(), compare);

    printf("E(%d) = %lld\n", 10000, radicals[10000][0]);

    return 0;
}