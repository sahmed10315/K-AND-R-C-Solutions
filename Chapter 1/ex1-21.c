#include <stdio.h>
 
#define MAXLINE 1000

#define TABSTOP 10 

int getLine(char line[], int maxline);
 
void entab(char line[], char final[]);
  
int main()
{

        int len;


        char line[MAXLINE];

        char final[MAXLINE];    
 
        while((len = getLine(line, MAXLINE)) > 0) 
        { 
              entab(line, final);

              printf("%s : %s", line, final);

        }
 
        return 0;
 
}

void entab(char line[], char final[])
{
	
        int i = 0, j = 0, tabs, blanks;
	while((final[j] = line[i]) != '\0') 
              { 
                     if(final[j] == ' ') 
                     {

                            int n;

                            for(n =0; line[i] == ' '; n++,i++)

                            ;

                            tabs = n / TABSTOP;

                            blanks = n % TABSTOP;

                            for(int k =0; k < tabs; k++) 
                                   final[j++] = 'T';

                            for(int l =0; l < blanks; l++) 
                                   final[j++] = 'S';
 
                     }else 
                     { 
                            i++; j++; 
                     }

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
