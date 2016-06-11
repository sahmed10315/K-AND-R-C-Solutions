#include <stdio.h>
#include <string.h>

void reverse(char s[], int i , int k);

main()
{
	char s[] = "Saad Ahmed";
	reverse (s, 0, strlen(s) - 1);
	printf("%s\n", s);
}

void reverse(char s[], int i , int k)
{
	if(i < k)
	{
		int c;
		c = s[i];
		s[i] = s[k];
		s[k] = c;

		reverse(s, i+1, k-1);
	} 
}
