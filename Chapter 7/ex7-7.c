#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char *line, int max, FILE *fp); 

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	FILE *fp;
	char *prog = argv[0];

	if(argc < 2)
	{
		fprintf(stderr, "%s: Usage: find pattern [optional file name]...\n", prog);
		exit(1);
	}
	else if(argc == 2)
	{
		while(getline(line, MAXLINE, stdin) > 0)
				if(strstr(line, argv[1]) != NULL) {
					printf("%s", line); 
				}
	} else {
		char *substr = *++argv;

		while(--argc > 1) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
					fprintf(stderr, "%s: cant open %s\n", prog, *argv);
					exit(2);
			} else {
				while(getline(line, MAXLINE, fp) > 0)
					if(strstr(line, substr) != NULL) {
						printf("%s: %s\n", line, *argv); 
					}
				fclose(fp);
			} 
		}
	}
	
	exit(0);
}
	
/* getline: read a line, return length */
int getline(char *line, int max, FILE *fp) 
{
	if(fgets(line, max, fp) == NULL)
		return 0;
	else
		return strlen(line);
}