#include "main.h"

/**
 * get_size - Calculates the size to cast the argument.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 *
 * Return: The size to cast the argument.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int argument_size = 0;

	if (format[curr_i] == 'l')
		argument_size = S_LONG;
	else if (format[curr_i] == 'h')
		argument_size = S_SHORT;

	if (argument_size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (argument_size);
}
