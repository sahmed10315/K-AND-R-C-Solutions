#include <stdio.h>

void itob(long n, char s[], int b);
void reverse(char s[]);

main()
{
	char s[10];
	
	itob(65462, s, 2);
	
	printf("%s\n", s);
}

/* By  negating n to make it positive, it overflows, as the higher value is one less than the lowest negative value */

void itob(long n, char s[], int b)
{
	int i, sign;
	int r;

	if((sign =n) < 0)
		n = -n;
	i = 0;
	do {

 		r = n % b ;
 
		switch(r)
		{
			case 10:
				s[i++] = 'A';
				break;
			case 11:
				s[i++] = 'B';
				break;

			case 12:
				s[i++] = 'C';
				break;

			case 13:
				s[i++] = 'D';
				break;

			case 14:
				s[i++] = 'E';
				break;

			case 15:
				s[i++] = 'F';
				break;

			default:
				s[i++] = r + '0';

		}
		 
	} while((n /= b) > 0);

	if(sign < 0)
	{ 
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