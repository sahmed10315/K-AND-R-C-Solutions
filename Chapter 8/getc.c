#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
	_READ = 01,
	_WRITE = 02,
	_UNBUF = 04,
	_EOF = 010,
	_ERR = 020
};

FILE _iob[OPEN_MAX] = {
	{0, (char *) 0, (char *) 0, _READ, 0},
	{0, (char *) 0, (char *) 0, _WRITE, 1},
	{0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
				? (unsigned char) *(p)->ptr++ : _fillbuf(p))
				
#define putc(x, p) (--(p)->cnt >= 0 \
				? *(p)->ptr++ = (x) : _flushbuf((x), p)
				
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

int _fillbuf(FILE * fp)
{
	int bufsize;
	
	if ((fp->flag & (_READ | EOF | _ERR)) != _READ)
		return EOF;
	
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	
	if (fp->base == NULL)
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	
	if(--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}