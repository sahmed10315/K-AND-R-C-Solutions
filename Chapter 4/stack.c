#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
extern double var[];

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
  if(sp > 0)
    return isalpha(val[--sp]) ? var[(char)val[sp] - 'A'] : val[sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek(void)
{
  if(sp > 0)
    return val[sp - 1];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}
void print(void)
{
	for(int i = 0; i < sp; i++)
        printf("\t%.8g ", val[i]);
		
}

void printV(void)
{
	for(int i = 0; i < 26; i++)
        printf("%c: %f\n", i + 'A', var[i]);
		
}

void duplicate(void)
{
  int p = sp - 1;
  if(sp < MAXVAL)
    val[sp++] = val[p];
  else
    printf("error: stack full, can't push %g\n", val[p]);
}


void swap(void)
{
	int t = val[sp - 1];
	val[sp - 1] = val[sp - 2];
	val[sp - 2] = t;
}

void clear(void)
{
	sp = 0;
}
