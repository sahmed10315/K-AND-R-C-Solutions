
int fclose(FILE *f)
{
    int fd;
    
    if (f == NULL)
        return -1;
    
    fflush(f);
    f->cnt = 0;
    f->ptr = NULL;
	
    if (f->base != NULL)
        free(f->base);
	
    f->base = NULL;
    f->flag = 0;
	fd = f->fd;
    f->fd = -1;
	
    return close(fd);
}