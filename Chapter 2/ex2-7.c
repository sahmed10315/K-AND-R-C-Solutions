#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	printf("%u %u\n\n", 287, invert(287, 4,3));

} 

unsigned invert(unsigned x, int p, int n)
{
	return (x & ~((~(~0 << n) << (p + 1 - n))) | ((~(~0 << n) & (~x >> (p + 1 -n))) << (p + 1 -n)));

}
