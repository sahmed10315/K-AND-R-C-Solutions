#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);

void copy(char to[], char from[], int start);

main()
{
        int len;
        int max;
        char line[MAXLINE];
        char final[MAXLINE];    

        while((len = getLine(line, MAXLINE)) > 0)
        {
       		int i; 
                for(i = 0; i < MAXLINE && (line[i] == ' ' || line[i] == '\t'); i++);
                
		if(line[i] != '\n'){        
               		 copy(final, line, i);
		
        	        printf("%s", final);
		}
        }


        return 0;
   
}

int getLine(char s[], int lim)
{
 
        int c, i;

        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
        
        if(c == '\n' ){
                s[i] = c;
                ++i;
        }
        s[i] = '\0';


        return i;
}

void copy(char to[], char from[], int start)
{
        int i;
        i = 0;
        while((to[i++] = from[start++]) != '\0');
}
