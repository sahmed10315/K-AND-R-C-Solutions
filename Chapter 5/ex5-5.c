#include <stdio.h>

void strncpy1(char *s, char *t, int n);
void strncat1(char *s, char *t, int n);
int strncmp1(char *s, char *t, int n);

main()
{
	char s[100];
	char *t = "Saad Ahmed";
	strncpy1(s, t, 6);
	printf("%s\n", s);
	strncat1(s, t, 8);
	printf("%s\n", s);
	char *s1 = "Iqrar ho na";
	char *t1 = "Iqrar ho na yahoo";

	printf("%d\n", strncmp1(s1, t1, 5));
}

void strncpy1(char *s, char *t, int n)
{
	while (n-- > 0)
		*s++ = *t++;
	*s = '\0';
}

void strncat1(char *s, char *t, int n)
{ 
	while(*s)
		s++;
	while(n-- > 0)
		*s++ = *t++; 

	*s = '\0';
}

int strncmp1(char *s, char *t, int n)
{
	for( ; *s == *t && n > 0; s++, t++, n--)
		if(*s == '\0') 
			return 0; 
	return *s - *t;
}
