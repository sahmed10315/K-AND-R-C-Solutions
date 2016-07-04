#include <stdio.h>
#include <stdlib.h>

char *fgets(char *s, int n, FILE *iop);

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int max = 80;
	char *prog = argv[0];

	if(argc != 3)
	{
		fprintf(stderr, "%s: Error provide input and output file on command line\n", prog);
		exit(1);
	}
	
	if ((fp1 = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "%s: cant open %s\n", prog, *argv);
		exit(2);
	}
	
	if ((fp2 = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "%s: cant open %s\n", prog, *argv);
		exit(2);
	}
	
	char line1[80], line2[80];
	while(fgets(line1, max, fp1) != NULL && fgets(line2, max, fp2) != NULL)
			if(strcmp(line1, line2) != 0)
				printf("%s: %s", line1, line2);
			
	return 0;
	
}
