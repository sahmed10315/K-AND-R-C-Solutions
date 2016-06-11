#include <stdio.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

main()
{
	char s[10];
	
	itoa(-128, s, 15);
	
	printf("%s\n", s);
}

/* By  negating n to make it positive, it overflows, as the higher value is one less than the lowest negative value */

void itoa(int n, char s[], int w)
{
	int i, sign;

	if((sign =n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);

	if(sign < 0)
	{
 
		s[i++] = '-';
 
	}
 
 	int l = i;
	while(l < w--)
		s[i++] = ' ';

	s[i] = '\0';
	reverse(s);
 
}

void reverse(char s[])
{
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}