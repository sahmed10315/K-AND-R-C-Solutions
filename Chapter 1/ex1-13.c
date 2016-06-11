#include <stdio.h>
/* Histogram program */
#define IN 1
#define OUT 0
#define LENGTH 15

main()
{
	int c, count = 0;
	int words[LENGTH];
        int inblank = OUT;

	for(int i = 0; i < LENGTH; i++)
		words[i] = 0;


	while((c = getchar()) != EOF){
	
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if (inblank == OUT)
			{
				words[count]++;
				inblank = IN;
				count = 0;
			}
		}
		else
		{
			inblank = OUT;
			count++;
		}
	}

	if(count > 0)
		words[count]++;

 	printf("\nLENGTH COUNT\n");

	for(int i = 0; i < LENGTH; i++)
	{
		printf("%3d: ", i);
		
		for ( int n = 0 ; n < words[i]; n++)
			putchar('*');
	
		putchar('\n');

	}
	printf("\n Vertical Histogram: \n\n");
	
	int max = 0;

	for (int i = 0; i < LENGTH; i++)
	{
		printf("%d\t", i);
		if(words[i] > max)
			max = words[i];
	}
	putchar('\n');

	for (int j = 0; j < max; j++)
	{	
		for(int i = 0 ; i < LENGTH ; i++)
		{
			if(words[i]-- > 0)
				putchar('*');
			putchar('\t');
		
		}
		printf("\n");
	}
}

