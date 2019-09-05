/**************************************************************************
	Author: João V. Tristão
	Date: 
	Problem: 
	Approach:

**************************************************************************/

import java.math.BigInteger; 

class coins {
	private static final int VALUE = 200;

    public static void main(String args[]){
		int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; 
		BigInteger memo[] = new BigInteger[VALUE+1];

    	for(int i = 0; i <= VALUE; i++)
    		memo[i] = BigInteger.valueOf(-1);

    	coin_sum(coins, memo, VALUE);

    	for(int i = 0; i <= VALUE; i++)
    		System.out.format("%d %d\n", i, memo[i]);	
    }


	public static BigInteger coin_sum(int coins[], BigInteger memo[], int remain){
		BigInteger sub_total = BigInteger.valueOf(0);
		
		if(remain == 0)
			return BigInteger.valueOf(1);
		if(remain > 0){
			if(memo[remain] != BigInteger.valueOf(-1))
				return memo[remain];
			else {
				for(int i = 0; i < 8; i++){
					sub_total = sub_total.add(coin_sum(coins, memo, remain - coins[i]));
				}
				memo[remain] = sub_total;
			}
		}

		return sub_total;
	}
}