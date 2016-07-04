int isupper(int c)
{
    return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
}

int isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}