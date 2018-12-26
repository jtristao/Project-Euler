/**************************************************************************
	Author: João V. Tristão
	Date: 
	Problem: 
	Approach:

**************************************************************************/

/*
int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; 
double memo[VALUE+1];

double coin_sum(int remain){
	int sub_total = 0;
	if(remain == 0)
		return 1;
	if(remain > 0){
		if(memo[remain] != -1)
			return memo[remain];
		else {
			for(int i = 0; i < 8; i++){
				sub_total += coin_sum(remain - coins[i]);
			}
			memo[remain] = sub_total;
		}
	}

	return sub_total;
}

int main(int argc, char *argv[]){
	for(int i = 0; i <= VALUE; i++)
		memo[i] = -1;
	
	coin_sum(VALUE);

	for(int i = 0; i <= VALUE; i++)
		printf("%d  %lf\n", i, memo[i]);


	return EXIT_SUCCESS;
}*/


class coins {
	private static final int VALUE = 5;

    public static void main(String args[]){
		int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; 
		int memo[] = new int[6];

    	for(int i = 0; i <= VALUE; i++)
    		memo[i] = -1;

    	coin_sum(coins, memo, 4);

    	for(int i = 0; i <= VALUE; i++)
    		System.out.print(memo[i]);	
    }


	public static long coin_sum(int coins[], int memo[], int remain){
		int sub_total = 0;
		if(remain == 0)
			return 1;
		if(remain > 0){
			if(memo[remain] != -1)
				return memo[remain];
			else {
				for(int i = 0; i < 8; i++){
					sub_total += coin_sum(coins, memo, remain - coins[i]);
				}
				memo[remain] = sub_total;
			}
		}

		return sub_total;
	}
}