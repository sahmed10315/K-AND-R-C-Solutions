#include <stdio.h>

#define swap(t, x, y) {	t te = x; x = y; y = te; }
		
main()
{
	int x = 10;
	int y = 11;

	printf("%d %d\n" , x, y);
	swap(int, x, y);

	printf("%d %d\n" , x, y);
	
}
