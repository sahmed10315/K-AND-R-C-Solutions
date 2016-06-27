#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; /*points to each unnamed arg in turn */
	char *p, *sval, cval;
	int ival;
	double dval;
	unsigned int uval;
	
	va_start(ap, fmt);
	
	for(p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		
		switch(*++p) {
			case 'i':
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for(sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			case 'c':
				cval = va_arg(ap, char);
				putchar(cval);
				break;
			case 'u':
				uval = va_arg(ap, unsigned int);
				printf("%u", uval);
				break;
			case 'l':
				lval = va_arg(ap, long);
				printf("%ld", lval);
				break;
			case 'o':
				uval = va_arg(ap, unsigned int);
				printf("%o", uval);
				break;
			case 'x':
				uval = va_arg(ap, unsigned int);
				printf("%x", uval);
				break;
			case 'X':
				uval = va_arg(ap, unsigned int);
				printf("%X", uval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}