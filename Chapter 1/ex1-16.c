#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);

void copy(char to[], char from[]);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0; 

	while((len = getLine(line, MAXLINE)) > 0)
	{
		if(line[len ] != '\0'){
			line[len - 1] = '\0';
			printf("\nTotal length %d\n" , len);
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		} 
	}

	if(max > 0)
		printf("%s\n", longest);

	return 0;
   
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

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
