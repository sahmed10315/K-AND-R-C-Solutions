/*fsize: print size of file "name" */
void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
	/* Print all fields of the struct stat */
    printf("%8ld - %8ld - %8ld - %8ld - %8ld - %8ld %s\n", stbuf.st_size, stbuf.st_blocks, stbuf.st_blksize, stbuf.st_flags, stbuf.st_gen, stbuf.st_nlink, name);

}