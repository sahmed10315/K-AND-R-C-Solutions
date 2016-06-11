#include <stdio.h>

#define MAXLINE 1000

int GetLine(char s[], int lim);

int strindex(char s[], char t[]);

char pattern[] = "ould";

main()
{
        char line[MAXLINE];
        int found = 0;

        while(GetLine(line, MAXLINE) > 0)
                if( (found = strindex(line, pattern)) >= 0){
                        printf("%s %d\n", line, found);
        }
        return found;
}

int GetLine(char s[], int lim)
{
        int c, i;

        i = 0;

        while(--lim > 0 && (c = getchar()) != EOF && c != '\n')

                s[i++] = c;

        if(c == '\n')

                s[i++] = c;

        s[i] = '\0';

        return i;

}

int strindex(char s[], char t[])
{
        int i, j, k;
	int lenS = strlen(s);
	int lenT = strlen(t);
 
        for(i = lenS - 1; i >= lenT -1 ; i--){
                for(j = i, k = lenT - 1;  k >= 0 && s[j] == t[k]; j--, k--)
                        ; 
                if(k == -1)
                        return i - lenT + 1;
        }
        return -1;
}

