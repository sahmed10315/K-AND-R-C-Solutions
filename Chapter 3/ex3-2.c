#include <stdio.h>
 
void escape(char s[], char t[]);

void unescape(char s[], char t[]);
 
main()
{

   char t[30];

   char s[30];

   escape("Saad	 	d\n Ah med", t);
 
   printf("Escape: %s\n", t);

   unescape(t, s);

   printf("Unescape: %s\n", s);

}
 
void escape(char s[], char t[])
{
        int i = 0;
        int j = 0;
 
        while(s[i] != '\0')
        {
                switch(s[i])
                {
                        case '\n': 
                                t[j] = '\\';

                                t[j + 1] = 'n';

                                j += 2;i++;

                                break;

                        case '\t': 
                                t[j] = '\\';

                                t[j + 1] = 't';

                                j += 2;i++;

                                break;

                        default: 
                                t[j] = s[i];

                                i++;j++;

                                break;

                }

        }

        t[j] = '\0';

}

  
void unescape(char s[] , char t[])
{
 
        int i = 0;

        int j = 0;
 
        while(s[i] != '\0')
        {
                switch(s[i])
                {
                        case '\\': 
                                if(s[i + 1] == 'n') 
                                        t[j] = '\n'; 
                                else if(s[i + 1] == 't') 
                                        t[j] = '\t'; 
                                i += 2;
                                j++;
                                break;

                        default:
                                t[j++] = s[i++];
                                break;

                }
         }

        t[j] = '\0';

}
