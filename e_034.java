/**************************************************************************
    Author: João V. Tristão
    Date: 07/01/2019
    Problem: Find the sum of all the numbers that can be written as the sum of the factorial of their digits.
    Approach:
        - Generate all numbers with until 7 digits
        - Check if they fit the rule.
Obs: 
    Why 7? -> Number of digits | Maximum value
                    1                  9! = 362.880
                    2                2*9! =   ...
                    3                3*9! =   ...
                    4                4*9! =   ...
                    5                5*9! =   ...
                    6                6*9! =   ...
                    7                7*9! = 2540160
                    8                8*9! = 2903040
    After seven, its impossible to reach all numbers with 7 digits.

**************************************************************************/

class factorialDigits{

    public static boolean check_factorial_digits(int a){
        int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int copy = a;

        int sum = 0;
        while(a >= 1){
            sum += factorial[a%10];
            a/=10;
        }

        if(sum == copy)
            return true;
        return false;
    }

    public static void main(String args[]){
        int sum = 0;
        for(int i = 11; i < 10000000; i++){

            if(check_factorial_digits(i) == true){
                System.out.println(i);
                
                sum+=i;
            }
        }

        System.out.println(sum);
    }
}