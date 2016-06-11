#include <stdio.h>

void strcat1(char *s, char *t);

main()
{
	char s[100] = "Saad Ahmed";

	char *t = "Dork";
	strcat1(s, t);
	printf("%s\n", s);	
}

void strcat1(char *s, char *t)
{ 
	while(*s)
		s++;
	while(*s++ = *t++);
}
