#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - prints a variable number of arguments of various types
 * @format: a string representing the types of arguments to print
 *             c: char
 *             i: integer
 *             f: float
 *             s: string
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;

	va_start(args, format);

	char c;
	int i;
	float f;
	char *s;

	while (*format != '\0')
	{
		if (*format == 'c')
		{
			c = (char)va_arg(args, int);
			printf("%c", c);
		}
		else if (*format == 'i')
		{
			i = va_arg(args, int);
			printf("%d", i);
		}
		else if (*format == 'f')
		{
			f = (float)va_arg(args, double);
			printf("%f", f);
		}
		else if (*format == 's')
		{
			s = va_arg(args, char*);
			if (s == NULL)
			{
				printf("(nil)");
			}
			else
			{
				printf("%s", s);
			}
		}
		format++;
	}

	printf("\n");
	va_end(args);
}

