#include <stdio.h>

void squeeze(char s[], char s1[]);
int contains(char s[], char c);
main()
{
	char s[] = "original";
	squeeze(s, "agio");
	
	printf("%s %s\n", "original", s);

}

int contains(char s[], char c)
{
	int i = 0;
	while(s[i] != '\0')
		if(s[i++] == c)
			return 1;
	return 0;
}
void squeeze(char s[], char s1[])
{

	int i, j;

	for(i = j = 0; s[i] != '\0'; i++)
		if(!contains(s1, s[i]))
			s[j++] = s[i];

	s[j] = '\0';
}
