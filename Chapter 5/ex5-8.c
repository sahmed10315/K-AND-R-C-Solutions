#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);

void month_day(int year, int yearday, int *pmonth, int *pda);
main()
{

}

int day_of_year(int year, int month, int day)
{
	if(year < 1 || (month < 1 || month > 12) || (day < 1 || day > 31))
		return -1;

	int i, leap;
	leap = year %4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if(year < 1 || yearday < 1 || yearday > 365)
		return;

	int i, leap;
	leap = year %4 == 0 && year % 100 != 0 || year % 400 == 0;
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
