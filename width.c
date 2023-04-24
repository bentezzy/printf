#include "main.h"

/**
 * width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @j: Index of the current position in the format string
 * @list: list of arguments.
 *
 * Return: width.
 */

int width(const char *format, int *j, va_list list)
{
	int curr_i;
	int Width = 0;

	for (curr_i = *j + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			Width *= 10;
			Width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			Width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = curr_i - 1;

	return (Width);
}
