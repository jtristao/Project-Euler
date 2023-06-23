/*************************************************************************
	Author: João V. Tristão
	Date: 23/06/2023
	Problem: Dice Game
	Approach:
		- Pre calculate the odds of the dices give a certain value
        - Be X the sum of cubic dice and Y the sum of tetra dice

        sum(k = 6 to 36) P(X = k) and P(Y > k)
    Obs:
        Brute force doesnt Work :(
*************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int throw_dice(int n, int dice, int sum) {
    if(n == 0 and sum == 0) {
        return 1;
    } else if(n > 0 and sum > 0) {
        int ret = 0;
        for(int i = 1; i <= dice; ++i){
            ret += throw_dice(n-1, dice, sum-i);
        }

        return ret;
    }

    return 0;
}

int main(){
    vector<int> tetra(37), cube(37);
    for(int i = 0; i <= 36; ++i)
        tetra[i] = throw_dice(9, 4, i);
    
    for(int i = 0; i <= 36; ++i)
        cube[i] = throw_dice(6, 6, i);
    
    long long tetra_sum = std::accumulate(tetra.begin(), tetra.end(), 0);
    long long cube_sum = std::accumulate(cube.begin(), cube.end(), 0);

    double total = 0;
    long long tetra_partial = 0;
    for(int i = 6; i <= 36; ++i){
        tetra_partial += tetra[i];
        total += (cube[i] * (tetra_sum - tetra_partial));
        cout << total << endl;
    }

    cout << setprecision(7) << fixed << total/(tetra_sum * cube_sum) << endl;
    
	return EXIT_SUCCESS;
}
