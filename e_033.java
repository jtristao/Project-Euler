/**************************************************************************
	Author: João V. Tristão
	Date: 07/01/2019
	Problem: Diggit cancelling fractions
	Approach:
		- Find all fractions that fit the criteria.

Obs:
	(1/4)*(1/5)*(2/5)*(4/8) = 8/800 = 1/100 
**************************************************************************/

class digitCancelling{
	public static boolean find_commom(int a, int b){
		int first_a = a/10;
		int last_a = a%10;
		int first_b = b/10;
		int last_b = b%10;

		if(first_a == first_b || first_a == last_b || last_a == first_b || last_a == last_b)
			return true;

		return false;
	}

	public static int remove_commom(int a, int b){
		int first_a = a/10;
		int last_a = a%10;
		int first_b = b/10;
		int last_b = b%10;

		if(first_a == first_b || first_a == last_b){
			return a % 10;
		}else if(last_a == first_b || last_a == last_b)
			return a / 10;

		return 1;
	}

	public static void main(String args[]){
		double quotient;

		for(int i = 10; i < 100; i++){
			for(int j = i+1; j < 100; j++){
				if(i%10 != 0 && j % 10 != 0 && i != j){
					quotient = ((double)i/(double)j);
					if(find_commom(i, j) == true){
						int num = remove_commom(i, j);
						int den = remove_commom(j, i);
						double new_quotient = (double)num/(double)den;

						double ratio = quotient/new_quotient;

						if(ratio == 1){
							System.out.format("%d/%d (%f) -> %d/%d (%f)\n", i , j, quotient, num, den, new_quotient);
						}
					}
				}
			}
		}
	}
}