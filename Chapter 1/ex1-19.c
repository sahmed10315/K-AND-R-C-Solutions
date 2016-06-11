#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);

void reverse(char to[], char from[], int len);

main()
{
        int len;
        int max;
        char line[MAXLINE];
        char final[MAXLINE];    

        while((len = getLine(line, MAXLINE)) > 0)
        {
		reverse(final, line, len);

		printf("%s : %s\n",line,final);
        }


        return 0;
   
}

int getLine(char s[], int lim)
{
 
        int c, i;

        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
        
        s[i] = '\0';


        return i;
}

void reverse(char to[], char from[], int len)
{
        int i = 0;
	int j = len - 1;
        while(j >= 0)
		to[i++] = from[j--]; 
	to[i] = '\0';
}
