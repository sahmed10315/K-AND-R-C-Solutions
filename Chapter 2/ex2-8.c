#include <stdio.h>

unsigned rightrot(unsigned x, int n);

main()
{
	printf("%u %u\n\n", 287, rightrot(287,3));

} 

unsigned rightrot(unsigned x, int n)
{
	int i = 0;
	for(unsigned y = x; y != 0; y = y >> 1, i++);
	return  (x >> n) | ((~(~0 << n) & x) << (i -n)  );
}
