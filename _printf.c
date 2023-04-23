#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
			{
				putchar('%');
				len++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				len++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
				{
					printf("(null)");
					len += 6;
				}
				else
				{
					printf("%s", s);
					len += strlen(s);
				}
			}
			else
			{
				putchar('%');
				putchar(*format);
				len += 2;
			}
		}
		else
		{
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
