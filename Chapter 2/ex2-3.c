#include <stdio.h>
#include <ctype.h>

int htoi (char s[]);

main()
{

	printf("%d\n", htoi("12gF3"));
	printf("%d\n", htoi("0X0C0BE"));	
}

int htoi(char s[])
{
 	int i=0 , n = 0;
	
	if(s[0] == '0' && tolower(s[1]) == 'x')
		i = 2;
 
	for(; isalnum(s[i]) ;i++)
	{
 
		if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F')
			n = 16 * n + (10 + toupper(s[i]) -'A');
		else if(isdigit(s[i]))
			n = 16 * n + (s[i] - '0');
		else
			printf("Invalid hex character. %c. Ignoring\n", s[i]);
	}

	return n; 
}
