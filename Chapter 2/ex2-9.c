#include <stdio.h>

int bitcount(unsigned x);

main()
{
	printf("%u %u\n\n", 287, bitcount(287));

} 

int bitcount(unsigned x)
{

	int b;
	for (b = 0; x != 0; x &= (x - 1) , b++);
	return b;
}
