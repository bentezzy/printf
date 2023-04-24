#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */

int size(const char *format, int *j)
{
	int curr_i = *j + 1;
	int Size = 0;

	if (format[curr_i] == 'l')
		Size = S_LONG;
	else if (format[curr_i] == 'h')
		Size = S_SHORT;

	if (size == 0)
		*j = curr_i - 1;
	else
		*j = curr_i;

	return (Size);
}
