#include <stdio.h>

/* All input spaces with a new line counts as a word, which is not correct */
/* Also empty new lines counts as word */

#define IN 1
#define OUT 0

main()
{
	int c, nl, nw, nc, state;

	state = OUT;

	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c== '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			++nw;
		}
	}

	printf("Newline: %d Words: %d Character: %d \n", nl, nw ,nc);
}
