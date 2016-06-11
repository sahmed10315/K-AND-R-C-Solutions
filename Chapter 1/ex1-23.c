#include <stdio.h>
 
#define MAXLINE 1000
#define IN 1
#define OUT 0
#define PARA 2

int getLine(char line[], int maxline);

int main()
{
        int len;
        char line[MAXLINE];
 
	int state = OUT;

        while((len = getLine(line, MAXLINE)) > 0)
        {
             
		for(int i =0; i < len; i++)
		{
			
			if(line[i] == '/' && line[i + 1] == '*' && state != PARA)
 				state = IN;
			else if(line[i] == '*' && line[i + 1] == '/' && state != PARA){
				state = OUT;
				 i+=2;
			}
			else if(line[i] == '"' && line[i-1] != '\'' && line[i+1] != '\'')
				if(state == PARA)
					state = OUT;
				else
					state = PARA;

			if(state == OUT || state == PARA)
				putchar(line[i]);
		} 

        }
         return 0;
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

         s[i] = '\0'; /* This is a comment
		and must be removed */
 printf("This is inside /* a comment */ print");
         return i;

}

 
 


