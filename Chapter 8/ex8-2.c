#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define PERMS 0666

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _flags{
	int _READ;
	int _WRITE;
	int _UNBUF;
	int _EOF;
	int _ERR;
}flags;

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	struct _flags flags;
	int fd;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])


int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

int _fillbuf(FILE * fp)
{
	int bufsize;
	
	if (!(fp->flags._READ))
		return EOF;
	
	bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ;
	
	if (fp->base == NULL)
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	
	if(--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flags._EOF = 1;
		else
			fp->flags._ERR = 1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}


FILE *fopen (char *name, char * mode)
{
	int fd;
	FILE *fp;
	
	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	
	for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if (fp->flags._READ == 0 && fp->flags._WRITE == 0)
			break;
	
	if (fp >= _iob + OPEN_MAX)
		return NULL;
	
	if(*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open (name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	
	if(fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	if(*mode == 'r')
		fp->flags._READ = 1;
	else
		fp->flags._WRITE = 1; 
	return fp;
}