#include <stdio.h>

int any(char s[], char s1[]);
int contains(char s[], char c);
main()
{
	char s[] = "ggggigggoriginal";
	
	printf("%s %d\n", "original", any(s, "aio"));

}

int contains(char s[], char c)
{
	int i = 0;
	while(s[i] != '\0')
		if(s[i++] == c)
			return 1;
	return 0;
}
int any(char s[], char s1[])
{

	int i;

	for(i=  0; s[i] != '\0'; i++)
		if(contains(s1, s[i]))
			return i;
	return -1;
}
