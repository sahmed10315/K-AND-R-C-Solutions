#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "calc.h"
/* reverse Polish calculator */
double var[26]; 

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if(!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
    return c; /* not a number */
  
  char v = 0;

  i = 0;
  if(isalpha(c))
   {
        v = c;
	if((c = getch()) != '=')
	{
		ungetch(c);
		return v;
	}
	c = getch();
	s[i] = c;
   }

  if(c == '-')
     while(isdigit(s[++i] = c = getch()))
	;

  if(isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  
  if(v != 0)
  {
	var[v - 'A'] = atof(s);
	return v;
  }
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}
