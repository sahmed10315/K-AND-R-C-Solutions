/* this program forms the basis on which exercises 4-3 through 4-10 build */

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

int getch(void);
void ungetch(int);
void ungets(char s[]);

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
