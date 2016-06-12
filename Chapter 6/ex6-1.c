#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char *, int);
int bettergetword(char *word, int lim);

struct key {
	char * word;
	int count;
} keytab [] = {
	"auto", 0,	
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"for", 0,
	"int", 0,
	"return", 0,
	"struct", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

int binsearch1(char *, struct key *tab, int);

#define NKEYS (sizeof keytab / sizeof keytab[0])

/* count C Keywords */
int main() 
{
	int n;
	char word[MAXWORD];

	while (bettergetword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch1(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;

	for(n = 0; n < NKEYS; n++)
		if(keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch1(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0; 
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;

		if((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;	
	}

	return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for( ; --lim > 0; w++)
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	printf("\n%s\n", word);
	return word[0];
}

int bettergetword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    int t;

    while (isspace(c=getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        if (c == '\"') { /*string constant*/
            for(c=getch(); c!= '\"'; c=getch()) 
                ; 
        }
        else if (c == '#') { /*preprocessor*/
            for(c=getch(); c!= '\n'; c=getch()) 
                ;
        }
        else if (c == '/')  /*comment*/
            if ((c=getch()) == '/') { /*single comment*/
                for(c=getch(); c!= '\n'; c=getch()) 
                    ;
            }
            else if (c == '*') { /*mutiline comment*/
                for(c=getch(),t=getch(); c!= '*' && t!= '/'; c=getch(), t=getch()) 
                    ungetch(t);
            }
            else ungetch(c);
        else /*underscore*/
            for( ; !isspace(c) && c!=EOF; c=getch()) 
                ;
        if (c != '\"' && c!='\n' && c!='/') 
            ungetch(c);
        *w = '\0';
        return c;
    }
    
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            if (!isspace(*w)){
                ungetch(*w);
                return (*w);
            }
            else {
                ungetch(*w);
                break;
            }
        }
    *w = '\0';
printf("\n%s\n", word);
    return word[0];
}

