#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

main()
{
	char *s = "Saad Ahmed Dorke";
	char *t = "Dorke";
	printf("%d\n", strend(s, t));
}

int strend(char *s, char *t)
{
	int i; 

	int inc = strlen(s) - strlen(t);

	while(inc-- > 0)
		s++;

	for(; *s++ == *t++; )
		if(*s == '\0' && *t == '\0')
			return 1;
	return 0;
} 
