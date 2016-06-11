#include <stdio.h>

void itoa(int n, char s[]);
static void itoaR(int n, char s[]);
static int i = 0;

main()
{
	char s[10];
	itoa(-12345,s); 
	printf("%s\n",s);
}
 
void itoa(int n, char s[])
{
	int sign; 

	if((sign = n) < 0)
	{
		n = -n;
		s[i++] = '-';
	}
	
	itoaR(n, s);
	s[i] = '\0'; 
	
}

static void itoaR(int n, char s[])
{ 
	if(n / 10)
		itoaR(n / 10, s);

	s[i++] = n % 10 + '0';  
}
