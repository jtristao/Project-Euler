/**************************************************************************
	Author: João V. Tristão
	Date: 10/07/2018
	Problem: Find the sum of the digits of 2^1000.
	Approach:
		- Use https://defuse.ca/big-number-calculator.htm to calculate the number
		- Add the digits

**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	int len, sum;
	char *answer = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	
	len = strlen(answer);
	sum = 0;
	for(int i = 0; i < len; i++){
		sum += (answer[i]-48);
		printf("%d\t", ,answer[i]-48);
	}
	
	printf("%d", sum);
}
