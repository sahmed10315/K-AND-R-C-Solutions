#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000

#define DEFAULT 1

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int dlines, int nlines);


int main(int argc, char *argv[])
{

        int dlines = 0;

        if(argc > 1 && (*++argv)[0] == '-'){

                dlines = atoi(++argv[0]);

        }

 
        int nlines ;
 
        nlines = readlines(lineptr, MAXLINES);
 
        if(dlines == 0 || nlines < dlines)
                writelines(lineptr, DEFAULT, nlines);
        else
                writelines(lineptr, dlines, nlines);
	return 0;
}
 

#define MAXLEN 1000

int getLine(char [], int);

char *alloc(int);


int readlines(char *lineptr[], int maxlines)
{

        int len, nlines;

        char *p, line[MAXLEN];

        nlines = 0;

        while((len = getLine(line, MAXLEN)) > 0)

                if(nlines >= maxlines || (p = malloc(len)) == NULL)
                        return -1;
                else {

                        line[len - 1] = '\0';

                        strcpy(p, line);

                        lineptr[nlines++] = p;

                }

        return nlines;

}

 

void writelines(char *lineptr[], int dlines, int nlines)
{

        int i;

        for (i = nlines - dlines; i < nlines; i++)

                printf("%s\n", lineptr[i]);

}

int getLine(char s[], int lim)
{
        int c, i;

        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
      

        if(i == lim - 1 && c != '\n' && c != EOF){
            

                printf("Extra characters: ");

                while((c = getchar()) != '\n'){

                 ++i;

                putchar(c);

                }

        }

 

        if(c == '\n' && i < lim - 1){

                s[i] = c;      

                ++i;

                s[i] = '\0';

 

        }else

                s[lim - 1] = '\0';

 

        return i;

}
