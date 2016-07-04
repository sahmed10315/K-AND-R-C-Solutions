/* This program uses scanf instead of getch and ungetch */

#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */ 

int getop(char []);
void push(double);
double pop(void);
void print(void);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void printV(void); 

/* reverse Polish calculator */
double var[26];

int main(void)
{
  double asinh(double);
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

#include <ctype.h>
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;
	
  scanf("%c", c);
  while((s[0] = c) == ' ' || c == '\t')
    scanf("%c", c);

  s[1] = '\0';
  if(!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
    return c; /* not a number */
  
  char v = 0;

  i = 0;
  if(isalpha(c))
   {
	v = c;
	scanf("%c", c);
	if(c != '=')
	{
		ungetch(c);
		return v;
	}
	scanf("%c", c);
	s[i] = c;
   }

  if(c == '-')
  {
	scanf("%c", c);
    while(isdigit(s[++i] = c))
		scanf("%c", c);
  }
  
  if(isdigit(c)) {
	  scanf("%c", c);
    while(isdigit(s[++i] = c))
      scanf("%c", c);;
  }
  
  if(c == '.')
  {
	scanf("%c", c);
    while(isdigit(s[++i] = c))
      scanf("%c", c);
  }
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
 