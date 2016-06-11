#include<stdio.h>
#include<string.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
char ch;

int getch(void) /* get a (possibly pushed back) character */
{
  if(bufp == 1)
  {
	bufp--;
	return ch;
  }
  else
	getchar();
}

void ungetch(int c) /* push character back on input */
{
  if(bufp == 1)
    printf("ungetch: Full\n");
  else if(c != EOF)
  {
    ch = c;
    bufp++;
  }
}

void ungets(char s[])
{	
	int len = strlen(s);

	if(len + bufp >= BUFSIZE)
	    printf("ungets: too many characters\n");
	else
		for(int i = len - 1; i >=0; i--)
			buf[bufp++] = s[i];
		
}
