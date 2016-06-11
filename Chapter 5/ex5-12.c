
#include <stdio.h>
#include <stdlib.h> 
#define MAXLINE 1000

#define TABSTOP 10
 
int getLine(char line[], int maxline);

void detab(char final[], char line[]);
void settab(char line[], int len, int m, int n);

int main(int argc, char *argv[])
{ 
	int m = 0;
	int n = 0;
	if (argc == 3)
	{
		if((*++argv)[0] == '-')
			m = atoi(++argv[0]);
		if((*++argv)[0] == '+')
			n = atoi(++argv[0]);
	}
 
        int len;
        char line[MAXLINE];
        char final[MAXLINE];    
 
        while((len = getLine(line, MAXLINE)) > 0)
        {
	       settab(line, len, m, n + 1);
               detab(final, line);
               printf("%s : %s", line, final);

        }
 
        return 0;
 
}

void settab(char line[], int len, int m, int n)
{
	for(int i = m; i < len; i+=n)
	{ 
			line[i] = '\t';
	}
}

void detab(char final[], char line[])
{
	int i = 0;
	int j= 0;
       
	while((final[j] = line[i]) != '\0')
       {

             if(final[j] == '\t')        
             {

                    for(int n =0; n < TABSTOP; n++, j++) 
                           final[j] = 'x';

             } else 
                    j++;

             i++; 
      }

}

int getLine(char s[], int lim)
{

        int c, i; 
        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i) 
                s[i] = c; 

        if(c == '\n'){

              s[i] =c;

              ++i;

       }
 
        s[i] = '\0';
 
        return i;

}
