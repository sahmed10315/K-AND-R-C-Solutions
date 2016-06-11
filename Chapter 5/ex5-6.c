#include <stdio.h>
#include <string.h>
#define NUMBER '0'
#define BUFSIZE 1000

int getline1( char *s, int lim);
int atoi(char *s);
char * itoa(int n, char *s);
void reverse(char *s);

int getop(char *s);

main()
{ 
	char line[100];
	int len = getline1(line, 100);
	printf("%d \n%s\n", len, line);
	printf("%d \n", atoi("1235"));
	char str[10];
	char * p = itoa(-12345, str);
	printf("%s\n", p);
	printf("index: %d\n", strindex1("saad ahmed", "med"));
}
char buf[BUFSIZE];              /* The Stack */
int  bufp = 0;                  /* Top Position on the stack */

int getch (void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
        if (bufp >= BUFSIZE) {
                printf("ungetch: too many characters.\n");
        } else {
                buf[bufp++] = c;
        }

}
int strindex(char *s, char *t)
{
	int i, k, l;
	for(i = 0; s[i] != '\0'; i++){
		for(k = i, l = 0; t[l] != '\0' && s[k] == t[l] ; k++, l++)
		;
		if(l > 0 && t[l] == '\0')
			return i;
	}
	return -1;
}

int strindex1(char *s, char *t)
{ 
	char * str = s;
	int l;
	for(; *s != '\0'; s++){
		char *s1 = s;
		char *t1 = t;

		for( l = 0; *t1 != '\0' && *s1 == *t1 ; s1++, t1++, l++)
		;
		if(*t1 == '\0' && l > 0)
			return s1 - str - l;
	}
	return -1;
}

int getop(char *s)
{
  int c;

  while((*s = c = getch()) == ' ' || c == '\t')
    ;

  *(s + 1) = '\0';

  if(!isdigit(c) && c != '.')
    return c; /* not a number */ 
  if(isdigit(c)) /* collect integer part */
    while(isdigit(*++s = c = getch()))
      ;
  if(c == '.')
    while(isdigit(*++s = c = getch()))
      ;
  *++s = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}


int getline1(char *s, int lim)
{
	int c, i;
	char *p = s;

	for(; lim-- > 0 && (c = getchar()) != EOF && c!='\n'; )
		*s++ = c;
 	 
	if(c == '\n' )
		*s++ = c;	 
	
	*s = '\0';
 
	return s - p;
}

char * itoa(int n, char *s)
{
	char *p = s;
	int sign;
	
	if((sign = n) < 0)
		n = -n;
 
	do {
		*s++ = n % 10 + '0';
	} while (( n /= 10) > 0);
	
	if(sign < 0)
		*s++ = '-';

	*s = '\0';

	reverse(p);
	return p;
}

void reverse(char *s)
{
	int c;
	char * p = s;

	while(*p)
		p++; 
	p--;
	for(; s < p; s++, p--){ 
		c =  *s;
		*s = *p;
		*p = c;
	}
}

int atoi(char *s)
{
	int n = 0, sign;
	for( ;isspace(*s); s++)
		;

	sign = (*s == '-' ) ? - 1: 1;

	if(*s == '+' || *s == '-')
		s++;
  
	for( ; isdigit(*s); s++)
		n = 10 * n + (*s - '0');

	return sign * n;
}


