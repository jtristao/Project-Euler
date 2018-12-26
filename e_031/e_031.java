/**************************************************************************
	Author: João V. Tristão
	Date: 26/12/2018
	Problem: How many different ways can £2 be made using any number of coins?
	Approach:
		- Use dynamic programming.
		- Every step is defined by its previous value - a certain coin value.
		
	Complexity:
		Time: O(n_coins*value)
		Space: O(n_coins)

**************************************************************************/

class coins {
	private static final int VALUE = 200;

    public static void main(String args[]){
		int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; 
		int memo[] = new int[VALUE+1];

    	memo[0] = 1;

    	coin_sum(coins, memo);

    	for(int i = 0; i <= VALUE; i++)
    		System.out.format("%d %d\n", i, memo[i]);	
    }


	public static void coin_sum(int coins[], int memo[]){
		for(int i = 0; i < coins.length; i++){
			for(int j = coins[i]; j <= VALUE; j++){
				memo[j] += memo[j-coins[i]];
			}
		}
	}
}