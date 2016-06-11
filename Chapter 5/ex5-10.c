/* this program forms the basis on which exercises 4-3 through 4-10 build */

#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */ 
 
void push(double);
double pop(void); 

/* reverse Polish calculator */
double var[26];

int main(int argc, char *argv[])
{ 
  int type;
  double op2;
 
  for(int i = 1; i < argc; i++) 
  {
	   if(isdigit(argv[i][0]))
		push(atof(argv[i]));
	   else
	   {
		    switch(argv[i][0])
		    { 
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
		      case '\n':
			printf("\n");
			break;
		      default: 
				printf("error: unknown command \n");
			break;
		    }
  	}
   }
  printf("%g\n", pop());
  return 0;
}

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

