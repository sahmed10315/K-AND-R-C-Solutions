#include<stdio.h>

int main()
{
	int a,b;
	float c,d;

	a = 15;
	b = a / 2;
	printf("%d\n",b);
	printf("%3d\n",b);
	printf("%03d\n",b);

	c = 15.3;
	d = c / 3;
	printf("%3.2f\n",d);
	
	printf("The color: %s\n", "blue");
	printf("First number: %d\n", 12345);
	printf("Second number: %04d\n", 25);
	printf("Third number: %i\n", 1234);
	printf("Float number: %3.2f\n", 3.14159);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 255);
	printf("Unsigned value: %u\n", 150);
	printf("Just print the percentage sign %%\n", 10);
	
	printf(":%s:\n", "Hello, world!");
	printf(":%25s:\n", "Hello, world!");
	printf(":%.10s:\n", "Hello, world!");
	printf(":%-10s:\n", "Hello, world!");
	printf(":%-15s:\n", "Hello, world!");
	printf(":%.15s:\n", "Hello, world!");
	printf(":%15.10s:\n", "Hello, world!");
	printf(":%-15.10s:\n", "Hello, world!");
	
	return 0;
}