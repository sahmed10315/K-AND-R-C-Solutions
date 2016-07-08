#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
void filecopy(int, int);

int main(int argc, char *argv[])
{
	int fd;
	void filecopy(int, int);
	
	char *prog = argv[0];
	
	if(argc == 1)
		filecopy(0, 1);
	else
		while(--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
				fprintf(stderr, "%s: cant open %s\n", prog, *argv);
				exit(1);
			} else {
				filecopy(fd, 1);
				close(fd);
			}
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout \n", prog);
		exit(2);
	}
	exit(0);
}

void filecopy(int ifp, int ofp)
{
	int c;	
	while((read(ifp, &c, 1)) == 1)
		write (ofp, &c, 1);
}