#include <stdio.h>

int lower(int c);

main()
{
	printf("%c %c\n\n", 'P', lower('P'));

} 
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;

}
