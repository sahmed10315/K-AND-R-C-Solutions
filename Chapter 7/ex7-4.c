#include <stdarg.h>

void minscanf(char * fmt, ...)
{
	va_list ap;
	char *p;
	int * ival;
	double * dval;
	char *sval; 
	va_start(ap, fmt);
	
	for(p = fmt; *p; p++)
	{
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
			case 'i':
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double *);
				scanf("%f", dval);
				break;
			case 's':
			   sval = va_arg(ap, char *);
			   scanf("%s", sval);
			   break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}