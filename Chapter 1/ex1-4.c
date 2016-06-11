#include <stdio.h>
/* Print Celsius Fahrenheit table */
main()
{
	float fahr, celsius;
        int lower, upper, step;
	
	lower = -20;      /* lower limit of temperature table */
	upper = 150;    /* upper limit */
	step = 10;      /* stepping size */
	
	celsius = lower;
	
	printf("Cels    Fahr\n");

	while( celsius <= upper){
		fahr = (celsius / (5.0 / 9.0) ) + 32.0;
		printf("%3.0f %6.0f\n", celsius, fahr);
		celsius = celsius + step;
	}		
}
