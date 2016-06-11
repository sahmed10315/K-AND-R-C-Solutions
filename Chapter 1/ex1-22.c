#include <stdio.h>

#define MAXLINE 1000
#define SHORT 20

int getLine(char line[], int maxline);
void copy(char shortline[] , char line[], int start, int end);
  
void foldlines(char line[], char shortline[], int lines);

int main()
{
       int len;
       char line[MAXLINE];

       char shortline[SHORT];    
 
       while((len = getLine(line, MAXLINE)) > 0)
       {  
		if(len / SHORT > 0)
		{
			int lines = len / SHORT;
			if(len % SHORT > 0)
				lines++;
		
			foldlines(line, shortline, lines);
			
		}else
                printf("Long line: %s", line);
        } 
        return 0;
 
}

void foldlines(char line[], char shortline[], int lines)
{
	int start = 0;
	for(int i = 1; i <= lines; i++)
	{ 
		int end;
		for( end = SHORT * i; line[end] != ' '; end--);

		copy(shortline, line, start, end);
		start = end;
		printf("short line: %s\n", shortline);
	}
}

void copy(char shortline [] , char line [], int start, int end)
{
	int i;
	i = 0;
	while((shortline[i] = line[start]) != '\0' && start < end) 
	{	++i;
		++start;
	}
	shortline[i] = '\0';
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

 
