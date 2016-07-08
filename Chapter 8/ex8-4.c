
int fseek(FILE *fp, long offset, int origin)
{
    if ((fp->flags._UNBUF == 0) && base != NULL) { 
        if (fp->flags._WRITE) { 
            fflush(fp); 
        } else if (fp->flags._READ) {
            fp->cnt = 0;
            fp->ptr = fp->base;
        }
    }
    return lseek(fp->fd, offset, origin);
}