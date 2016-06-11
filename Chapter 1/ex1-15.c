#include <stdio.h>
/* Function for conversion of temperature */

float conversion(float);

main()
{
	float fahr, celsius;
        int lower, upper, step;
	
	lower = 0;      /* lower limit of temperature table */
	upper = 300;    /* upper limit */
	step = 20;      /* stepping size */
	
	fahr = lower;
	
	printf("Fahr   Cels\n");

	while( fahr <= upper){
		printf("%3.0f %6.1f\n", fahr, conversion(fahr));
		fahr = fahr + step;
	}		
}

float conversion(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
