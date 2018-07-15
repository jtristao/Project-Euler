#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum{
	SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
}WEEK;

enum{
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
}MONTH;

int main(){
	int sum, day, month, year;

	sum = 0;
	day = MONDAY;
	month = JAN;
	year = 1900;

	int i = 0;
	while(year <= 2000) {
		printf("%d\t", day);
		if(month == JAN || month == MAR || month == MAY || month == JUL || month == AUG|| month == OCT  || month == DEC) {
			day = (day + 3)%7;
		} else if(month == APR || month == JUN || month == SEP || month == NOV) {
			day = (day + 2)%7;
		} else if(year > 1900 && year % 4 == 0)
			day = (day + 1)%7;

		if(year > 1900 && day == SUNDAY)
			sum++;

		i++;
		month++;
		if(month == 12) {
			month %= 12;
			printf("year %d\n", year);
			year++;
		}
	}

	printf("SUNDAYS = %d %d\n", sum, i);

	return EXIT_SUCCESS;
}