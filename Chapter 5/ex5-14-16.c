#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort1(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);
int strcmp1(char* s1, char* s2);

int strcmp_d(char* s, char* t);
int strcmp_fd(char* s, char* t);
int strcmp_f(char* s, char* t);
void reverse1(void *s[], int);
int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0, reverse = 0, fold = 0, directory = 0, c;
	
	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch(c){
				case 'n':
					numeric =1;
					break;
				case 'r':
					reverse =1;
					break;
				case 'f':
					fold = 1;
					break;
				case 'd':
					directory = 1;
					break;
				default:
					printf("Invalid option\n");
					break;
			} 

	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		if(numeric)
			qsort1((void **) lineptr, 0, nlines -1, (int (*)(void*, void*))(numcmp));
		else if(fold)
		{
			if(directory)
				qsort1((void **) lineptr, 0, nlines -1, (int (*)(void*, void*))(strcmp_fd));
			else
				qsort1((void **) lineptr, 0, nlines -1, (int (*)(void*, void*))(strcmp_f));
			
		}else if(directory)
			qsort1((void **) lineptr, 0, nlines -1, (int (*)(void*, void*))(strcmp_d));
		else 
			qsort1((void **) lineptr, 0, nlines -1, (int (*)(void*, void*))(strcmp1));

		if(reverse)
			reverse1((void **)lineptr, nlines);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void reverse1(void *s[], int len)
{
	void * c;
	int i, j;

	for(i = 0, j = len - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void qsort1(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort1(v, left, last - 1, comp);
	qsort1(v, last+1, right, comp);
}

int strcmp1(char* s, char* t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    return *s - *t;
}

int strcmp_f(char* s, char* t)
{
    for ( ; toupper(*s) == toupper(*t); s++, t++)
        if (*s == '\0')
            return 0;

    return toupper(*s) - toupper(*t);
}

int strcmp_d(char* s1, char* s2)
{
    while(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
		++s1;       /* ignore bad characters */
    while(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
		++s2;       /* ignore bad characters */

    for ( ; (*s1) == (*s2); s1++, s2++)
    {
        if (*s1 == '\0')
            return 0;

	while(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
		++s1;       /* ignore bad characters */
	while(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
		++s2;       /* ignore bad characters */
   }
    return (*s1) - (*s2);
}

int strcmp_fd(char* s1, char* s2)
{
    while(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
		++s1;       /* ignore bad characters */
    while(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
		++s2;       /* ignore bad characters */

    for ( ; toupper(*s1) == toupper(*s2); s1++, s2++)
    {
        if (*s1 == '\0')
            return 0;

	while(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
		++s1;       /* ignore bad characters */
	while(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
		++s2;       /* ignore bad characters */
   }
    return toupper(*s1) - toupper(*s2);
}

int numcmp(char * s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else 
		return 0;
}
 
void swap(void *v[], int i, int k)
{
	void *temp;
	temp = v[i];
	v[i] = v[k];
	v[k] = temp;
}
 
#define MAXLEN 1000

int getLine(char [], int);

char *alloc(int);
 
int readlines(char *lineptr[], int maxlines)
{
        int len, nlines;
        char *p, line[MAXLEN];
        nlines = 0;
        while((len = getLine(line, MAXLEN)) > 0)
                if(nlines >= maxlines || (p = malloc(len)) == NULL)
                        return -1;
                else {
                        line[len - 1] = '\0';
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                }
        return nlines;
}
 
void writelines(char *lineptr[], int nlines)
{
      int i;
	printf("\n\n");
       for (i = 0; i < nlines; i++)
                printf("%s\n", lineptr[i]);
}

int getLine(char s[], int lim)
{
        int c, i;

        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
   
        if(i == lim - 1 && c != '\n' && c != EOF){
                 printf("Extra characters: ");

                while((c = getchar()) != '\n'){
                 ++i;
                putchar(c);
                }
        }
 
        if(c == '\n' && i < lim - 1){
                s[i] = c;      
                ++i;
                s[i] = '\0';
        }else
                s[lim - 1] = '\0';
 
        return i;

}
