#include <stdio.h>
#define IN 1
#define OUT 0

main()
{
	int c;
	int state;

	while((c = getchar()) != EOF)
	{
		state = OUT;
		if(c == '\t')
		{
			printf("%s" , "\\t");
			state = IN;
		}
		if(c== '\b')	
		{
			printf("%s", "\\b");
			state = IN;
		}
		if(c == '\\')
		{
			printf("%s" , "\\\\");
			state = IN;
		}
		if(state == OUT)
			putchar(c);
	}
}
