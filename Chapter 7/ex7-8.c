#include <stdio.h>
#include <stdlib.h>

#define LINES_PER_PAGE 60

void print_file(char *filename);

int main(int argc, char *argv[])
{
	  int i;

	  if (argc < 2) {
			fputs("No files specified\n", stderr);
			exit(1);
	  }
	  for (i = 1; i < argc; i++) {
			print_file(argv[i]);
	  }
	  return 0;
}

void print_file(char *filename)
{
	  FILE *f;
	  int pagenumber = 1;
	  int linecount;    
	  int c;        
	  int newpage = 1;
	 
	  if ((f = fopen(filename, "r")) != NULL) {
		while ((c = fgetc(f)) != EOF) {
		  if (newpage) {
				printf("[%s] page %d starts\n", filename, pagenumber);
				newpage = 0;
				linecount = 1;
		  }                
		  putchar(c);
		  if (c == '\n' && ++linecount > LINES_PER_PAGE) { 
				printf("[%s] page %d ends\n", filename, pagenumber); 
				putchar('\n');
				newpage = 1;
				pagenumber++;
		  }              
		} 
		if (!newpage) { 
			printf("[%s] page %d ends\n", filename, pagenumber);
		} 
		putchar('\n');    
		fclose(f);
	  } 
}
