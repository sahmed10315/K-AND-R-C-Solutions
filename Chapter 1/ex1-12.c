/* Program prints its input one word per line */
#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c;
	int inblank = OUT;

	while((c = getchar()) != EOF) {

		if(c == ' ' || c == '\t'){
			if(inblank == OUT) {
				inblank = IN;
				putchar('\n');
			}
		}else {
			inblank = OUT;
			putchar(c); 
		}
	}

}
