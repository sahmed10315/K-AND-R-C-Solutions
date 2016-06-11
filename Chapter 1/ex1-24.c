#include <stdio.h>
 
main()
{
      int c;

       int brackets = 0; int fbraces = 0; int sbraces = 0; int fparanthesis = 0; int sparanthesis = 0; int squotes = 0; int fcomments = 0; int dquotes = 0;

       int sbrackets = 0; int fbrackets = 0; int scomments = 0; int state = 0; int sstate = 0;
 
       while((c = getchar()) != EOF)
       {
               if(c == '(')
                    fbraces++;   
              else if(c == ')')
                     sbraces++;
              else if(c == '{')
                     fparanthesis++;
              else if(c == '}')
                     sparanthesis++;
              else if(c == '[')
                     fbrackets++;
              else if(c == ']')
                     sbrackets++;
              else if (c == '"')
                     dquotes++;
              else if(c == '\'')
                     squotes++;
              else if(c == '/' && sstate == 0)
                     state = 1;
              else if(state == 1 && c == '*')
              {
                     state = 0;
                     fcomments++;
              }
              else if (c == '*')
                     sstate = 1;
              else if (sstate == 1 && c == '/')
              {
                     sstate = 0;
                     scomments++;
              }
 
       }
 
       if(fbraces != sbraces)
              printf("Braces are not well formed.\n");

       if(fparanthesis != sparanthesis)
              printf("Paranthesis are not well formed.\n");

       if(fbrackets != sbrackets) 
              printf("Brakets are not well formed.\n");

       if(dquotes % 2 != 0)
              printf("Double quotes are not well formed.\n");

       if(squotes % 2!= 0)
              printf("Single quotes are not well formed.\n");

       if(fcomments != scomments)
              printf("Comments are not well formed.\n");

  
       return 0;
 
}

 
