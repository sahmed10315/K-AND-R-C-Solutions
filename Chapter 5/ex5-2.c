#include <ctype.h>
#include <stdio.h>
#include "calc.h"

#define SIZE 100

int getfloat(double * pn)
{
	double power;
	int c, sign;
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();

	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	if(c == '.')
		c = getch();
	
	for(power = 1.0; isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;	
	}

	*pn = sign * *pn / power;

	if(c != EOF)
		ungetch(c);
	return c;
}

int main()
{

	int n, getfloat(double *);
	double array[SIZE];

	for(int i = 0; i < SIZE; i++)
		array[i] = 0;

	for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	
	for(int i = 0; i < SIZE; i++)
		printf("%g\t", array[i]);
	printf("\n");
	return 0;
}
