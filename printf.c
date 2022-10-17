#include <stdlib.h>
#include "main.h"

/**
 * specifiers - check for specifiers
 * @format: format
 * Return: return the funtion if valid or NULL
 */

static int (*specifiers(const char *format))(va_list)
{
	unsigned int n;
	print_t p[] = {
		{"c", print_c}, {"s", print_s}, {NULL, NULL}
	};
	for (n = 0; p[n].t != NULL; n++)
	{
		if (*(p[n].t) == *format)
		{
			break;
		}
	}
	return (p[n].f);
}


/**
 * _printf - print
 * @format: list of argument types int the function
 * Return: number of characters counted and printed
 */


int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
	{
		return (-1);
	}
	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
		{
			return (count);
			f = specifiers(&format[i + 1]);

			if (f != NULL)
			{
				count += f(valist);
				i += 2;
				continue;
			}
			if (!format[i + 1])
				return (-1);
			_putchar(format[i]);
			count++;
			if (format[i + 1] == '%')
				i += 2;
			else
				i++;
		}
		va_end(valist);
		return (count);
	}
