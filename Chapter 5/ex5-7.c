#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000

#define MAXLEN 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char []);
void writelines(char *lineptr[], int nlines);
void qsort1(char *lineptr[], int left, int right);

main()
{ 
	int nlines;
	char arrline[MAXLEN];

	if((nlines = readlines(lineptr, MAXLINES, arrline)) >= 0){
		qsort1(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0; 
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int getline1(char *, int); 

int readlines(char *lineptr[], int maxlines, char arrline[])
{
	int len, nlines;
	char line[MAXLEN];

	nlines = 0;
	while((len = getline1(line, MAXLEN)) > 0)
		if(nlines >= maxlines)
			return -1;
		else {
			line[len -1] = '\0';
			strcpy(arrline, line);
			lineptr[nlines++] = arrline;
			arrline += len;
		} 
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int k)
{
	char *temp = v[i];
	v[i] = v[k];
	v[k] = temp;
}	

int getline1(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;                                                         
  if (c == '\n') {
    s[i++] = c;   
  }
  s[i] = '\0';
  return i;
}


void qsort1(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort1(v, left, last-1);
    qsort1(v, last+1, right);
}
