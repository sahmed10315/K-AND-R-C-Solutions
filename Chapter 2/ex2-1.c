#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	char c;
	char signed sc;
	char unsigned uc;
	
	float ff;
	printf("%lf",FLT_MIN);	
	printf("Char range: %d %d\n", CHAR_MIN, CHAR_MAX);
	printf("Char range signed: %d %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Char range unsigned: %d %d\n\n", 0, UCHAR_MAX);

	printf("Int range: %d %d\n", INT_MIN, INT_MAX);
	printf("Int range unsigned: %d %u\n\n", 0, UINT_MAX);

	printf("Short range: %d %d\n", SHRT_MIN, SHRT_MAX);
	printf("Short unsigned range: %d %d\n\n", 0 , USHRT_MAX);

	printf("Long range: %ld %ld\n", LONG_MIN, LONG_MAX);
	printf("Long unsigned range: %ld %lu\n\n", 0,ULONG_MAX);

	printf("Long long range: %lld %lld\n", LLONG_MIN, LLONG_MAX);
	printf("Long Long range unsigned: %u %llu\n\n", 0, ULLONG_MAX);

	printf("Float range: %e %e\n\n", FLT_MIN, FLT_MAX);
	printf("Double range: %e %e\n\n", DBL_MIN, DBL_MAX);
	printf("Long double range: %e %e\n\n", LDBL_MIN, LDBL_MAX);
}
