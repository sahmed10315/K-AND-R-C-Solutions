#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"

#define MAXOP 100 /* max size of operand or operator */

extern double var[];

int main(void)
{ 
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF)
  {
    switch(type)
    { 
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
       case '%':
	 	op2 = pop();
	 	push((int)pop() % (int)op2);
	 	break;
	case '#':
	 printf("Peek : %g\n", peek());
	break;
	case '!':
	 duplicate();
	break;
	case '~':
	swap();
	break;
	case '@':
	/*  push(asinh(npop()));*/
	  break;
	case '^':
	/*  push(cos(npop()));*/
	  break;
	case '(':
	/*  push(pow(npop(), 2)); */
	  break;	
	case '=':
	 printV();
	break;
      case '\n':
	print();
	printf("\n");
        break;
      default:
	if(isalpha((char)type))
		push(var[type - 'A']);
	else
        	printf("error: unknown command %s\n", s);
        break;
    }
  }

  return 0;
}

