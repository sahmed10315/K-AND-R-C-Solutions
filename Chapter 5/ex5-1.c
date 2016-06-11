#include <ctype.h>
#include <stdio.h>
#include "calc.h"

#define SIZE 100

int getint(int * pn)
{

	int c, sign;
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
	{
		c = getch();
		if(!isdigit(c))
		{	
			ungetch(c);
			return 0;
		}
	}

	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

int main()
{

	int n, array[SIZE], getint(int *);

	for(int i = 0; i < SIZE; i++)
		array[i] = 0;

	for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	
	for(int i = 0; i < SIZE; i++)
		printf("%d\t", array[i]);
	printf("\n");
	return 0;
}
