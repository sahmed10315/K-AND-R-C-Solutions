#include <stdio.h>
/* Histogram to print frequencies of characters */
#define IN 1
#define OUT 0
#define LENGTH 93 

main()
{
	int c, count = 0;
	int words[LENGTH];

	for(int i = 0; i < LENGTH; i++)
		words[i] = 0;


	while((c = getchar()) != EOF){
	
		if(c != ' ' && c != '\n' && c != '\t')
		{
			if(c >= '!' && c <= '~')
				words[c - '!']++;
		}
	}


 	printf("\nLENGTH COUNT\n");
	
	c = '!';

	for(int i = 0; i < LENGTH; i++)
	{
		printf("%3c: ", c++);
		
		for ( int n = 0 ; n < words[i]; n++)
			putchar('*');
	
		putchar('\n');

	}
}

