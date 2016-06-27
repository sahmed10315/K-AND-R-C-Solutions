#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
		int c;
		
		if (argc < 2)
		{
			printf("Please enter lower or upper.");
			exit(0);
		}
		
		while((c = getchar()) != EOF)
		{
		
			if(strcmp(argv[1], "lower") == 0)
				putchar(tolower(c));
			else
				putchar(toupper(c));
		}
		return 0;
}