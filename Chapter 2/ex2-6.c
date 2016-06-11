#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
	printf("%u %u\n\n", 287, setbits(287, 4,3, 169));

} 

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~((~(~0 << n) << (p + 1 - n))) | ((~(~0 << n) & (y >> (p + 1 -n))) << (p + 1 -n)));

}
