#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c;
	int inblank = OUT;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' )
			if (inblank == OUT)
			{
				inblank = IN;
				putchar(c);
			}
		if(c != ' ')	
		{
			putchar(c);
			inblank = OUT;
		}
	}
}
