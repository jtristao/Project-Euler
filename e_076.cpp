/*************************************************************************
    Author: João V. Tristão
    Date: 14/02/2019
    Problem: Counting summations
    Approach: 
        -Dynamic Programming (Coin Problem)

*************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
    int n = 100;
    vector<long long int> coins(n+1, 0);

    coins[0] = 1;

    // For every coin
    for(int i = 1; i < n; i++){
        // For every value
        for(int j = i; j <= n; j++){
            coins[j] += coins[j-i];
        }
    }

    printf("Sums : %lld\n", coins[n]);

    return 0;
}