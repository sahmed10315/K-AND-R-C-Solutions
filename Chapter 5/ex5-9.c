#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);

void month_day(int year, int yearday, int *pmonth, int *pda);
main()
{

	int year, month, day, yearday;
	
	year = 2000;
	month = 3;
	day = 1;
	printf("The date is: %d-%02d-%02d\n", year, month, day);
	printf("day_of_year: %d\n", day_of_year(year, month, day)); 


	yearday = 61;	/* 2000-03-01 */
	month_day(year, yearday, &month, &day);
	printf("Yearday is %d\n", yearday);
	printf("month_day: %d %d\n", month, day); 
}

int day_of_year(int year, int month, int day)
{
	if(year < 1 || (month < 1 || month > 12) || (day < 1 || day > 31))
		return -1;

	int i, leap;
	leap = year %4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += *((char *)daytab + (13 * leap + i));
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if(year < 1 || yearday < 1 || yearday > 365)
		return;

	int i, leap;
	leap = year %4 == 0 && year % 100 != 0 || year % 400 == 0;
	for(i = 1; yearday > *((char *)daytab + (13 * leap + i)); i++)
		yearday -= *((char *)daytab + (13 * leap + i));
	*pmonth = i;
	*pday = yearday;
}
