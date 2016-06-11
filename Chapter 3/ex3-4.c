#include <stdio.h>

void itoa(signed char n, char s[]);
void reverse(char s[]);

main()
{
	char s[10];
	
	itoa(-128, s);
	
	printf("%s\n", s);
}

/* By  negating n to make it positive, it overflows, as the higher value is one less than the lowest negative value */

void itoa(signed char n, char s[])
{
	int i, sign;

	if((sign =n) < 0)
		n = -n - 1;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);

	if(sign < 0)
	{
		s[0] += 1;
		s[i++] = '-';
 
	}
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