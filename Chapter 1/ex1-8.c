#include <stdio.h>
/* Program to count new line, blanks and tabs */
main()
{
	int c, nl, bl, tb;
	nl = 0; bl = 0; tb = 0;

	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			nl++;
		if(c == '\t') 
			tb++;
		if(c == ' ')
			bl++;
	}

	printf("NewLine: %d Tabs: %d Blanks: %d\n", nl, tb, bl);

}
