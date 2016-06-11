#include <stdio.h>

void expand(char s1 [], char s2 []);

main()
{

       char s2[100];

      expand("a-b-c0-9a-z",s2);

       printf("%s\n", s2);

}

void expand(char s1[], char s2[])
{
       int j = 0, c, i = 0;

       while(s1[i] != '\0')
       {
              if(s1[i] == '-')
                     i++;

              for( c = s1[i]; c <= s1[i + 2]; c++, j++)
                     s2[j] = c;
             i+=3;
	     if(s1[i] == '-')
		i--;
 
       }

       s2[j] = '\0';
}

